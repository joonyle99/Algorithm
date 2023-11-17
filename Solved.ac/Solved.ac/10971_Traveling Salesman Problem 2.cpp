#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N;
int w[11][11];
bool v[11];

int minCost = 1000000 * 10;

void BFS(int start)
{
	// 이 지점에서 모든 경로를 다 돌면서 최단 경로를 탐색한다.
	std::queue<int> myQueue;

	// 시작 지점을 Queue에 넣고 시작
	myQueue.push(start);
	v[start] = true;

	// Queue에 아무 값도 남지 않을때까지 반복 실행
	while (!myQueue.empty())
	{
		// 해당 지점에서 이어진 모든 경로를 하나하나 탐색
		for (int i = 1; i <= N; ++i)
		{
			// 방문하지 않은 지점이라면
			if (v[i] == false && w[myQueue.front()][i] != 0)
			{
				// Queue에 넣고
				myQueue.push(i);

				// 비용 계산을 누적한다.
				// myQueue.front()
			}
		}

		myQueue.pop();
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// 외판원 순회 2

	cin >> N;

	// 비용 그래프 생성
	// index 0은 제외하고 생성한다.
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			int cost; cin >> cost;

			w[i][j] = cost;
		}
	}

	// 가장 적은 비욜으로 순회 여행 하는법
	// 한 도시에서 N개의 모든 도시를 거쳐 다시 원래의 도시로 돌아오는 방법

	// 1. 어느 도시에서 출발할지
	// 2. 어떤 경로로 순회할지

	// 이 두개를 모두 고려해서 순회하고, 그 중 최단 경로를 찾아야 한다.

	// 1)
	for (int i = 1; i <= N; ++i)
	{
		// 2)
		BFS(i);
	}


	for (int i = 1; i <= N; ++i)
	{
		cout << i << " : ";
		for (int j = 1; j <= N; ++j)
		{
			cout << w[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}