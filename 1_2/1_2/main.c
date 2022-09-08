#include <stdio.h>

#include <stdlib.h>

#include "time.h"

#define AROWS 3

#define ACOLS 4

#define BROWS 4

#define BCOLS 5

#define CROWS 3

#define CCOLS 5

/*

행렬이 여러 개일 때 하나의 function으로 처리하는 방법을 고안

*/



int get_dataA(int(*p)[ACOLS], int n)

{



	for (int i = 0; i < n; i++)

		for (int j = 0; j < ACOLS; j++)

			p[i][j] = rand();

	return 1;

}
int get_dataB(int(*p)[BCOLS], int n)

{



	for (int i = 0; i < n; i++)

		for (int j = 0; j < BCOLS; j++)

			p[i][j] = rand();

	return 1;

}
int get_dataC(int(*p)[CCOLS], int n)

{



	for (int i = 0; i < n; i++)

		for (int j = 0; j < CCOLS; j++)

			p[i][j] = rand();

	return 1;

}



void show_dataA(int(*p)[ACOLS], int n)

{

	for (int i = 0; i < n; i++)

	{

		for (int j = 0; j < ACOLS; j++)

			printf("%d ", p[i][j]);

		printf("\n");

	}

}
void show_dataB(int(*p)[BCOLS], int n)

{

	for (int i = 0; i < n; i++)

	{

		for (int j = 0; j < BCOLS; j++)

			printf("%d ", p[i][j]);

		printf("\n");

	}

}
void show_dataC(int(*p)[CCOLS], int n)

{

	for (int i = 0; i < n; i++)

	{

		for (int j = 0; j < CCOLS; j++)

			printf("%d ", p[i][j]);

		printf("\n");

	}

}


/*
void multiply(int matrixA[][ACOLS], int ar, int matrixB[][BCOLS], int br, int matrixC[][CCOLS], int cr) {



}
*/




int main(void)

{

	int matrixA[AROWS][ACOLS];

	int matrixB[BROWS][BCOLS];

	int matrixC[CROWS][CCOLS];



	srand(time(NULL));

	get_dataA(matrixA, AROWS);

	show_dataA(matrixA, AROWS);
	printf("\n");

	get_dataB(matrixB, BROWS);
	

	show_dataB(matrixB, BROWS);
	printf("\n");


	//multiply(matrixA, AROWS, matrixB, BROWS, matrixC, CROWS);
	get_dataC(matrixC, CROWS);
	show_dataC(matrixC, AROWS);

	system("pause");

	return 0;

}