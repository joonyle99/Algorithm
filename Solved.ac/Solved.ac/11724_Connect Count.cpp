#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 무방향 그래프는 2차원 배열에 담아야 한다.
std::vector<std::vector<int>> graphs;

// 방문처리를 위한 변수 선언
bool visited[1001] = { false, };

void DFS(int node)
{
	if (visited[node] == false)
	{
		// 방문 처리
		visited[node] = true;

		for (int i = 0; i < graphs[node].size(); ++i)
		{
			DFS(graphs[node][i]);
		}
	}

	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// 연결 요소의 개수

	int N; cin >> N;
	int M; cin >> M;

	// 연결 요소의 개수를 담는 변수 선언
	int cnt = 0;

	graphs.resize(N + 1);

	// 무방향 그래프 생성
	for (int i = 0; i < M; ++i)
	{
		int u; cin >> u;
		int v; cin >> v;

		graphs[u].push_back(v);
		graphs[v].push_back(u);
	}

	// 순환하는 사이클의 개수 (연결 요소) 구하기
	for (int i = 1; i <= N; ++i)
	{
		// 방문하지 않았으면 탐색
		if (visited[i] == false)
		{
			// 각 연결 요소에 들어가서 탐색
			DFS(i);

			// 해당 연결 요소의 탐색이 종료되면 연결 요소 카운트 증가
			cnt++;
		}
		// 방문했으면 다음 연결 요소를 찾기
		else
			continue;
	}

	cout << cnt << endl;

	/*
	 * 2차원 벡터의 요소를 출력하는 코드
	for (int i = 1; i <= N; ++i)
	{
		cout << "index " << i << " : ";

		for (int j = 0; j < graphs[i].size(); ++j)
		{
			cout << graphs[i][j] << " ";
		}

		cout << endl;
	}
	*/

	return 0;
}