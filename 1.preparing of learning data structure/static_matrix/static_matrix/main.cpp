#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Matrix.h"
using namespace std;

int Matrix::free = 0;
int* Matrix::data = new int[100];

int main(void) {
	Matrix mA(AROWS,ACOLS);
	Matrix mA1(AROWS, ACOLS);
	Matrix mB(BROWS, BCOLS);
	Matrix mC(CROWS, CCOLS);
	srand(time(NULL));

	cout << "mA : " << endl;
	mA.get_data();
	mA.show_data();

	cout << "mA1(sorted) : " << endl;
	mA1.get_data();
	mA1.sort_data();
	mA1.show_data();


	cout << "mA1 + mA : " << endl;
	mA1.addMatrix(mA);
	mA1.show_data();

	cout << "mB : " << endl;
	mB.get_data();
	mB.show_data();


	cout << "mA * mB : " << endl;
	mC.MultiplyMatrix(mA, mB);
	mC.show_data();
	return 0;
}