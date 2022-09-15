#pragma once
#include <iostream>
#include <stdlib.h>
//#include <time.h>
//a[2][3] ->a[2*rows + 3]
class Matrix {
private:
	int rows, cols;
	int* data;
public:
	Matrix(int r, int c);
	~Matrix();
	int get_data();
	int show_data();
	int sort_data();
	int addMatrix(Matrix& m);
	int MultiplyMatrix(Matrix& m1, Matrix& m2);
};

Matrix::Matrix(int r, int c) : rows(r), cols(c) { data = new int[rows * cols]; }
Matrix::~Matrix() { delete[] data; }
int Matrix::get_data() {
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			data[i * cols + j] = rand()%100;
		}
	}
	return 0;
}
int Matrix::show_data() {
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			std::cout<< data[i * cols + j]<<" ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	return 0;
}
int Matrix::sort_data() {
	for (int i = 0; i < rows * cols; ++i) {
		for (int j = 1; j < rows * cols - i; ++j) {
			if (data[j - 1] > data[j]) {
				int tmp = data[j - 1];
				data[j - 1] = data[j];
				data[j] = tmp;
			}
		}
	}
	return 0;
}
int Matrix::addMatrix(Matrix& m) {
	if (rows == m.rows && cols == m.cols) {
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < cols; ++j) {
				data[i * cols + j] += m.data[i * cols + j];
			}
		}
		return 0;
	}
	else {
		std::cout << "add is impossible!" << std::endl;
	}
	return 1;
}
int Matrix::MultiplyMatrix(Matrix& m1, Matrix& m2) {
	if (m1.cols == m2.rows && m1.rows == this->rows && m2.cols == this->cols) {
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < cols; ++j) {
				data[i * cols + j] = 0;
				for (int k = 0; k < m1.cols; ++k) {
					data[i * cols + j] += m1.data[i * m1.cols + k] * m2.data[k * m2.cols + j];
				}
				
			}
		}
		return 0;
	}
	else {
		std::cout << "multiply is impossible!" << std::endl;
	}
	return 1;
}