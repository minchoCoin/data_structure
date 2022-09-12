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

	mA.get_data();
	mA.show_data();

	mB.get_data();
	mB.show_data();

	tmp.get_data();
	tmp.show_data();

	tmp.addMatrix(mA);
	tmp.show_data();

	mC.MultiplyMatrix(mA, mB);
	mC.show_data();
	


}