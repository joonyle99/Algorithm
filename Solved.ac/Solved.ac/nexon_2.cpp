#include <bits/stdc++.h>
using namespace std;

int m, n;
int d[10];

int dp[31];

int result = 0;

void Solution_DFS(int sum, vector<int>& path) {
	// base condition
	if (sum == n) {
		for (int i = 0; i < path.size(); ++i) {
			cout << path[i] << ' ';
		}
		cout << '\n';
		result++;
		return;
	}

	for (int i = 0; i < m; ++i) {
		if (sum + d[i] > n) continue;
		path.push_back(d[i]);
		Solution_DFS(sum + d[i], path);
		path.pop_back();        // backtracking
	}
}

void Solution_DP() {

	// 모든 주사위 눈을 돌며, 해당 칸의 가짓수를 초기화
	for (int i = 0; i < m; ++i) {
		dp[d[i]] = 1;
	}

	// Bottom-Up
	for (int now = 1; now <= n; ++now) {
		for (int i = 0; i < m; ++i) {
			int next = now + d[i];
			if (next <= n) {
				dp[next] += dp[now];
			}
		}
	}
}

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : 주사위 탈출 게임

	// 1 <= m <= 10
	// 1 <= n <= 30
	// 1 <= d[i] <= 30

	cin >> m;       // 주사위 눈의 수
	cin >> n;       // 보드의 크기

	for (int i = 0; i < m; ++i) {
		cin >> d[i];
	}

	/*
	* (1) : DFS (재귀 함수) 풀이방식
	* Test Case 9에서 시간초과 발생(최적화 필요)
	*/

	// vector<int> path;
	// Solution_DFS(0, path);

	// cout << result;

	/*
	* (2) : Dynamic Programming (기억해서 풀기) 풀이방식
	*
	* 1. Dp 테이블 정의하기
	* dp[i]: 특정 칸에 도달할 수 있는 주사위 눈의 가짓수
	*
	* 2. 점화식 찾기
	* k번째 칸의 가짓수를 k번째 칸에서 갈 수 있는 칸(k + d[i])에 더해준다
	* dp[k + d[i]] += dp[k]
	* 
	* 3. 초깃값 설정하기
	* 주사위 눈에 해당하는 칸은 1로 초기화한다
	*/

	Solution_DP();

	cout << dp[n];

	return 0;
}
