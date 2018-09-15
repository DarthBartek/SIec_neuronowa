#pragma once
#include <iostream>
#include <vector>
#include <windows.h>
#include <math.h>
#include "Neuron.h"

using namespace std;

typedef vector<Neuron> Layer;
class Net {
private:
	int numOfLayers;

	double learning_rate;


public:vector<Layer> m_layer;
	   Net(vector<int> &topology);
	   void feedForward(vector<double> &inputValues);
	   void backPropagate(vector<double> &outputValues, vector<double> &targetValues);
	   vector<double> getResult() {
		   vector<double> result;
		   for (int i = 0; i < m_layer.back().size(); i++) {
			   result.push_back(m_layer.back()[i].getOutput());
		   }
		   return result;
	   }
};
