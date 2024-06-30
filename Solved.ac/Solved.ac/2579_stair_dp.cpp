#include <bits/stdc++.h>
using namespace std;


int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : 계단 오르기

	// 게임에서 얻을 수 있는 총 점수의 최댓값을 구하는 프로그램을 작성하시오.

	// 첫 번째 계단은 무조건 밟아야 한다
	// 연속된 세 계단은 밟을 수 없다
	// 한번에 한 칸 혹은 두 칸 올라갈 수 있다
	// 마지막 계단은 반든시 밟아야 한다

	int N; cin >> N;
	int stairs[305];	// stairs[i] = i층 계단의 점수
	for (int i = 1; i <= N; i++) {
		cin >> stairs[i];
	}
	int dp[305];		// dp[i] = i층 계단 까지의 최댓값
	dp[0] = 0;
	dp[1] = stairs[1];
	dp[2] = stairs[1] + stairs[2];
	// dp[3]
	// 0 -> 1 -> 3
	// 0 -> 2 -> 3
	dp[3] = std::max(dp[1] + stairs[3], dp[0] + stairs[2] + stairs[3]);

	// 마지막 계단은 반드시 밟아야 한다
	// 계단은 한 계단 혹은 두 계단씩 오를 수 있다.
	// 연속된 세개의 계단을 밟으면 안된다.
	//
	// 1 -> 2
	// 1 -> 3
	//
	// 1 -> 4 (x)
	// 1 -> 2 -> 3 (x)
	//
	// 4 -> 5 -> 6 (x)
	// 3 -> 6 (x)
	//
	// 3 -> 5 -> 6 (두 칸 뛰었다가 한 칸 뛰어서 가는 것)
	// 4 -> 6 (두 칸 뛰어서 가는 것)
	//
	// dp[4] + stairs[6]
	// vs
	// dp[5] + stairs[6]
	// 중에서 더 큰 것

	for (int i = 4; i <= N; i++) {
		int a = dp[i - 2] + stairs[i];						// i - 2 -> i
		int b = dp[i - 3] + stairs[i - 1] + stairs[i];		// i - 3 -> i - 1 -> i		// dp[i-1] + stairs[i] 만 하면 안되는 이유: 연속된 세 개의 계단을 밟을 수 있기 때문에 그 전에 두 칸 뛰고 한 칸 뛰어줘야 한다
		dp[i] = std::max(a, b);
	}

	cout << dp[N];

	return 0;
}
