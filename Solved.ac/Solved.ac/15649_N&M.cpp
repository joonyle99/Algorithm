#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <algorithm>

using std::cin;
using std::cout;

int N, M;

std::vector<int> inputArray;
std::vector<bool> visited;

void DFS(int number, std::vector<int> numVector)
{
	numVector.push_back(number);

	auto cnt = numVector.size();

	if (cnt == M)
	{
		for (int i = 0; i < cnt; ++i)
		{
			if (i == cnt - 1)
				cout << numVector[i] << '\n';
			else
				cout << numVector[i] << " ";
		}

		return;
	}

	for (int i = 1; i <= N; ++i)
	{
		if (!visited[i])
		{
			visited[i] = true;
			DFS(i, numVector);
			visited[i] = false;
		}
	}
}

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : N과 M (1)
	// Sorting : 백 트래킹
	// 1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열

	cin >> N >> M;

	inputArray.resize(N + 1);
	visited.resize(N + 1);

	for (int i = 1; i <= N; ++i)
		inputArray[i] = i;

	for (int i = 1; i <= N; ++i)
	{
		std::vector<int> numVector;
		visited[i] = true;
		DFS(i, numVector);
		visited[i] = false;
	}

	return 0;
}