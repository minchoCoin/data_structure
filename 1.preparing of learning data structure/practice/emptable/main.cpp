#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
	int num;
	string name;
	double salary;
	string dept;
	static int count;

public:
	Employee();
	Employee(int n);
	Employee(const Employee& e);
	~Employee();
	Employee& operator =(const Employee& e);
	int operator++();
	static int Show() { return count; }
	friend ostream& operator <<(ostream& os, Employee& e);
	friend istream& operator >>(istream& is, Employee& e);
};

class EmpTable {
private:
	int top;
	Employee* data;
public:
	EmpTable(int t) : top(t) { data = new Employee[t]; }
	~EmpTable() { delete[] data; }
	void InitializeEmployee();
	void ShowEmployee();
};

Employee::Employee() : num(0), name("example"), salary(1000000.0), dept("123123123") { count++; }
Employee::Employee(int n) : num(n), name(string("name") + to_string(n)), salary(n * 1000000.0), dept(to_string(n * 100000000.0)) { count++; }
Employee::Employee(const Employee& e) {
	num = e.num;
	name = e.name;
	salary = e.salary;
	dept = e.dept;
}
Employee& Employee:: operator = (const Employee& e) {
	num = e.num;
	name = e.name;
	salary = e.salary;
	dept = e.dept;
	return *this;
}
Employee::~Employee() { count--; }
ostream& operator << (ostream& os, Employee& e) {
	os << "num : " << e.num << " name : " << e.name << " salary : " << e.salary << "dept : " << e.dept;
	return os;
}
istream& operator >>(istream& is, Employee& e) {
	is >> e.num >> e.name >> e.salary >> e.dept;
	return is;
}

void EmpTable::InitializeEmployee() {
	for (int i = 0; i < top; ++i) {
		cin >> data[i];
	}
}
void EmpTable::ShowEmployee() {
	for (int i = 0; i < top; ++i) {
		cout << data[i]<<endl;
	}
}

int Employee::count = 0;

int main(void) {
	int num = 3;
	EmpTable empt(num);
	empt.InitializeEmployee();
	empt.ShowEmployee();
	return 0;
}