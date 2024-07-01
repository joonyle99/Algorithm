#include <bits/stdc++.h>
using namespace std;

int n;
int dp[1005];

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : 2×n 타일링

	// dp 테이블 정의하기
	// dp[i] = 2 x i의 직사각형을 채우는 방법의 수

	// 점화식 찾기
	// 2 x n의 직사각형이 있을 때, left-top의 칸을 기준으로 살펴보면
	// 2 x 1의 직사각형을 놓는 방법과
	// 1 x 2의 직사각형을 놓는 방법이 있다.
	// 1 x 2의 직사각형을 놓는 경우에는, 그 아래에 1 x 2의 직사각형 밖에 놓을 수 없다.
	// 따라서  dp[i] = dp[i-1] + dp[i-2]가 된다

	// 초깃값은
	// dp[1]과 dp[2]만 구하면, dp[i] = dp[i-1] + dp[i-2]를 만족시킬 수 있다.

	cin >> n;
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;	// int over flow 발생을 막기 위한 나머지 값만 계속해서 가져간다
		// dp[i] = (dp[i - 1] % 10007 + dp[i - 2] % 10007) % 10007; // 모듈러 연산의 분배법칙 (필요없지만 참고)
	}
	cout << dp[n];

	return 0;
}
