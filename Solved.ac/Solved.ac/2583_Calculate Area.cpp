#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <algorithm>

using std::cin;
using std::cout;

int M, N, K;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1, 0,0 };

struct Position
{
	int x, y;
	Position(int _x, int _y)
		: x(_x), y(_y)
	{}
};

int visited[101][101];

int BFS(Position startPos)
{
	int innerCount = 1;

	std::queue<Position> myQueue;
	myQueue.push(startPos);
	visited[startPos.y][startPos.x] = 1;

	while (!myQueue.empty())
	{
		Position curPos = myQueue.front();
		myQueue.pop();

		for (int k = 0; k < 4; ++k)
		{
			Position nextPos(curPos.x + dx[k], curPos.y + dy[k]);

			if (nextPos.x < 0 || nextPos.y < 0 || nextPos.x >= N || nextPos.y >= M)
				continue;

			if (visited[nextPos.y][nextPos.x] != 1)
			{
				visited[nextPos.y][nextPos.x] = 1;
				myQueue.push(nextPos);
				innerCount++;
			}
		}
	}

	return innerCount;
}

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : 영역 구하기

	cin >> M >> N >> K;

	// 모눈종이에 K개의 직사각형을 그린다
	while (K-- > 0)
	{
		int bl_x, bl_y, tr_x, tr_y;
		cin >> bl_x >> bl_y >> tr_x >> tr_y;

		for (int x = bl_x; x < tr_x; ++x)
		{
			for (int y = bl_y; y < tr_y; ++y)
			{
				visited[y][x] = 1;
			}
		}
	}

	/*
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cout << visited[i][j] << " ";
		}
		cout << '\n';
	}
	*/

	int outterCount = 0;
	std::vector<int> innerCountArr;

	for (int y = 0; y < M; ++y)
	{
		for (int x = 0; x < N; ++x)
		{
			Position curPos(x, y);
			if (!visited[curPos.y][curPos.x])
			{
				innerCountArr.push_back(BFS(curPos));
				outterCount++;
			}
		}
	}

	cout << outterCount << '\n';

	std::sort(innerCountArr.begin(), innerCountArr.end());

	for (const auto count : innerCountArr)
		cout << count << " ";

	return 0;
}