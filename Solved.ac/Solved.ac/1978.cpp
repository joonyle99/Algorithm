#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N; cin >> N;
	vector<int> vec;
	int count = 0;

	for (int i = 0; i < N; ++i)
	{
		int value; cin >> value;
		vec.push_back(value);
	}

	// value는 1000이하의 자연수
	// 소수를 찾는 방법...?
	for (const auto v : vec)
	{
		if (v == 2)
		{
			count++;
			continue;
		}

		if (v == 1)
		{
			continue;
		}

		bool isPrime = true;

		// 1. 2 ~ v-1 까지 모두 나눠보고 소수인지 판별
		for (int i = 2; i < v; i++)
		{
			// i로 나눴을때 나누어떨어지면??
			// 소수가 아님
			if (v % i == 0)
			{
				isPrime = false;
				break;
			}

			// 모두 다 돌았는데 나누어 떨어지지 않았다??
			// 소수임

			// 즉 한번이라도 나누어 떨어지면 소수가 아님

		}

		if (isPrime)
			count++;
	}

	cout << count << endl;

	return 0;
}