#include <bits/stdc++.h>
using namespace std;

int N;
int duration[20];
int price[20];

int maxPrice = -1;

int dp[20];			// k번째 날까지 상담을 통해 얻을 수 있는 최대 수익

void DFS(int nowDay, int hasPrice) {
	// 탈출 조건
	if (nowDay >= N + 1) {
		maxPrice = max(maxPrice, hasPrice);
		return;
	}

	/// 멀티버스

	// 상담을 할 수 있는 경우
	if (nowDay + duration[nowDay] <= N + 1) {
		DFS(nowDay + duration[nowDay], hasPrice + price[nowDay]);
	}

	// 상담을 하지 않는 경우
	DFS(nowDay + 1, hasPrice);
}

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : 퇴사

	cin >> N;
	for (int i = 1; i <= N; ++i) {
		cin >> duration[i];
		cin >> price[i];
	}

	// 1. DFS(재귀함수)로 풀 수 있다.
	// DFS(1, 0);
	// cout << maxPrice;

	// 2. Dynamic Programming(DP)로 풀 수 있다.
	for (int day = 1; day <= N; ++day) {
		// 상담을 진행할 수 있는 경우
		if (day + duration[day] <= N + 1) {
			int nextDay = day + duration[day];
			int nextPrice = dp[day] + price[day];
			dp[nextDay] = max(dp[nextDay], nextPrice);
		}
		// 상담을 진행하지 않고 하루 쉰다
		dp[day + 1] = max(dp[day + 1], dp[day]);
	}

	// N + 1일까지의 최대 수익을 출력합니다.
	cout << dp[N + 1];

	return 0;
}
