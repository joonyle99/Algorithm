#pragma once

#include <iostream>
#include <ctime>

using namespace std;

class Random
{
private:
	static Random* Instance;

public:
	static Random& GetInstance()
	{
		if (Instance == nullptr)
		{
			Instance = new Random;
			srand(time(0));
		}
		return *Instance;
	}

public:
	static int GetRandomNumber()
	{
		return rand() % 10000;
	}
};
