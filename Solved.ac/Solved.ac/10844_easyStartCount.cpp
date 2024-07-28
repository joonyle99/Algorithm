#include <bits/stdc++.h>
using namespace std;

int N;
int dp[105][10];

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : 쉬운 계단 수

	cin >> N;

	// dp[i][j] : i의 길이를 가지면서 j로 끝나는 계단수의 개수

	for (int i = 1; i <= 9; ++i)
	{
		/*
		dp[1][1] = 1;
		dp[1][2] = 1;
		dp[1][3] = 1;

		...

		*/

		dp[1][i] = 1;
	}

	for (int length = 2; length <= N; ++length)
	{
		for (int last = 0; last <= 9; ++last)
		{
			if (last == 0)
			{
				// 이전 길이의 1로 끝나는 계단수

				dp[length][last] = dp[length - 1][1];
			}
			else if (last == 9)
			{
				// 이전 길이의 8로 끝나는 계단수

				dp[length][last] = dp[length - 1][8];
			}
			else
			{
				// 이전 길이의 -1 or +1로 끝나는 계단수
				dp[length][last] = dp[length - 1][last - 1] + dp[length - 1][last + 1];
			}

			dp[length][last] %= 1000000000;
		}
	}

	int result = 0;

	for (int i = 0; i <= 9; ++i)
	{
		result += dp[N][i];
		result %= 1000000000;
	}

	cout << result;

	return 0;
}
