#include <bits/stdc++.h>
using namespace std;

struct Point {
	int Layer;
	int Row;
	int Col;

	Point(int l, int r, int c) {
		this->Layer = l;
		this->Row = r;
		this->Col = c;
	}
};

int input[5][5][5];
int board[5][5][5];
int visited[5][5][5];

int dh[6] = { 1, -1, 0, 0, 0, 0 };
int dr[6] = { 0, 0, 1, -1, 0, 0 };
int dc[6] = { 0, 0, 0, 0, 1, -1 };

int result = 0x7f7f7f7f;

void Draw() {
	system("cls");
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			for (int k = 0; k < 5; ++k) {
				cout << board[i][j][k] << ' ';
			}
			cout << '\n';
		}
		cout << '\n';
	}
}

void ResetVisited() {
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			for (int k = 0; k < 5; ++k) {
				visited[i][j][k] = 0;
			}
		}
	}
}

void Rotate(int layer, int count, bool isCCW) {

	if (count == 0)
		return;

	int temp[5][5];

	// 원본 데이터를 임시 배열에 복사
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			temp[i][j] = board[layer][i][j];
		}
	}

	for (int r = 0; r < count; ++r) {
		if (!isCCW) {  // 시계 방향
			for (int i = 0; i < 5; ++i) {
				for (int j = 0; j < 5; ++j) {
					board[layer][j][4 - i] = temp[i][j];
				}
			}
		}
		else {  // 반시계 방향
			for (int i = 0; i < 5; ++i) {
				for (int j = 0; j < 5; ++j) {
					board[layer][4 - j][i] = temp[i][j];
				}
			}
		}

		// 다음 회전을 위해 board를 temp에 복사
		for (int i = 0; i < 5; ++i) {
			for (int j = 0; j < 5; ++j) {
				temp[i][j] = board[layer][i][j];
			}
		}
	}
}

void BFS(int nl, int nr, int nc) {

	ResetVisited();

	queue<Point> q;
	q.push({ nl, nr, nc });
	visited[nl][nr][nc] = 1;

	while (!q.empty()) {

		auto now = q.front(); q.pop();

		// 6방향으로 이동이 가능한지 판단한다
		for (int i = 0; i < 6; ++i) {
			auto next = Point(now.Layer + dh[i], now.Row + dr[i], now.Col + dc[i]);

			if (next.Layer < 0 || next.Layer >= 5 || next.Row < 0 || next.Row >= 5 || next.Col < 0 || next.Col >= 5) continue;
			if (board[next.Layer][next.Row][next.Col] == 0) continue;
			if (visited[next.Layer][next.Row][next.Col] != 0) continue;

			q.push({ next.Layer, next.Row, next.Col });
			visited[next.Layer][next.Row][next.Col] = visited[now.Layer][now.Row][now.Col] + 1;
		}
	}

	if (visited[4][4][4] != 0)
		result = min(result, visited[4][4][4] - 1);
}

// 레이어 0부터 4까지 모든 경우의 수를 회전시킨다
void DFS(int layer) {

	// 모든 층이 결정된 경우 길찾기를 시작한다
	if (layer == 5) {
		if (board[0][0][0] == 1) {
			BFS(0, 0, 0);
		}
		return;
	}

	for (int r = 0; r < 4; ++r) {
		Rotate(layer, r, false);
		DFS(layer + 1);				// layer: 0, 1, 2, 3, 4
		Rotate(layer, r, true);
	}
}

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : Maaaaaaaaaze

	// input
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			for (int k = 0; k < 5; ++k) {
				cin >> input[i][j][k];
			}
		}
	}

	/// 하.. 층을 다르게 생각해야 하네..

	// make all combination
	int order[5] = { 0, 1, 2, 3, 4 };
	do {

		for (int layer = 0; layer < 5; ++layer) {
			for (int row = 0; row < 5; ++row) {
				for (int col = 0; col < 5; ++col) {
					int orederLayer = order[layer];
					board[layer][row][col] = input[orederLayer][row][col];
				}
			}
		}

		DFS(0);

	} while (next_permutation(order, order + 5));

	if (result == 0x7f7f7f7f) cout << -1;
	else cout << result;

	return 0;
}
