#include <bits/stdc++.h>
using namespace std;

int n;
long long dp[1005];

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : 2 x n 타일링 2

	// 문제의 조건에서 10007로 나눈 나머지를 출력하라고 한 이유에 대해서 생각해봐라
	// 그러면 각 연산에서 10007을 연산하도록 유도했음을 알 수 있다.

	// 나머지 연산의 성질
	// (a + b) % c = ( (a % c) + (b % c) ) % c (모듈러 연산의 분배 법칙 성립)

	cin >> n;

	// dp[i] = 2 x i의 직사각형을 1 x 2, 2 x 1, 2 x 2 타일로 채우는 방법의 수
	dp[1] = 1;
	dp[2] = 3;
	for (int i = 3; i <= n; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 2]) % 10007;
	}

	cout << dp[n];

	return 0;
}
