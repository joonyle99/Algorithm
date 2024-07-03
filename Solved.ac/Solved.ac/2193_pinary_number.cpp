#include <bits/stdc++.h>
using namespace std;

int N;
pair<long long, long long> dp[100];

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : 이친수

	cin >> N;

	// dp[i] = i자리 이친수들 중 0으로 끝나는 과 1의 각각의 개수

	dp[1] = { 0, 1 };
	// dp[2] = { 1, 0 };
	// dp[3] = { 1, 1 };
	// dp[4] = { 2, 1 };
	// dp[5] = { 3, 2 };
	// dp[6] = { 5, 3 };

	// 0으로 끝나있던거는 0과 1로 바뀜
	// 1로 끝나있던거는 0으로 바뀜

	// 최종적으로 0으로 끝나있는 개수는 prev_left + prev_right
	// 최종적으로 1로 끝나있는 개수는 prev_left

	// long long을 사용해야 오버플로우가 발생하지 않는다

	for (int i = 2; i <= N; i++) {
		dp[i] = { dp[i - 1].first + dp[i - 1].second, dp[i - 1].first };
	}

	cout << dp[N].first + dp[N].second;

	return 0;
}
