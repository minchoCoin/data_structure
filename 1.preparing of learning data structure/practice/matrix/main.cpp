#include <iostream>
#include <time.h>
#include "Matrix.h"

using namespace std;

int main(void) {
	Matrix mA(3, 4);
	Matrix tmp(3, 4);
	Matrix mB(4, 5);
	Matrix mC(3, 5);
	srand(time(NULL));

	cout << "mA : " << endl;
	mA.get_data();
	mA.show_data();

	cout << "mA(sorted) : " << endl;
	mA.sort_data();
	mA.show_data();

	cout << "mB : " << endl;
	mB.get_data();
	mB.show_data();

	cout << "tmp : " << endl;
	tmp.get_data();
	tmp.show_data();

	cout << "tmp + mA : " << endl;
	tmp.addMatrix(mA);
	tmp.show_data();

	cout << "mA * mB : " << endl;
	mC.MultiplyMatrix(mA, mB);
	mC.show_data();
	


}