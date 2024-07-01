#include <bits/stdc++.h>
using namespace std;

int N, M;
int numArray[100005];   // 10만개의 int => 40만 byte => 0.4MB로 메모리 여유
int dp[100005];

/*
*
* 메모리 레이아웃
*
높은 주소
+------------------+
|       스택       | <- 지역 변수, 함수 호출 정보
|        ↓         |
|                  |
|                  |
|        ↑         |
|       힙         | <- 동적으로 할당된 메모리
+------------------+
|   미사용 메모리   |
+------------------+
|     데이터       | <- 초기화된 전역/정적 변수
+------------------+
|      BSS        | <- 초기화되지 않은 전역/정적 변수
+------------------+
|     텍스트       | <- 프로그램 코드
+------------------+
낮은 주소
*/
int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : 구간 합 구하기 4

	// 총 M개의 줄에 입력으로 주어진
	// i번째 수부터 j번째 수까지 합을 출력한다.

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		cin >> numArray[i];
	}

	/*
	while (M--) {
		int i, j;
		cin >> i >> j;

		int sum = 0;

		// i부터 j까지의 합을 계산하는 내부 루프는 최악의 경우 N번 반복됩니다
		for (int k = i; k <= j; k++) {
			sum += numArray[k];
		}

		cout << sum << '\n';
	}

	// N: 10만
	// M: 10만

	// O(M * N) => 10만 x 10만 = 10^10 = 100억 번의 연산이 필요하다
	// 시간 제한은 1초
	// 컴퓨터의 1초 동안의 연산량은 대략 1억번
	// 따라서 O(N^2) 시간복잡도의 알고리즘으로 해결할 수 없다
	*/

	/// 기억해서 풀기 알고리즘 (DP)로 해결하기

	// dp 테이블 정의하기
	// dp[i] = 처음부터 i번째 수까지의 합을 담아둔 배열

	// dp[1] = numArray[1]
	// dp[2] = numArray[1] + numArray[2]
	// dp[3] = numArray[1] + numArray[2] + numArray[3]
	// ...
	// dp[i] = dp[i-1] + numArray[i]

	// 즉 i번째 ~ j번째 까지의 합을 구하기 위해서는
	// 1번째 ~ j번쩨 까지의 합
	// - 1번째 ~ i-1번째 까지의 합
	// = 'i번째 ~ j번째 까지의 합' 이 도출된다

	dp[1] = numArray[1];
	for (int i = 2; i <= N; i++) {
		dp[i] = dp[i - 1] + numArray[i];		// 각각의 num은 1000이하이기 때문에, 1000을 10만번 더해도 1억이기 때문에 int 범위 안에 들어온다.
	}

	while (M--) {
		int i, j;
		cin >> i >> j;
		cout << dp[j] - dp[i] + numArray[i] << '\n';
	}

	// barking dog은 dp[0] = 0으로 설정하고
	// dp[j] - dp[i-1]로 해결했다 (좀 더 깔끔)

	return 0;
}
