#include <bits/stdc++.h>
using namespace std;

string field[12];
bool visited[12][6];

// 하 우 상 좌
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

void ResetVisited()
{
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			visited[i][j] = false;
		}
	}
}

void MoveDownAll()
{
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (field[i][j] == '@')
			{
				if (i - 1 < 0) continue;

				// 세로줄에 있는 거 다 한 칸씩 내린다
				for (int k = i - 1; k >= 0; k--)
				{
					// 한 칸씩 내린다 (Swap을 사용해도 된다)
					field[k + 1][j] = field[k][j];

					if (k == 0)
					{
						field[k][j] = '.';
					}
				}
			}
		}
	}
}

vector<pair<int, int>> BFS(int row, int col)
{
	vector<pair<int, int>> vec;
	queue<pair<int, int>> queue;

	vec.push_back({ row, col });
	queue.push({ row, col });

	visited[row][col] = true;

	while (!queue.empty())
	{
		pair<int, int> now = queue.front(); queue.pop();

		for (int i = 0; i < 4; i++)
		{
			pair<int, int> next = { now.first + dy[i], now.second + dx[i] };

			if (next.first < 0 || next.second < 0 || next.first >= 12 || next.second >= 6) continue;
			if (field[next.first][next.second] != field[now.first][now.second]) continue;
			if (visited[next.first][next.second] == true) continue;

			vec.push_back({ next.first, next.second });
			queue.push({ next.first, next.second });

			visited[next.first][next.second] = true;
		}
	}

	return vec;
}

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : Puyo Puyo

	for (int i = 0; i < 12; i++)
	{
		cin >> field[i];
	}

	int result = 0;

	while (true)
	{
		vector<pair<int, int>> parts;

		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if (field[i][j] != '.' && visited[i][j] == false)
				{
					vector<pair<int, int>> part = BFS(i, j);

					if (part.size() >= 4)
					{
						for (int k = 0; k < part.size(); k++)
						{
							parts.push_back({ part[k].first, part[k].second });
						}
					}
				}
			}
		}

		if (parts.empty()) break;

		result++;

		for (int i = 0; i < parts.size(); i++)
		{
			field[parts[i].first][parts[i].second] = '@';
		}

		MoveDownAll();

		ResetVisited();
	}

	cout << result;

	return 0;
}
