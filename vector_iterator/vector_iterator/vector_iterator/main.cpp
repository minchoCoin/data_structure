#include <iostream>

#include <vector>

#include <stdlib.h>

#include <time.h>

using namespace std;





// 구현 실습 대상임

vector<vector<int>> Add(vector<vector<int>>& A, vector<vector<int>>& B);

void  Initialize(vector<vector<int>>& A);

void  Print(vector<vector<int>>& A);

int main()

{
	srand(time(NULL));

	vector<vector<int> > A(5), B(5), C(5);

	Initialize(A);

	Initialize(B);

	C = Add(A, B);


	cout << "vector<vector int>> A" << endl;
	Print(A);
	cout << "vector<vector int>> B" << endl;
	
	Print(B);
	cout << "vector<vector int>> C" << endl;
	
	Print(C);


	return 0;

}

vector<vector<int>> Add(vector<vector<int>>& A, vector<vector<int>>& B) {
	vector<vector<int>> C(5);
	Initialize(C);

	vector<vector<int>>::iterator itA = A.begin();
	vector<vector<int>>::iterator itB = B.begin();
	vector<vector<int>>::iterator itC = C.begin();

	for (; itA != A.end() && itB != B.end() && itC !=C.end(); itA++, itB++,itC++) {
		vector<int>::iterator in_itA = itA->begin();
		vector<int>::iterator in_itB = itB->begin();
		vector<int>::iterator in_itC = itC->begin();

		for (; in_itA != itA->end() && in_itB != itB->end() && in_itC != itC->end(); in_itA++, in_itB++, in_itC++) {
			*in_itC = *in_itA + *in_itB;
		}
	}
	return C;
}

void  Initialize(vector<vector<int>>& A) {
	vector<vector<int>>::iterator it = A.begin();
	for (; it != A.end(); it++) {
		it->resize(15);
		vector<int>::iterator in_itA = it->begin();

		for (; in_itA != it->end(); in_itA++) {
			*in_itA = rand() % 10;
		}

	}
}

void  Print(vector<vector<int>>& A) {
	vector<vector<int>>::iterator it = A.begin();
	for (; it != A.end(); it++) {
		vector<int>::iterator in_itA = it->begin();
		for (; in_itA != it->end(); in_itA++) {
			cout << *in_itA << " ";
		}
		cout << endl;

	}
}



/*
int main() {

	vector<int> vs = { 1,2,3,4,5 };



	vector<int>::iterator it = vs.begin();

	for (it = vs.begin(); it != vs.end(); it++)

		cout << *it << " ";

	cout << endl;

	string a = "have";

	string b = "nice";

	string c = "fish";

	string d = "apple";

	int n = 3;

	vector<vector<string>> table(n);



	table[0].push_back(a); // I add string 'a' to end of first vector in 'arr'

	table[0].push_back(b);

	table[1].push_back(c);

	table[1].push_back(d);

	for (int i = 0; i < table[0].size(); i++) {

		for (int j = 0; j < table[i].size(); j++) // print all string in first vector of 'arr'

			cout << table[i][j] << " ";

		cout << endl;

	}

	/*

	vector <vector<int>> vvi = {{1,2,3},{4,5}, {0,1,0,1},{100,200}};

	vector< vector<int> >::iterator row;

	vector<int>::iterator col;

	for (row = vvi.begin(); row != vvi.end(); row++) {

		for (col = row->begin(); col != row->end(); col++) {

			cout <<*col<<"  ";

		cout<<endl;		}

	}

	*/
/*
system("pause");

return 1;

}

*/



