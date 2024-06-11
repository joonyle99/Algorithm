#include <bits/stdc++.h>
using namespace std;

int M, N;   // 가로, 세로
int tomato[1005][1005];
int dist[1005][1005];

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int minDuration = 0;

queue<pair<int, int>> q;

void BFS()
{
	while (!q.empty()) {
		pair<int, int> now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			pair<int, int> next = make_pair(now.first + dx[i], now.second + dy[i]);
			if (next.first < 0 || next.first > M - 1 || next.second < 0 || next.second > N - 1) continue;
			if (tomato[next.second][next.first] != 0) continue;
			dist[next.second][next.first] = dist[now.second][now.first] + 1;	/// 핵심 포인트 2
			tomato[next.second][next.first] = 1;
			q.push(next);
		}
	}
}

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : 토마토

	// 1 => 익은 토마토
	// 0 => 익지 않은 토마토
	// -1 => 토마토 없음

	cin >> M >> N;

	// input data
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			// i == N == 세로 == 행(Row)
			// j == M == 가로 == 열(Column)
			// 이차원 배열 Array[Row][Column]
			cin >> tomato[i][j];
		}
	}

	bool isAllMature = true;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (tomato[i][j] == 1)
				q.push(make_pair(j, i));	/// 핵심 포인트 1

			if (tomato[i][j] == 0)
				isAllMature = false;
		}
	}
	if (isAllMature) {
		cout << 0 << '\n';
		return 0;
	}

	/*
	cout << "========================================" << '\n';

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << tomato[i][j] << ' ';
		}
		cout << '\n';
	}

	cout << "========================================" << '\n';
	*/

	// main logic
	BFS();

	// check duration
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			// 모든 토마토가 익지 못하는 경우
			if (tomato[i][j] == 0)
			{
				cout << "-1" << '\n';
				return 0;
			}

			minDuration = max(minDuration, dist[i][j]);
		}
	}

	cout << minDuration << '\n';

	/*
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << tomato[i][j] << ' ';
		}
		cout << '\n';
	}

	cout << "========================================" << '\n';

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << dist[i][j] << ' ';
		}
		cout << '\n';
	}
	*/

	return 0;
}
