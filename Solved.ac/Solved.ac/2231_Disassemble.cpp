#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <algorithm>

using std::cin;
using std::cout;

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : 분해합

	int N; cin >> N;

	// M은 N의 생성자
	// M : 245 N : 256 (245 + 2 + 4 + 5)

	// 216이 주어졌을때 가장 작은 생성자를 구하는 방법

	// 가장 처음 안될 것 같은 방법
	int min = INT32_MAX;
	bool hasAnswer = false;

	for (int c = N; c >= 1; --c)
	{
		int result = c;
		int tempC = c;

		while (tempC != 0)
		{
			result += tempC % 10;
			tempC /= 10;
		}

		// 생성자가 있는 경우
		if (result == N)
		{
			hasAnswer = true;

			if (min > c)
				min = c;
		}
	}

	if (hasAnswer)
		cout << min << '\n';
	else
		cout << 0 << '\n';



	return 0;
}
