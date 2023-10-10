#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

class Person
{
public:
	std::string name;
	int age;

	// virtual void Func();
};

class Student : public Person
{
public:
	int sNumber;

	// void Func() override;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	Person p;
	Student s;

	p.name;
	p.age;

	s.name;
	s.age;
	s.sNumber;

	return 0;
}