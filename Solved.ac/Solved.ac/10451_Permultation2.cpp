#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int graph[1001];
bool alreadyDone[1001];

void dfs(int node)
{
	// 이미 탐색 했으면
	if(!alreadyDone[node])
	{
		alreadyDone[node] = true;

		int nextNode = graph[node];
		dfs(nextNode);
	}

	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// 순열 사이클 개수 구하기

	/*
	 * T : 테스트 케이스 개수
	 * N : 순열의 크기
	 */

	int T; cin >> T;

	// 테스트 케이스
	while (T > 0)
	{
		T--;

		// 초기화
		for (int i = 1; i <= 1000; ++i)
			graph[i] = 0;
		for (int i = 1; i <= 1000; ++i)
			alreadyDone[i] = false;

		// 노드 개수
		int N; cin >> N;

		// 방향 그래프 생성
		for (int i = 1; i <= N; ++i)
			cin >> graph[i];

		int cycleCnt = 0;

		// 각각의 사이클을 확인
		for (int i = 1; i <= N; ++i)
		{
			// 아직 사용되지 않은 노드로 들어가 해당 사이클을 탐색한다.
			if (alreadyDone[i] == false)
			{
				dfs(i);
				cycleCnt++;
			}
		}

		cout << cycleCnt << endl;
	}
}