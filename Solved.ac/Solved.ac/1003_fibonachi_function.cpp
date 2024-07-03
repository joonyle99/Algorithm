#include <bits/stdc++.h>
using namespace std;

int T;
pair<int, int> dp[41];

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : 피보나치 함수

	// dp 테이블 정의하기
	// dp[i] = fibo(i)에서 0과 1이 출력된 횟수

	dp[0] = { 1, 0 };
	dp[1] = { 0, 1 };

	for (int i = 2; i <= 40; i++) {
		dp[i] = { dp[i - 1].first + dp[i - 2].first, dp[i - 1].second + dp[i - 2].second };
	}

	cin >> T;
	while (T--) {
		int N; cin >> N;
		cout << dp[N].first << ' ' << dp[N].second << '\n';
	}

	return 0;
}
