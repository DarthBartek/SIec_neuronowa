#include "NN.h"
void randomMatrix(double xmin, double xmax, Matrix &mat) {
	double randomNum;
	for (int i = 0; i < mat.getRows(); i++) {
		for (int j = 0; j < mat.getCols(); j++) {
			randomNum = ((double)rand() / (RAND_MAX + 1.0) - 0.5);
			
			mat.value[i][j] = randomNum;
		}
	}
}
double activationF(double x, int function) {
	if(function==1)
	x = 1 / (1 + exp(-x));
	
	return x;
}

NN::NN(vector<int> topology)
{
	//initiating layers
	for (int i = 0; i < topology.size(); i++) {
			layers.push_back(Matrix(topology[i]+1, 1));
	}
	//initiating weights
	for (int i = 0; i < topology.size()-1; i++) {
			weights.push_back(Matrix(layers[i+1].getRows()-1 , layers[i].getRows()));
	}
	//randomizing weights values
	for (int i = 0; i < layers.size() - 1; i++) {
		randomMatrix(-5.0,5.0,weights[i]);
	}
}

vector<double> NN::feedForward(vector<double> _inputs)
{
	Matrix inputs = VectorArrayToMatrix(_inputs);
	for (int i = 0; i < layers[0].getRows() - 1; i++) {
		layers[0].value[i][0] = inputs.value[i][0];
		
	}
	layers[0].value[layers[0].getRows() - 1][0] = 1.0;

	cout << "\n ff\n";
	
	for (int lCount = 0; lCount < layers.size()-1; lCount++) {
		cout << "\n w: "<< lCount<<"\n";
		weights[lCount].showMatrix();
		cout << "\n l: " << lCount << "\n";
		layers[lCount].showMatrix();
		Matrix Z = MultiplyMatrix( weights[lCount],layers[lCount]);
		cout << "\n z: ";;
		Z.showMatrix();
		for (int i = 0; i < Z.getRows()-1; i++) {
			Z.value[i][0] = activationF(Z.value[i][0], 1);
		}
		layers[lCount].value[layers[lCount].getRows() - 1][0] = 1.0;
		layers[lCount] = add(layers[lCount], Z);
	}
	vector<double>output;

	output = MatrixToVectorArray(layers.back());
	
	return output;
}

void NN::backPropagation(vector<double> _inputs, vector<double> target)
{
	vector<double>output = feedForward(_inputs);
	Matrix outputs = VectorArrayToMatrix(output);
	Matrix targets = VectorArrayToMatrix(target);
	//////////// ERROR
	for (int i = layers.size() - 1; i >0; i--) {
		errors.push_back(Matrix(layers[i].getRows(),1));
	}
	//cout << "\n er: " << errors.back().getRows() << " t: " << targets.getRows() << " o: " << targets.getRows()<<" l: "<< layers.back().getRows();

	for (int i = 0; i < layers.back().getRows() - 1; i++) {
		errors.back().value[i][0] = targets.value[i][0] - outputs.value[i][0];
	}

	for (int i = errors.size() - 1; i >= 0; i--) {
		Matrix TransposedWeights = Transpose(weights[i]);
		cout << "\n bp";
		errors[i] = MultiplyMatrix(TransposedWeights,errors[i]);
		errors[i].showMatrix();
	}
}

NN::~NN()
{
}
