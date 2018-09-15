#pragma once
#include <vector>
#include <iostream>

using namespace std;
class Matrix;
typedef vector<double> Rows;
Matrix Transpose(Matrix m);
Matrix MultiplyMatrix(Matrix m1, Matrix m2);
Matrix VectorArrayToMatrix(vector<double> vals);
Matrix ArrayToMatrix(double arr[], int size);
Matrix add(Matrix &m1, Matrix &m2);
Matrix MultiplyByScalar(Matrix m1, double x);
Matrix substract(Matrix m1, Matrix m2);
vector<double> MatrixToVectorArray(Matrix m);
Matrix copy(Matrix m);
class Matrix
{
private:
	int m, n;
public:
	vector<Rows> value;
	
	Matrix(int cols, int rows);
	void setMatrix(double x);
	void setMatrixElement(int cols, int rows, double _value);
	int getRows();
	int getCols();
	void showMatrix();
	void MultiplyByScalar(double x);
	~Matrix();
};
