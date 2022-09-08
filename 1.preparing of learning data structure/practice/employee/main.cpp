#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
	int num;
	string name;
	float salary;
	string dept;
	static int count;
public:
	Employee();
	Employee(int n);
	Employee(const Employee& e);
	~Employee();
	Employee& operator = (const Employee& e);
	int operator++();
	static int Show() {
		int tmp = count;
		count = 0;
		return tmp;
	}
	friend ostream& operator <<(ostream& os, Employee& e);
};
Employee::Employee() : num(1),name("name1"),salary(100.0),dept("300") {

}
Employee::Employee(int n) : num(n),name(string("name") + to_string(n)),salary(float(n*100)),dept(to_string(n*300)) {

}
Employee::Employee(const Employee& e) {
	num = e.num;
	name = e.name;
	salary = e.salary;
	dept = e.dept;
}
Employee::~Employee(){}
int Employee::operator++() {
	num++;
	return num;
}
Employee& Employee::operator=(const Employee& e) {
	num = e.num;
	name = e.name;
	salary = e.salary;
	dept = e.dept;
	return *this;
}
ostream& operator <<(ostream& os, Employee& e) {
	os << "num : " << e.num << " name : " << e.name << " salary : " << e.salary << " dept : " << e.dept;
	return os;
}
int Employee::count = 0;

int main(void) {
	Employee sd1;
	Employee sd2(10);
	Employee sd3(sd2);
	Employee::Show();
	sd1.Show();
	Employee sd4 = sd2;
	sd3 = sd2;
	cout << endl;
	cout << sd4 << endl;
	return 0;
}