#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

std::vector<std::vector<int>> graphVec;
int visited[101];
int finalDepth = -1;

void DFS(int t1, int t2, int depth)
{
	if (t1 == t2)
	{
		finalDepth = depth;
		return;
	}

	for (int i = 0; i < graphVec[t1].size(); ++i)
	{
		if (visited[graphVec[t1][i]] == false)
		{
			visited[graphVec[t1][i]] = true;
			DFS(graphVec[t1][i], t2, depth + 1);
			visited[graphVec[t1][i]] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// 촌수 계산

	/*
	 * 각각의 사람에게 번호가 부여된다
	 * n : 전체 사람의 수
	 * t1, t2 : 촌수를 계산할 두 대상
	 * m : 부모 자식들 간의 관계의 개수
	 * x : 부모를 나타내는 번호
	 * y : x의 자식을 나타내는 번호
	 */

	int n; cin >> n;

	graphVec.resize(n + 1);

	int t1; cin >> t1;
	int t2; cin >> t2;

	int m; cin >> m;

	while (m > 0)
	{
		m--;

		int x; cin >> x;
		int y; cin >> y;

		graphVec[x].push_back(y);
		graphVec[y].push_back(x);
	}

	// 촌수 계산
	// t1과 t2의 공통 부모를 찾고
	// t1에서 t2를 찾으러 가는 최단 경로를 찾는다.
	int depth = 0;
	visited[t1] = true;
	DFS(t1, t2, depth);

	cout << finalDepth << endl;

	/*
	for (int i = 1; i < graphVec.size(); ++i)
	{
		cout << i << " : ";
		for (int j = 0; j < graphVec[i].size(); ++j)
		{
			cout << graphVec[i][j] << " ";
		}
		cout << endl;
	}
	*/

	return 0;
}