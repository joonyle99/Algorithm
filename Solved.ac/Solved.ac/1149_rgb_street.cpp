#include <bits/stdc++.h>
using namespace std;

int N;
int house[1005][3];

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : RGB 거리

	/// 1. 문제를 잘 읽기
	// RGB거리에는 집이 N개 있다.
	// 1번 집부터 N번 집이 순서대로 있다.
	// 집은 빨강, 초록, 파랑 중 하나의 색으로 칠해야 한다
	//
	// 조건 1: 1번 집의 색은 2번 집의 색과 같지 않아야 한다.
	// 조건 2: N번 집의 색은 N-1번 집의 색과 같지 않아야 한다.
	// 조건 3: i(2 ≤ i ≤ N-1)번 집의 색은 i-1번, i+1번 집의 색과 같지 않아야 한다.
	//
	// 요구하는 것: '모든 집을 칠하는 비용의 최솟값을 출력'

	/// 2. 입력값을 받는다
	cin >> N;   // 집의 수
	for (int i = 1; i <= N; i++) {   // 1번 집부터 N번 집까지 RGB 비용 설정
		int r, g, b;
		cin >> r >> g >> b;
		house[i][0] = r;
		house[i][1] = g;
		house[i][2] = b;
	}

	/// 3. 예제를 분석한다
	// 26 40 83     // 1번 집
	// 49 60 57     // 2번 집
	// 13 89 99     // 3번 집


	/// DP 테이블 (배열) 정의하기
	// dp[i][j] = i번째 집까지 칠하기 위한 최솟값, 단 i번째 집은 j로 칠해졌다

	/// 점화식 찾기 (+ 초깃값 설정)
	//

	int dp[1005][3];

	/* 공준열이 푼 풀이
	for (int i = 0; i < 3; i++) {
		dp[1][i] = house[1][i];
	}
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < 3; j++) {
			dp[i][j] = std::min(dp[i - 1][(j + 1) % 3], dp[i - 1][(j + 2) % 3]) + house[i][j];
		}
	}
	*/

	// barking dog 식 풀이
	// r g b는 3개 밖에 없으니까, 굳이 for문 안 돌려도 이렇게 하드하게 작성하는 게 더 직관적이고 효율적이다.

	dp[1][0] = house[1][0];
	dp[1][1] = house[1][1];
	dp[1][2] = house[1][2];

	for (int i = 2; i <= N; i++) {
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + house[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + house[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + house[i][2];
	}

	// 1. 
	// cout << min(dp[N][0], dp[N][1], dp[N][2]);

	// 2.
	cout << *min_element(dp[N], dp[N] + 3);

	return 0;
}
