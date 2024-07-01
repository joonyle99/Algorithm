#include <bits/stdc++.h>
using namespace std;

int N;

void BFS()
{
	queue<pair<int, int>> q;
	q.push({ N, 0 });

	// O(3 × N) = O( N )
	while (!q.empty()) {
		auto front = q.front(); q.pop();
		if (front.first == 1) {
			cout << front.second;
			break;
		}
		if (front.first % 3 == 0) {
			q.push({ front.first / 3, front.second + 1 });
		}
		if (front.first % 2 == 0) {
			q.push({ front.first / 2 , front.second + 1 });
		}
		q.push({ front.first - 1 , front.second + 1 });
	}
}

bool visited[100005];
bool resArray[100005];
int res = 0x7f7f7f7f;

void CopyArray(bool* from, bool* to, int size) {
	for (int i = 0; i < size; i++) {
		to[i] = from[i];
	}
}

void DFS(int x, int depth)
{
	if (x == 1) {
		if (res > depth) {
			res = depth;
			CopyArray(visited, resArray, 100005);
		}
		return;
	}

	visited[x - 1] = true;
	DFS(x - 1, depth + 1);
	visited[x - 1] = false;

	if (x % 3 == 0) {
		visited[x / 3] = true;
		DFS(x / 3, depth + 1);
		visited[x / 3] = false;
	}
	if (x % 2 == 0) {
		visited[x / 2] = true;
		DFS(x / 2, depth + 1);
		visited[x / 2] = false;
	}
}

int dp[100005];
int trackedDp[100005];	// 경로 추적용
// i를 오는데 최적으로 온 경로를 기록

void DP()
{
	// dp[12]를 구하고 싶다면
	// -> dp[4] + 1
	// -> dp[6] + 1
	// -> dp[11] + 1
	// 중 하나가 답일 것이다.

	dp[1] = 0;	// 초깃값: 1을 1로 만드는 데 필요한 최소 연산 횟수

	for (int i = 2; i <= N; i++) {

		// 1
		dp[i] = dp[i - 1] + 1;		// dp[i]에 최악의 경우를 넣어준다
		trackedDp[i] = i - 1;

		// 2
		if (i % 3 == 0 && dp[i] > dp[i / 3] + 1) {
			dp[i] = dp[i / 3] + 1;
			trackedDp[i] = i / 3;
		}

		// 3
		if (i % 2 == 0 && dp[i] > dp[i / 2] + 1) {
			dp[i] = dp[i / 2] + 1;
			trackedDp[i] = i / 2;
		}
	}

	cout << dp[N] << '\n';

	int cur = N;
	while (true) {
		cout << cur << ' ';
		if (cur == 1) break;
		cur = trackedDp[cur];	// cur이 어디서부터 왔는지 알 수 있다.
	}
}

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : 1로 만들기 2

	// X가 3으로 나누어 떨어지면, 3으로 나눈다.
	// X가 2로 나누어 떨어지면, 2로 나눈다.
	// 1을 뺀다.

	// 첫째 줄에 연산을 하는 횟수의 최솟값을 출력한다.
	// 둘째 줄에는 N을 1로 만드는 방법에 포함되어 있는 수를 공백으로 구분해서 순서대로 출력한다

	cin >> N;

	// 1. BFS로 시도해보기 (추적 실패)
	// BFS();

	// 2. DFS로 시도해보기 (시간 초과)
	/*
	visited[N] = true;
	DFS(N, 0);
	cout << res << '\n';
	for (int i = N; i >= 1; i--) {
		if (resArray[i]) {
			cout << i << ' ';
		}
	}
	*/

	// 3. DP로 시도해보기

	// (1): DP 테이블 정의하기
	// dp[i] = i를 1로 만들기 위해 필요한 연산의 최소 횟수

	// (2): 점화식 찾기
	// dp[12]를 구하고 싶다면
	// -> dp[4] + 1
	// -> dp[6] + 1
	// -> dp[11] + 1
	// 중 하나가 답일 것이다.
	//
	// dp[i] = min(dp[4] + 1, dp[6] + 1, dp[7] + 1);
	// -> 이렇게 될 수 없다. 왜냐하면 12야 조건 3개 모두 연산이 가능하지만
	// 10과 같은 숫자는 '/ 3'이 안되기 때문에, 조건 체크를 해줘야 한다

	// (3): 초깃값 설정하기

	// 이렇게 추적 경로를 출력하는 문제는
	// ** 추가적으로 정보를 어디엔가 기입해야 한다 **

	DP();

	return 0;
}
