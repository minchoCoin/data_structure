#pragma once
#include <iostream>
#include <stdlib.h>
#define AROWS 3
#define ACOLS 4
#define BROWS 4
#define BCOLS 5
#define CROWS 3
#define CCOLS 5
#define TERMS 5
#define MaxExp 10

class Matrix {
private:
	int rows, cols;
	static int* data;
	static int free;
	int start;
	int finish;
public:
	Matrix(int r, int c);
	~Matrix();
	int get_data();
	int show_data();
	int sort_data();
	int addMatrix(Matrix& m);
	int MultiplyMatrix(Matrix& m1, Matrix& m2);
};

Matrix::Matrix(int r, int c) : rows(r), cols(c), start(free), finish(start + rows * cols) { free += rows * cols; }
Matrix::~Matrix() { free -= rows * cols; }
int Matrix::get_data() {
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			data[start + i * cols + j] = rand() % 100;
		}
	}
	return 0;
}
int Matrix::sort_data() {
	for (int i = 0; i < start+rows*cols-1; ++i) {
		for (int j = 0; j < start + rows * cols -1 - i; ++j) {
			if (data[j] > data[j + 1]) {
				int tmp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = tmp;
			}
		}
	}
	return 0;
}
int Matrix::show_data() {
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			std::cout << data[start + i * cols + j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	return 0;
}
int Matrix::addMatrix(Matrix& m) {
	if (rows == m.rows && cols == m.cols) {
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < cols; ++j) {
				data[start + i * cols + j] += m.data[m.start + i * m.cols + j];
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
				data[start + i * cols + j] = 0;
				for (int k = 0; k < m1.cols; ++k) {
					data[start + i * cols + j] += m1.data[m1.start + i * m1.cols + k] * m2.data[m2.start + k * m2.cols + j];
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