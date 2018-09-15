#pragma once
#include <iostream>
#include <vector>

using namespace std;
struct Connections {
	double value;
	double deltavalue;

};
class Neuron {
private:
	double outputVal;

	double derivative;
	vector<Connections> outputWeights;
public:
	double error;
	bool bias;
	void setDerivative(double div);
	Neuron(int numOfOutputs, bool biasNeuron);
	void setOutputVal(double x);
	void setWeight(int index, double x);
	double getWeight(int index);
	double getDerivative();
	double getOutput(void);
	void setError(double e);
	double getError();
	int getNumOfWeights();
};
