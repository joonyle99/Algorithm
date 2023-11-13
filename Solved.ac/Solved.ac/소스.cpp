#include <iostream>
#include <vector>

using namespace std;

class Student
{
public:
	string name;
	int age;

public:
	Student()
	{
		std::cout << "인자 없는 기본 생성자" << std::endl;
	}
	Student(string n, int a)
	{
		std::cout << "인자 있는 기본 생성자" << std::endl;
	}
	Student(const Student& s)
	{
		std::cout << "복사 생성자" << std::endl;
	}
	Student(const Student&& s)
	{
		std::cout << "이동 생성자" << std::endl;
	}
	~Student()
	{
		std::cout << "소멸자" << std::endl;
	}
};

void MyFunc()
{
	std::vector<Student> myVector;
	myVector.reserve(2);

	myVector.push_back(Student("페이커", 27));

	cout << "======================================================" << endl;

	myVector.emplace_back("데프트", 27);

	cout << "======================================================" << endl;
}

int main()
{
	MyFunc();

	cout << "==================== End MyFunc() ====================" << endl;

	return 0;
}
