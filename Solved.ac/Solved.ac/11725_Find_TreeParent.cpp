#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <algorithm>

using std::cin;
using std::cout;

int N;

// 인접 리스트 방식
std::vector<std::vector<int>> tree;

bool visited[100001] = {};

std::vector<int> parentArr;

void DFS(int parentNumber)
{
	visited[parentNumber] = true;

	for (int i = 0; i < tree[parentNumber].size(); ++i)
	{
		int child = tree[parentNumber][i];

		if (!visited[child])
		{
			DFS(child);
			parentArr[child] = parentNumber;
		}
	}
}

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : 트리의 부모 찾기

	cin >> N;

	tree.resize(N + 1);
	parentArr.resize(N + 1);

	// 연결 정보만 주어진다.
	for (int i = 0; i < N - 1; ++i)
	{
		int from, to;
		cin >> from >> to;

		tree[from].push_back(to);
		tree[to].push_back(from);
	}

	/// 미쳤다.. 루트 노드에서 시작하면 되는구나..
	DFS(1);

	// 첫째 줄부터 N-1개의 줄에 각 노드의 부모 노드 번호를 2번 노드부터 순서대로 출력한다.
	for (int i = 2; i < parentArr.size(); ++i)
		cout << parentArr[i] << '\n';

	return 0;
}
