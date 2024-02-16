#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <algorithm>

using std::cin;
using std::cout;

int length, m;

// 지도
int map[500][500] = {};

// 방문 정보
bool visited[500][500] = {};

// 상 하 좌 우
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

int BFS(int startY, int startX)
{
	std::queue<std::pair<int, int>> myQueue;
	visited[startY][startX] = true;
	myQueue.emplace(startX, startY);
	int innerCount = 1;

	while (!myQueue.empty())
	{
		auto front = myQueue.front();
		myQueue.pop();

		// [상 하 좌 우] 탐색
		for (int i = 0; i < 4; ++i)
		{
			// 다음 위치
			std::pair<int, int> nextPos(front.first + dx[i], front.second + dy[i]);

			// 지도를 넘어가면 다시 탐색
			if (nextPos.first < 0 || nextPos.second < 0 || nextPos.first > m - 1 || nextPos.second > length - 1)
				continue;

			// 방문 정보와 지도 정보를 가지고 탐색 결정
			if (!visited[nextPos.second][nextPos.first] && map[nextPos.second][nextPos.first] == 1)
			{
				visited[nextPos.second][nextPos.first] = true;
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

	// Title : 그림

	cin >> length >> m;

	int maxInnerCount = 0;
	int outterCount = 0;

	// 지도 세팅
	for (int i = 0; i < length; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> map[i][j];
		}
	}

	// 모든 지도를 돌면서 BFS 탐색
	for (int i = 0; i < length; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			// 방문 정보와 지도 정보를 가지고 탐색 결정
			if (!visited[i][j] && map[i][j] == 1)
			{
				maxInnerCount = std::max(maxInnerCount, BFS(i, j));
				outterCount++;
			}
		}
	}

	cout << outterCount << '\n';
	cout << maxInnerCount << '\n';


	return 0;
}
