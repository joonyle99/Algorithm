#include <bits/stdc++.h>
using namespace std;

int n;

int res = 0;

void Recursive(int cur)
{
	// 방법을 하나 찾은 것이다
	if (cur == n) {
		res++;
		return;
	}

	// 이 방법은 아닌 것이다
	if (cur > n) {
		return;
	}

	for (int i = 1; i <= 3; i++) {
		Recursive(cur + i);
	}
}

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : 1, 2, 3 더하기

	// 1. 테이블을 정의한다
	// -> dp[i] -> i를 1, 2, 3의 합으로 나타내는 방법의 수
	// 
	// 2. 점화식을 찾는다 (
	// -> dp[4]를 구하고 싶다면,
	// --> dp[3] // (1+1+1)+1, (3)+1, (2+1)+1, (1+2)+1 ==> Dp[3] = 4
	// --> dp[2] // (1+1)+2, (2)+2 ==> Dp[2] = 2
	// --> dp[1] // (1)+3 => Dp[1] = 1
	// // -> dp[4] = dp[3] + dp[2] + dp[1]
	// 
	// dp[k] = dp[k-1] + dp[k-2] + dp[k-3]
	// 
	// 3. 초깃값을 설정한다
	//
	// dp[1] = 1 // 1을 1, 2, 3의 합으로 나타내는 방법의 수
	//

	// dp에 들어가 있는 값이 바뀌지 않는다.
	int dp[15];

	// ** 어디까지 초깃값이 설정되어야 하는지 잘 아는 것이 중요하다 **
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	// ** 미리 계산을 해둔다. 테스트 케이스가 여러개이지만 한 번만 계산해두면 계속해서 사용할 수 있다 **
	for (int i = 4; i <= 11; i++)
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];

	int T;  cin >> T;
	while (T--) {
		cin >> n;


		// 동적 프로그래밍 방식 (매우 효율적)
		cout << dp[n] << '\n';


		// 재귀함수 방식 (매우 비효율적)
		// Recursive(0);
		// cout << res << '\n';
		// res = 0;
	}

	return 0;
}
