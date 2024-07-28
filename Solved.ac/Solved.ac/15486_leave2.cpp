#include <bits/stdc++.h>
using namespace std;

int N;
int t[1500005];     // 150만 x 4Byte = 6,000,000 BYTE => 5859 KB => 5.7 MB (이 정도는 전역변수에서 무리 없다)
int p[1500005];
int dp[1500005];

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : 퇴사 2

	cin >> N;       // N은 최대 1,500,000

	for (int i = 1; i <= N; ++i)
	{
		cin >> t[i] >> p[i];
	}

	for (int now = 1; now <= N; ++now)
	{
		/// 상담을 진행할 상황이 되든 안되든, 쉬고 다음 날로 넘어간 경우
		dp[now + 1] = max(dp[now + 1], dp[now]);

		// 현재 날짜에서 상담을 진행할 때, 적어도 퇴직 날까지는 상담이 끝나는 경우
		if (now + t[now] <= N + 1)
		{
			int nextDay = now + t[now];
			int nextPrice = dp[now] + p[now];

			dp[nextDay] = max(dp[nextDay], nextPrice);
		}
	}

	cout << dp[N + 1];

	return 0;
}
