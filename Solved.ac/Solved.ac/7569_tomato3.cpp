#include <bits/stdc++.h>
using namespace std;

struct Pos
{
	int d, r, c;
	Pos(int _d, int _r, int _c)
	{
		d = _d;
		r = _r;
		c = _c;
	}
};

int M, N, H;

int box[105][105][105];
int dist[105][105][105];

int deltaDepth[6] = { -1, 1, 0, 0, 0, 0 };  // depth
int deltaRow[6] = { 0, 0, 0, 0, -1, 1 };    // row
int deltaCol[6] = { 0, 0, -1, 1, 0, 0 };    // col

queue<Pos> q;

int minDuration = -1;

void Make_Box()
{
	cin >> M >> N >> H;

	for (int depth = 0; depth < H; depth++) {
		for (int row = 0; row < N; row++) {
			for (int col = 0; col < M; col++) {
				cin >> box[depth][row][col];
			}
		}
	}
}

void BFS() {
	while (!q.empty()) {
		auto now = q.front(); q.pop();
		for (int i = 0; i < 6; i++) {
			auto next = Pos(now.d + deltaDepth[i], now.r + deltaRow[i], now.c + deltaCol[i]);
			if (next.d < 0 || next.d > H - 1 || next.r < 0 || next.r > N - 1 || next.c < 0 || next.c > M - 1) continue;
			if (box[next.d][next.r][next.c] != 0) continue;
			dist[next.d][next.r][next.c] = dist[now.d][now.r][now.c] + 1;
			box[next.d][next.r][next.c] = 1;
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
	// 며칠이 지나면 토마토들이 모두 익는지
	// 그 최소 일수를 구하는 프로그램

	Make_Box();

	// 만약, 저장될 때부터 모든 토마토가 익어있는 상태(1)이면 0을 출력해야 한다.
	bool isAllMature = true;
	for (int depth = 0; depth < H; depth++) {
		for (int row = 0; row < N; row++) {
			for (int col = 0; col < M; col++) {
				// 안 익어있는 토마토가 있는지 확인한다
				if (box[depth][row][col] == 0)
					isAllMature = false;
			}
		}
	}

	if (isAllMature)
	{
		cout << 0;
		return 0;
	}

	for (int depth = 0; depth < H; depth++) {
		for (int row = 0; row < N; row++) {
			for (int col = 0; col < M; col++) {
				// 익어있는 토마토가 있다면 큐에 넣는다
				if (box[depth][row][col] == 1)
					q.emplace(depth, row, col);
			}
		}
	}

	BFS();

	// 토마토가 모두 익지는 못하는 상황이면 -1을 출력해야 한다.
	bool isNeverMature = false;
	for (int depth = 0; depth < H; depth++) {
		for (int row = 0; row < N; row++) {
			for (int col = 0; col < M; col++) {
				// 안 익어있는 토마토가 있는지 확인한다
				if (box[depth][row][col] == 0)
					isNeverMature = true;
			}
		}
	}

	if (isNeverMature)
	{
		cout << -1;
		return 0;
	}

	for (int depth = 0; depth < H; depth++) {
		for (int row = 0; row < N; row++) {
			for (int col = 0; col < M; col++) {
				// 최대 기간을 구한다
				minDuration = max(minDuration, dist[depth][row][col]);
			}
		}
	}

	cout << minDuration;

	return 0;
}