#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <algorithm>

using std::cin;
using std::cout;

int M, N, K;

// 밭 생성
int map[50][50] = {};

// 방문 정보
bool visited_J[50][50] = {};

// 상 하 좌 우
int deltaCol[4] = { 0,0,-1,1 };
int deltaRow[4] = { -1,1,0,0 };

void Reset()
{
	for (int i = 0; i < 50; ++i)
	{
		for (int j = 0; j < 50; ++j)
		{
			map[i][j] = 0;
			visited_J[i][j] = false;
		}
	}
}

int BFS(int startY, int startX)
{
	std::queue<std::pair<int, int>> myQueue;
	visited_J[startY][startX] = true;
	myQueue.emplace(startX, startY);
	int cabbageCount = 1;

	while (!myQueue.empty())
	{
		auto front = myQueue.front();
		myQueue.pop();

		for (int i = 0; i < 4; ++i)
		{
			std::pair<int, int> nextPos(front.first + deltaCol[i], front.second + deltaRow[i]);

			if (nextPos.first < 0 || nextPos.second < 0 || nextPos.first > M - 1 || nextPos.second > N - 1)
				continue;

			// 배추가 있고 방문한적이 없다면
			if (!visited_J[nextPos.second][nextPos.first] && map[nextPos.second][nextPos.first] == 1)
			{
				visited_J[nextPos.second][nextPos.first] = true;
				myQueue.push(nextPos);
				cabbageCount++;
			}
		}
	}

	return cabbageCount;
}

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : 유기농 배추

	int T; cin >> T;

	while (T-- > 0)
	{
		cin >> M >> N >> K;

		int earthwormCount = 0;

		// 밭에 배추 심기
		while (K-- > 0)
		{
			int X, Y;
			cin >> X >> Y;

			map[Y][X] = 1;
		}

		// 최소의 배추흰지렁이 개수 구하기
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				// 배추가 있고 방문한적이 없다면
				if (!visited_J[i][j] && map[i][j] == 1)
				{
					BFS(i, j);
					earthwormCount++;
				}
			}
		}

		// map / visited 초기화
		Reset();

		cout << earthwormCount << '\n';
	}


	return 0;
}
