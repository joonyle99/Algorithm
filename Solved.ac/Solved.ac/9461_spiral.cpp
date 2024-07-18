#include <bits/stdc++.h>
using namespace std;

int T;
int N;
long long dp[105];

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : 파도반 수열

	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 2;
	dp[5] = 2;

	for (int i = 6; i <= 100; ++i) {
		dp[i] = dp[i - 1] + dp[i - 5];
	}

	// 값이 얼마나 커질 수 있을까?
	// dp[100] = dp[99] + dp[95];

	cin >> T;
	while (T--) {
		cin >> N;
		cout << dp[N] << '\n';
	}

	return 0;
}
