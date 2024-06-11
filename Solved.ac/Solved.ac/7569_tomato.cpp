#include <bits/stdc++.h>
using namespace std;

int M, N, H;

int box[105][105][105];
bool visited_J[105][105][105];

int deltaDepth[6] = { -1, 1, 0, 0, 0, 0 };  // depth
int deltaRow[6] = { 0, 0, 0, 0, -1, 1 };    // row
int deltaCol[6] = { 0, 0, -1, 1, 0, 0 };    // col

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

void BFS(int depth, int row, int col) {

	Pos start(depth, row, col);
	queue<Pos> myQueue;
	myQueue.push(start);
	visited_J[start.d][start.r][start.c] = true;

	while (!myQueue.empty()) {
		Pos now = myQueue.front();
		myQueue.pop();

		for (int i = 0; i < 6; i++) {
			Pos next(now.d + deltaDepth[i], now.r + deltaRow[i], now.c + deltaCol[i]);
			if (next.d < 0 || next.d > H - 1 || next.r < 0 || next.r > N - 1 || next.c < 0 || next.c > M - 1)
				continue;
			if (visited_J[next.d][next.r][next.c])
				continue;
			myQueue.push(next);
			visited_J[next.d][next.r][next.c] = true;
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

	cin >> M >> N >> H;

	for (int depth = 0; depth < H; depth++) {
		for (int row = 0; row < N; row++) {
			for (int col = 0; col < M; col++) {
				cin >> box[depth][row][col];
			}
		}
	}

	// 모든 토마토가 들어있는 박스칸에 대해 Breadth First Search
	for (int depth = 0; depth < H; depth++) {
		for (int row = 0; row < N; row++) {
			for (int col = 0; col < M; col++) {
				BFS(depth, row, col);
			}
		}
	}

	return 0;
}
