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

	Student() = default;
	Student(int n)
		: sNumber(n)
	{}
	~Student() = default;
};

// function template
template <typename T>
T Func2(T param)
{
	return param;
}

// class template
template <class T>
class Stack2
{
public:
	std::vector<T> vec;

public:
	void Func(std::vector<T> paramVec)
	{
		for(T v : paramVec)
		{
			std::cout << v << '\n';
		}
	}
};

/// <summary>
/// RAII Smart Pointer
/// </summary>
class MyString
{
public:
	char* c = nullptr;

private:
	int size = 0;

public:
	MyString(int size) { c = new char[size]; }
	~MyString() { delete[] c; }
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// class inheritance test
	Person p;
	Student s;

	p.name;
	p.age;

	s.name;
	s.age;
	s.sNumber;

	// template test

	// func template
	std::cout << Func2(3.141592) << std::endl;
	std::cout << Func2(3.14f) << std::endl;
	std::cout << Func2(3) << std::endl;

	// class template
	Stack2<Student> sStack;
	sStack.vec.emplace_back(3);	// emplace_back은 객체를 복사해서 넣지 않고 stl::vector에 직접 객체를 생성한다
	sStack.vec.emplace_back(6);
	sStack.vec.emplace_back(9);



	return 0;
}