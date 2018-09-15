#include "Net.h"

Net::Net(vector<int> &topology) {
	numOfLayers = topology.size();
	for (int layerNum = 0; layerNum < numOfLayers; layerNum++) {
		m_layer.push_back(Layer());
		int numOutputs = layerNum == topology.size() - 1 ? 0 : topology[layerNum + 1];
		for (int j = 0; j <= topology[layerNum]; j++) {
			if (j == topology[layerNum])
				m_layer.back().push_back(Neuron(numOutputs, true));
			else
				m_layer.back().push_back(Neuron(numOutputs, false));
			//cout << "Neuron nr: " << j << " w warstwie: " << layerNum << " zostal zrobiony\n";
		}
	}
	learning_rate = 0.01;
}
// otoz teraz licze blad dla kazdego neurona
//nastepnie adjustuje wagi które wychodza lub wchodza z neurona
//a potem dodaje te delty smieszne
void Net::feedForward(vector<double>& inputValues)
{
	// USTAWIANIE PIERWSZEJ WARSTWY (WEJSCIOWA)
	for (int i = 0; i<inputValues.size(); i++) {
		m_layer[0][i].setOutputVal(inputValues[i]);
	}
	double buff = 0;
	//LICZENIE WARSTW KOLEJNYCH
	for (int layerNum = 1; layerNum < m_layer.size(); layerNum++) {
		for (int neuronNum = 0; neuronNum < m_layer[layerNum].size() - 1; neuronNum++) {
			buff = 0;
			for (int i = 0; i<m_layer[layerNum - 1].size(); i++) {

				buff += m_layer[layerNum - 1][i].getOutput()*m_layer[layerNum - 1][i].getWeight(neuronNum);
			}
			cout << "\n waga warstwa " << layerNum - 1 << " neuron: " << neuronNum << " :  " << m_layer[layerNum - 1][neuronNum].getWeight(neuronNum);

			buff = 1 / (1 + exp(-buff));
			cout << "\n wyjscie: " << buff;
			m_layer[layerNum][neuronNum].setOutputVal(buff);
			buff = buff * (1 - buff);
			cout << "\n pochodna: " << buff;
			m_layer[layerNum][neuronNum].setDerivative(buff);
		}
	}
}
void Net::backPropagate(vector<double> &outputValues, vector<double> &targetValues) {
	//setting errors
	for (int i = 0; i < m_layer.back().size() - 1; i++) {
		m_layer.back()[i].error = targetValues[i] - outputValues[i];
	}
	for (int lCount = m_layer.size() - 2; lCount >0; lCount--) {
		for (int nCount = 0; nCount<m_layer[lCount].size(); nCount++) {
			//double weightSum=0;
			//Liczenie sum wag
			for (int i = 0; i < m_layer[lCount + 1].size(); i++) {
				double weightSum = 0;
				for (int j = 0; j<m_layer[lCount].size(); j++) {
					weightSum += m_layer[lCount][j].getWeight(i);

				}
				for (int j = 0; j < m_layer[lCount].size(); j++) {
					if (weightSum != 0)
						//	cout << "\n noo: " << (m_layer[lCount][j].getWeight(i) / weightSum)*m_layer[lCount][i].getError();
						m_layer[lCount][j].error += (m_layer[lCount][j].getWeight(i) / weightSum)*m_layer[lCount][i].error;
				}
				cout << "\n error warstwa" << lCount << " neuron: " << nCount << ": " << m_layer[lCount][nCount].error;
			}
		}
	}
	//Najgorsze - wlasciwa wsteczna propagacja
	for (int lCount = 0; lCount <m_layer.size() - 1; lCount++) {
		for (int nCount = 0; nCount < m_layer[lCount].size(); nCount++) {

			for (int wCount = 0; wCount<m_layer[lCount][nCount].getNumOfWeights(); wCount++) {
				double dWeight = 0;
				dWeight = m_layer[lCount][nCount].getWeight(wCount)*
					m_layer[lCount + 1][wCount].error*learning_rate*m_layer[lCount + 1][wCount].getDerivative();
				m_layer[lCount][nCount].setWeight(wCount, m_layer[lCount][nCount].getWeight(wCount) + dWeight);
			}

		}
	}

}
