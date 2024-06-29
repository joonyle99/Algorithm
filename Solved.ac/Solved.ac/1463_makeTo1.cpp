#include <bits/stdc++.h>
using namespace std;

int N;
int res = 0x7f7f7f7f;

void DFS(int x, int cnt) {
	if (x == 1) {
		if (res > cnt) {
			res = cnt;
		}
		return;
	}

	if (x % 3 == 0) {
		DFS(x / 3, cnt + 1);
	}
	if (x % 2 == 0) {
		DFS(x / 2, cnt + 1);
	}
	DFS(x - 1, cnt + 1);
}

queue<pair<int, int>> q;

void BFS_TopDown() {

	q.push(make_pair(N, 0));

	while (!q.empty())
	{ 
		auto front = q.front(); q.pop();

		auto number = front.first;
		auto count = front.second;

		if (number == 1) {
			res = count;
			break;
		}

		// 조건 1
		if (number % 3 == 0) {
			q.push(make_pair(number / 3, front.second + 1));
		}

		// 조건 2
		if (number % 2 == 0) {
			q.push(make_pair(number / 2, front.second + 1));
		}

		// 조건 3
		q.push(make_pair(number - 1, front.second + 1));
	}
}

int dp[1000005];		// 100만 개의 int == 400만 byte == 4MB == (충분히 사용할 수 있는 전역 변수 배열이다.

void DP()
{
	// 초깃값을 정해준다
	dp[1] = 0;

	// 점화식을 이용해 Bottom Up 방식을 이용한다
	for (int i = 2; i <= N; i++) {
		// 기본적으로 넣어주는 값 (정직하게 올라가는 조건 3)
		dp[i] = dp[i - 1] + 1;
		// 이미 들어있는 dp[i]값과 비교하여 최솟값을 dp[i]에 넣는다
		if (i % 3 == 0) dp[i] = std::min(dp[i], dp[i / 3] + 1);
		// 이미 들어있는 dp[i]값과 비교하여 최솟값을 dp[i]에 넣는다
		if (i % 2 == 0) dp[i] = std::min(dp[i], dp[i / 2] + 1);
	}

	// 점화식으로 도출한 값을 옮긴다
	res = dp[N];
}

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : 1로 만들기

	// dynamic promgramming

	// 조건 1: x가 3으로 나누어 떨어지면, 3으로 나눈다.
	// 조건 2: x가 2로 나누어 떨어지면, 2로 나눈다
	// 조건 3: 1을 뺀다

	// 위와 같은 조건 3개를 '적절히' 사용해서 1을 만들려고 한다
	// 연산을 사용하는 횟수의 최솟값 구하기

	cin >> N;   // 1 <= N <= 10^6

	/// 코딩테스트 공통 사항
	// 1. 문제를 잘 읽기 (어떤 것을 요구하는 지 잘 살피자. 엄한거 구하지 말고)
	// 2. 예제 입력에 대한 출력을 잘 보기
	// 3. 입력, 과정, 결과 등에서 어떠한 변수가 필요할 지 생각한다
	// 4. 우선 당장에 짤 수 있는 코드의 스니펫(프레임)을 짠다
	// -> 어떠한 알고리즘을 이용할 것인지 파악하는 단계라고 볼 수도 있겠다.

	// 2 -> 조건 2 사용하여 1회 만에 1을 만든다
	// 
	// 10 -> 조건 3을 사용해서 9를 만든다
	// 9 -> 조건 1을 사용해서 3을 만든다
	// 3 -> 조건 1을 사용해서 1을 만든다
	// 3회 만에 1을 만든다

	// 그리디 알고리즘과 같이 현재에 최선인 선택을 하면 안된다.

	// DFS(N, 0);

	// BFS_TopDown();

	/// DP에 해당하는 사항
	// 1. 테이블을 정의한다
	// -> D[i] => i를 1로 만들기 위해 필요한 연산 사용 횟수의 최솟값
	// 
	// 2. 점화식을 찾는다
	// -> 만약 D[12]를 구하고 싶다면,
	// -> D[4] + 1, D[6] + 1, D[11] + 1 이 중에서 최솟값이 정답일 것이다
	// -> D[12] = std::min(D[4] + 1, D[6] + 1, D[11] + 1)이 된다
	//
	// 3. 초기값을 설정한다
	// -> 피보나치 수열에서 fibo(1)과 fibo(2)가 1인 것처럼, 점화식에서는 '초깃값이 필수적으로 필요'하다
	// -> 만약 D[1] = 0이라고 정의한다면,
	// -> D[2] = D[1] + 1이기 때문에 조건 3 만족
	// -> D[2] = D[1] + 1이기 때문에 조건 2 만족
	// -> D[3] = D[1] + 1이기 때문에 조건 1 만족
	// --> 즉 점화식이 돌아갈 수 있게 하기 위한 초깃값을 설정해야 한다.
	// --> 이 문제에서는 D[1]만 해주면 되지만, 초깃값이 2개 이상이 필요한 경우가 있다.

	DP();

	cout << res;

	return 0;
}
