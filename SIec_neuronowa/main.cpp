#include <iostream>
#include <vector>
#include <windows.h>
#include <math.h>
#include "NN.h"

using namespace std;

class Neuron;
struct TrainingData {
	vector<double> in;
	vector<double> target;
};



int main() {
	vector<int> toppo;
	toppo = { 2,2,1 };
	NN net(toppo);
	TrainingData t[4];
	
	t[0].in.push_back(0.0);
	t[0].in.push_back(0.0);
	t[0].target.push_back(0.0);

	t[1].in.push_back(1.0);
	t[1].in.push_back(1.0);
	t[1].target.push_back(0.0);

	t[2].in.push_back(1.0);
	t[2].in.push_back(0.0);
	t[2].target.push_back(1.0);

	t[3].in.push_back(0.0);
	t[3].in.push_back(1.0);
	t[3].target.push_back(1.0);

	vector<double> example;
	example = net.feedForward(t[1].in);
	cout << example[0];
	net.backPropagation({ 2,3 }, {1});
	int a;
	cin >> a;
	return 0;
}