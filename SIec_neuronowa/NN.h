#pragma once
#include <iostream>
#include <windows.h>
#include <vector>
#include "Matrix.h"

using namespace std;



class NN
{
private:
	vector<Matrix> weights;
	vector<Matrix> layers;
	vector<Matrix> errors;

public:

	NN(vector<int> topology);
	vector<double> feedForward(vector<double> _inputs);
	void backPropagation(vector<double> _inputs, vector<double> targets);
	~NN();
};

