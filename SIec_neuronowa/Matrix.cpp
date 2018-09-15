#include "Matrix.h"



Matrix::Matrix(int rows, int cols)
{
	m = rows;
	n = cols;
		for (int r = 0; r < rows;r++) {
			value.push_back(Rows());
			for (int c = 0; c < cols; c++) {
				value[r].push_back(0);
			}
		}
}

void Matrix::setMatrix(double x)
{
	for (int r = 0; r < m; r++) {
		value.push_back(Rows());
		for (int c = 0; c < n; c++) {
			value[r][c] = x;
		}
	}
}

void Matrix::setMatrixElement(int rows, int cols, double _value)
{
	value[rows][cols] = _value;
}

int Matrix::getRows()
{
	return m;
}

int Matrix::getCols()
{
	return n;
}

void Matrix::showMatrix()
{
	for (int i = 0; i < m; i++) {
		cout << "\n";
		for (int j = 0; j < n; j++) {
			cout << value[i][j] << " ";
		}
	}
}

void Matrix::MultiplyByScalar(double x)
{
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			value[i][j] *= x;
		}
	}
}

Matrix::~Matrix()
{
}
Matrix Transpose(Matrix m) {
	Matrix buff(m.getCols(), m.getRows());
	for (int i = 0; i < buff.getRows(); i++) {
		for (int j = 0; j < buff.getCols(); j++) {
			buff.setMatrixElement(i, j, m.value[j][i]);
		}
	}
	return buff;
}

Matrix MultiplyMatrix(Matrix m1, Matrix m2)
{
	if (m1.getCols() == m2.getRows()) {
		int n, m, p, i, j;
		n = m1.getRows();
		m = m1.getCols();
		p = m2.getCols();
		Matrix buff(n, p);
		for (int i = 0; i < buff.getRows(); i++) {
			for (int j = 0; j < buff.getCols(); j++) {
				double x = 0;
				for (int r = 0; r < m; r++) {
					x += m1.value[i][r] * m2.value[r][j];
				}
				buff.setMatrixElement(i, j, x);
			}
		}
		return buff;
	}
	else {
		cout << "\n BLAAAD\n";
		int n, m, p, i, j;
		n = m1.getRows();
		m = m1.getCols();
		p = m2.getRows();
		cout << "n: " << n << " m: " << m << " p: " << p << endl;
		return m1;
	}
}

Matrix VectorArrayToMatrix(vector<double> arr)
{
	Matrix buff(arr.size(), 1);
	for (int i = 0; i < arr.size(); i++)
		buff.value[i][0] = arr[i];
	return buff;
}

Matrix ArrayToMatrix(double arr[], int size)
{
	Matrix buff(size, 1);
	for (int i = 0; i < size; i++)
		buff.value[i][0] = arr[i];
		return buff;
}


Matrix add(Matrix &m1, Matrix &m2)
{
	Matrix buff(m1.getRows(), m2.getCols());
	if ((m1.getRows() == m2.getRows()) && (m1.getCols() == m2.getCols())) {
		for (int i = 0; i < buff.getRows(); i++) {
			for (int j = 0; j < buff.getCols(); j++) {
				buff.value[i][j] = m1.value[i][j] + m2.value[i][j];
			}
		}
	}
	else {
		int x1 = m1.getRows();
		int x2 = m2.getRows();

		Matrix buff(1, 1);
		Matrix buff1(1, 1);
		if (x1 >= x2) {
			buff = m1;
			buff1 = m2;
		}
		else {
			buff = m2;
			buff1 = m1;
		}
		for (int i = 0; i < buff1.getRows(); i++) {
			for (int j = 0; j < buff.getCols(); j++) {
				buff.value[i][j] = m1.value[i][j] + m2.value[i][j];
			}
		}
	}
	return buff;
}

Matrix MultiplyByScalar(Matrix m1, double x)
{
	for (int i = 0; i < m1.getRows();i++) {
		for (int j = 0; j < m1.getCols();j++) {
			m1.value[i][j] *= x;
		}
	}
	return m1;
}
Matrix substract(Matrix m1, Matrix m2)
{
	if ((m1.getRows() == m2.getRows()) && (m1.getCols() == m2.getCols())) {
		Matrix buff(m1.getRows(), m2.getCols());
		for (int i = 0; i < buff.getRows(); i++) {
			for (int j = 0; j < buff.getCols(); j++) {
				buff.value[i][j] = m1.value[i][j] - m2.value[i][j];
			}
		}
		return buff;
	}
	else return Matrix(1, 1);
}

vector<double> MatrixToVectorArray(Matrix m)
{
	vector<double> buff;
	if (m.getCols() == 1) {
		
		for (int i = 0; i < m.getRows(); i++) {
			buff.push_back(m.value[i][0]);
		}
	}
	return buff;
}

Matrix copy(Matrix m)
{
	Matrix buff(m.getRows(), m.getCols());
	for (int i = 0; i < m.getRows(); i++) {
		for (int j = 0; j < m.getCols(); j++) {
			buff.value[i][j] = m.value[i][j]; ;
		}
	}
	return buff;
}

