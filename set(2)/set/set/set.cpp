#include <iostream>

#include <memory>

#include <stdlib.h>

#include <time.h>

using namespace std;

#define MaxSize 100



template <class T>

class Set {

public:

	Set(int bagCapacity = 10);

	~Set();

	bool IsFull();

	int Size() const; //HowMany( )에 해당됨

	bool IsEmpty() const;

	virtual T Pop();

	virtual void Push(const T&);

	friend ostream& operator <<<T>(ostream& os, Set<T>& b);

private:

	T* array;

	int capacity;

	int top;

};

template <class T>
ostream& operator <<(ostream& os, Set<T>& b) {
	for (int i = 0; i < b.Size(); ++i) {
		cout << b.array[i] << " ";
	}
	return os;
}


//Visual Studio2019에서 bag.h, bag.cpp로 분리하지 않아야 함

template <class T>

Set<T>::Set(int bagCapacity) : capacity(bagCapacity)

{

	if (capacity < 1) throw "Capacity must be > 0";

	array = new T[capacity];

	top = -1;

}



template <class T>

Set<T>::~Set() { delete[] array; }



template <class T>

void ChangeSizeID(T*& a, const int oldSize, const int newSize)

{

	if (newSize < 0) throw "New length must be >= 0";

	T* temp = new T[newSize];

	int number = oldSize;

	if (oldSize > newSize) number = newSize;

	//copy(a, a + number, temp);

	memcpy(temp, a, sizeof(T) * number);

	delete[] a;

	a = temp;



}

template <class T>

int Set<T>::Size() const {

	return top + 1;

}



template <class T>

bool Set<T>::IsEmpty() const {

	return top < 0;

}



template <class T>

void Set<T>::Push(const T& x)

{
	int i;
	for (i = 0; i < Size(); ++i) {
		if (array[i] == x) break;
	}
	if (i >= Size()) { // no duplicate
		if (top == capacity - 1)

			// 현재 버젼은 ordering 상태에서 push한다. non-ordering되게 push가 가능하게 수정

		{

			ChangeSizeID(array, capacity, 2 * capacity);

			capacity *= 2;

		}

		int targetPos = (top + 1) / 2;
		memcpy(array + targetPos + 1, array + targetPos, sizeof(T) * (top + 1 - targetPos));
		array[targetPos] = x;
		top++;
	}

}



template <class T>

T Set<T>::Pop()

{

	T retValue;

	if (IsEmpty()) throw "Bag is empty, cannot delete";

	int deletePos = top / 2;

	retValue = array[deletePos];

	// 실습 사항: no ordering상태로 pop되게 수정

	//copy(array + deletePos + 1, array + top + 1, array + deletePos);

	memcpy(array + deletePos, array + deletePos + 1, sizeof(T) * (top - deletePos));

	top--;

	return retValue;

}



template <class T>

inline bool Set<T>::IsFull()

{

	if (top == MaxSize - 1) return 1;

	else return 0;

}



int main() {

	srand(time(NULL));
	Set<int> b(4);
	Set<float> fo(10);

	int n;
	float f;

	//Set<float> fo(10);에 대하여도 구현할 것

	//화면에서 임의 숫자를 입력받아 Push( ) 호출하도록 수정

	b.Push(3);

	b.Push(5);

	b.Push(1);

	b.Push(6);

	b.Push(7);

	cout << b << endl;

	if (b.IsEmpty()) {

		cout << "empty" << endl;

	}

	else {

		cout << "not empty" << endl;

	}

	while (!b.IsEmpty()) {

		n = b.Pop();

		cout << "b.Pop() = " << n << endl;

	}

	fo.Push(3.5);

	fo.Push(5.2);

	fo.Push(1.3);

	fo.Push(6.5);

	fo.Push(7.2);

	fo.Push(12.7);
	fo.Push(14.3);
	fo.Push(15.2);
	fo.Push(12.2);
	fo.Push(1.1);

	cout << fo << endl;

	if (fo.IsEmpty()) {

		cout << "empty" << endl;

	}

	else {

		cout << "not empty" << endl;

	}

	while (!fo.IsEmpty()) {

		f = fo.Pop();

		cout << "fo.Pop() = " << f << endl;

	}

	system("pause");

	return 0;

}