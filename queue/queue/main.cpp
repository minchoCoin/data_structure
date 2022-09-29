//소스코드3.3: Queue 자료구조
#include <iostream>
#include <memory>

using namespace std;

template <class T>
class Queue
{
public:
	Queue(int queueCapacity = 10);
	bool IsEmpty();
	T& Front();
	T& Rear();
	void Push(T const& x);
	void Pop();
	int Capacity() { return capacity; }
	int Count() { return count; }
	friend ostream& operator<<<T>(ostream& os, Queue<T>&);
	friend istream& operator>><T>(istream& os, Queue<T>&);
private:
	T* queue;
	int front;
	int rear;
	int capacity;
	int count;
};
template <class T>
ostream& operator<<(ostream& os, Queue<T>& s) {
	if (s.IsEmpty()) {
		os << "queue is empty!!";
		return os;
	}
	int j = s.front + 1;
	for (int i = 0; i < s.count; ++i) {
		os << s.queue[j] << " ";
		j = (j + 1) % s.capacity;
	}
	return os;
}
template <class T>
istream& operator>>(istream& os, Queue<T>& s) {
	
	T tmp;
	cin >> tmp;
	s.Push(tmp);
	return os;
}
template <class T>
Queue<T>::Queue(int queueCapacity) : capacity(queueCapacity)
{
	queue = new T[capacity];
	front = rear = -1;
	count = 0;
}

template <class T>
inline bool  Queue<T>::IsEmpty() { return front == rear; }

template <class T>
inline T& Queue<T>::Front()
{
	if (IsEmpty()) throw "Queue is empty. No front element";
	return queue[(front + 1) % capacity];
}

template <class T>
inline T& Queue<T>::Rear()
{
	if (IsEmpty()) throw "Queue is empty. No rear element";
	return queue[rear];
}

// doubling queue capacity
template <class T>
void Queue<T>::Push(T const& x)
{
	if (count == capacity) {
		cout << "capacity of queue is doubling!" << endl;
		int original_count = count;
		T* buf = new T[original_count];

		for (int i = 0; i < original_count; ++i) {
			buf[i] = Front();
			Pop();
		}
		T* newqueue = new T[capacity * 2];
		capacity *= 2;
		memcpy(newqueue, buf, sizeof(T)*original_count);
		delete[] queue;
		delete[] buf;
		queue = newqueue;

		front = -1;
		count = original_count;
		rear = original_count - 1;

	}
	
	rear = (rear + 1) % capacity;
	queue[rear] = x;
	count++;
	//cout << capacity << " " << front << " " << rear << " " << x << endl; //for debugging
}

template <class T>
void Queue<T>::Pop()
{
	if (IsEmpty()) throw "Queue is empty. Cannot delelte.";
	front = (front + 1) % capacity;
	queue[front].~T();
	count--;
}

int main()
{
	Queue<int> s(3);
	s.Push(2);
	s.Push(1);
	s.Push(4);
	s.Push(10); //구현시에 doubling 동작 가능한지 테스트
	s.Push(11);
	s.Push(12);
	s.Push(13);
	s.Push(14);
	s.Push(15);
	cout << "input one element of queue : cin >> s "<<endl;
	cin >> s; //구현 실습
	if (s.IsEmpty()) {
		cout << "empty" << endl;
	}
	else {
		cout << "not empty" << endl;
	}

	while (!s.IsEmpty()) {
		cout << s.Front() << endl;
		s.Pop();
	}
	
	cout << "output queue : cout << s << endl;" << endl;
	cout << s << endl;//가능하도록 필요한 함수를 추가 구현한다
	system("pause");
}
