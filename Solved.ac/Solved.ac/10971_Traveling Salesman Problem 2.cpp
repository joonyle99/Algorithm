#include <iostream>
#include <algorithm>

using namespace std;

int N;
int graph[11][11];
bool visited[11];

int minCost = 1000000 * 10 + 1;

void BFS(int startNode, int curNode, int remainCnt, int curCost)
{
	// 다 돌고 돌아가는 일만 남았을 때
	if (remainCnt == 0)
	{
		// 최종적으로 돌아가는 비용 더하기
		if (graph[curNode][startNode] != 0)
			minCost = std::min(curCost + graph[curNode][startNode], minCost);

		return;
	}

	// startNode에서 cnt개의 노드를 탐색하고, 최소 비용을 구한다.
	for (int nextNode = 1; nextNode <= N; ++nextNode)
	{
		// 갈 수 있는 곳이고, 방문한적이 없는 경우
		if (graph[curNode][nextNode] != 0 && visited[nextNode] == false && curCost < minCost)
		{
			visited[nextNode] = true; // 방문처리.

			BFS(startNode, nextNode, remainCnt - 1, curCost + graph[curNode][nextNode]);

			visited[nextNode] = false; // 끝까지 들어갔다 나왔으므로, 방문처리를 철회한다.
		}
		else
			continue;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// 외판원 순회 2

	cin >> N;

	// 그래프 생성
	// index 0은 제외하고 생성한다.
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			int cost; cin >> cost;
			graph[i][j] = cost;
		}
	}

	// 가장 적은 비욜으로 순회 여행 하는법
	// 한 도시에서 N개의 모든 도시를 거쳐 다시 원래의 도시로 돌아오는 방법

	// 1. 어느 도시에서 출발할지
	// 2. 어떤 경로로 순회할지

	// 이 두개를 모두 고려해서 순회하고, 그 중 최단 경로를 찾아야 한다.

	int finalMinCost = 1000000 * 10 + 1;
	for (int i = 1; i <= N; ++i)
	{
		visited[i] = true;

		BFS(i, i, N - 1, 0);

		// 방문정보 초기화
		// std::memset(visited, false, sizeof(visited));
		std::fill(std::begin(visited), std::end(visited), false);

		// 최종 최소 비용 계산
		finalMinCost = std::min(finalMinCost, minCost);
	}

	cout << finalMinCost << endl;

	return 0;
}