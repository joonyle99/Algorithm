#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <algorithm>

using std::cin;
using std::cout;

void Solution(int start, int end)
{
	// start부터 end까지 소수를 모두 출력하자

	// 소수 판단법
	// 소수 : N의 경우 1과 N만이 약수

	for (int number = start; number <= end; ++number)
	{
		bool isPrime = true;

		if (number == 1)
			continue;

		if (number == 2 || number == 3)
		{
			cout << number << '\n';
			continue;
		}

		// 자신의 제곱근까지 나눠본다
		for (int div = 2; div * div <= number; ++div)
		{
			if(number % div == 0)
			{
				isPrime = false;
				break;
			}
		}

		if (isPrime)
			cout << number << '\n';
	}
}

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : 소수 구하기

	int M, N;
	cin >> M >> N;

	// M이상 N이하의 소수를 모두 출력
	Solution(M, N);

	return 0;
}
