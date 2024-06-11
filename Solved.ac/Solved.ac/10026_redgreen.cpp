#include <bits/stdc++.h>
using namespace std;

int N;
string board[105];
bool visited[105][105];
queue<pair<int, int>> q1;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int normalAreaCount = 0;
int noneNormalAreaCount = 0;

void Make_Board()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> board[i];
}

void BFS(int row, int col)
{
	auto start = make_pair(col, row);
	visited[start.second][start.first] = true;
	q1.push(start);

	// check color
	char color = board[row][col];

	while (!q1.empty())
	{
		auto now = q1.front(); q1.pop();
		for (int i = 0; i < 4; i++)
		{
			auto next = make_pair(now.first + dx[i], now.second + dy[i]);
			if (next.first < 0 || next.first >= N || next.second < 0 || next.second >= N) continue;
			if (board[next.second][next.first] != color) continue;
			if (visited[next.second][next.first]) continue;
			visited[next.second][next.first] = true;
			q1.push(next);
		}
	}
}

void NormalFunction()
{
	for (int row = 0; row < N; row++)	// 세로
	{
		for (int col = 0; col < board[row].length(); col++)	// 가로
		{
			if (visited[row][col]) continue;

			BFS(row, col);
			normalAreaCount++;
		}
	}
}

void InitForNoneNormal()
{
	for (int row = 0; row < N; row++)	// 세로
	{
		for (int col = 0; col < board[row].length(); col++)	// 가로
		{
			visited[row][col] = false;
			if (board[row][col] == 'G')
				board[row][col] = 'R';
		}
	}

}

void NoneNormalFunction()
{
	for (int row = 0; row < N; row++)	// 세로
	{
		for (int col = 0; col < board[row].length(); col++)	// 가로
		{
			if (visited[row][col]) continue;

			BFS(row, col);
			noneNormalAreaCount++;
		}
	}
}

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : 적록색약
	// 구역의 수를 구하는 프로그램

	Make_Board();

	NormalFunction();

	InitForNoneNormal();

	NoneNormalFunction();

	cout << normalAreaCount << ' ' << noneNormalAreaCount;

	return 0;
}
