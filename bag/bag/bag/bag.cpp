#include <iostream>
#include <memory>
using namespace std;

#define MaxSize 100

template <class T>
class Bag {
public:
	Bag(int bagCapacity = 10);
	~Bag();
	bool IsFull();
	int Size() const;
	bool IsEmpty() const;
	virtual T Pop();
	virtual void Push(const T&);
	friend ostream& operator <<(ostream& os, Bag<T>& b);
private:
	T* array;
	int capacity;
	int top;
};

template <class T>
ostream& operator<<(ostream& os, Bag<T>& b) {
	for (int i = 0; i < b.top; ++i) cout << b.array[i] << endl;
	return os;
}

template <class T>
Bag<T>::Bag(int bagCapacity) : capacity(bagCapacity) {
	if (capacity < 1) throw "Capacity must be >0";
	array = new T[capacity];
	top = -1;
}
template <class T>
Bag<T>::~Bag() { delete[] array; }

template <class T>
void ChangeSizeID(T*& a, const int oldSize, const int newSize) {
	if (newSize < 0) throw "New length must be >=0";

	T* temp = new T[newSize];
	int number = oldSize;
	if (oldSize > newSize) number = newSize;
	memcpy(temp, a, sizeof(T) * number);
	delete[] a;
	a = temp;
}

template <class T>
int Bag<T>::Size() const {
	return top + 1;
}

template <class T>
bool Bag<T>::IsEmpty() const {
	return top < 0;
}

template <class T>
void Bag<T>::Push(const T& x) {
	if (top == capacity - 1) {
		ChangeSizeID(array, capacity, 2 * capacity);
		capacity *= 2;
	}
	//array[++top] = x;
	int targetPos = (top+1) / 2;
	memcpy(array + targetPos + 1, array + targetPos, sizeof(T) * (top + 1 - targetPos));
	array[targetPos] = x;
	top++;
}

template <class T>
T Bag<T>::Pop() {
	T retValue;
	if (IsEmpty()) throw "Bag is empty, cannot delete";
	int targetPos = top / 2;
	retValue = array[targetPos];
	memcpy(array + targetPos, array + targetPos + 1, sizeof(T) * (top - targetPos));
	top--;
	return retValue;
}

template <class T>

inline bool Bag<T>::IsFull()

{

	if (top == MaxSize - 1) return 1;

	else return 0;

}
int main() {

	Bag<int> b(4);
	Bag<float> fo(10);

	int n;
	float f;

	//Bag<float> fo(10);에 대하여도 구현할 것

	//화면에서 임의 숫자를 입력받아 Push( ) 호출하도록 수정

	b.Push(3);

	b.Push(5);

	b.Push(1);

	b.Push(6);

	b.Push(7);

	fo.Push(1.1);
	fo.Push(1.5);
	fo.Push(2.7);
	fo.Push(3.5);
	fo.Push(8.2);
	fo.Push(9.1);
	fo.Push(10.5);
	fo.Push(1.2);
	fo.Push(8.3);
	fo.Push(2.5);
	fo.Push(5.5);
	

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