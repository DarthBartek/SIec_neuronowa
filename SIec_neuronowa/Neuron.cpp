#include "Neuron.h"
void Neuron::setDerivative(double div)
{
	derivative = div;
}
Neuron::Neuron(int numOfOutputs, bool biasNeuron) {
	for (int i = 0; i < numOfOutputs; i++) {
		outputWeights.push_back(Connections());
		outputWeights[i].value = (double)(rand() % 100 - 50);//rand() / (double)RAND_MAX;
		bias = biasNeuron;
		outputVal = 0.0;
		if (bias) {
			outputVal = 1;
		}
	}
}

void Neuron::setOutputVal(double x)
{
	outputVal = x;
}
void Neuron::setWeight(int index, double x)
{
	if (index > outputWeights.size() - 1)
		int p = 0;//printErr("Podany indeks jest wiekszy niz rozmiar tablicy");
	else
		outputWeights[index].value = x;
}
double Neuron::getWeight(int index)
{
	if (index >= outputWeights.size()) {
		//printErr("Podany indeks jest wiekszy niz rozmiar tablicy");
		return 0;
	}
	else
		return outputWeights[index].value;
}
double Neuron::getDerivative()
{
	return derivative;
}
double Neuron::getOutput(void)
{
	return outputVal;
}
void Neuron::setError(double e)
{
	error = e;
}
double Neuron::getError()
{
	return error;
}
int Neuron::getNumOfWeights()
{
	return outputWeights.size();
}