#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <algorithm>

using std::cin;
using std::cout;

int Walk(int x, int dir)
{
	x += dir;
	return x;
}

int Teleport(int x)
{
	x *= 2;
	return x;
}

int BFS(int subin, int sister)
{
	std::queue<std::pair<int, int>> myQueue;
	bool visited[100001] = { false, };

	myQueue.push(std::make_pair(subin, 0));
	visited[subin] = true;

	while (!myQueue.empty())
	{
		auto prevInfo = myQueue.front();
		myQueue.pop();

		// 목표 지점에 도달했다면 걸린 시간을 리턴
		if (prevInfo.first == sister)
			return prevInfo.second;

		// 3가지 이동 상황을 계산

		int rightResult = Walk(prevInfo.first, 1);
		if (rightResult <= 100000 && rightResult >= 0)
		{
			if (!visited[rightResult])
			{
				myQueue.push(std::make_pair(rightResult, prevInfo.second + 1));
				visited[rightResult] = true;
			}
		}

		int leftResult = Walk(prevInfo.first, -1);
		if (leftResult <= 100000 && leftResult >= 0)
		{
			if (!visited[leftResult])
			{
				myQueue.push(std::make_pair(leftResult, prevInfo.second + 1));
				visited[leftResult] = true;
			}
		}

		int teleportResult = Teleport(prevInfo.first);
		if (teleportResult <= 100000 && teleportResult >= 0)
		{
			if (!visited[teleportResult])
			{
				myQueue.push(std::make_pair(teleportResult, prevInfo.second + 1));
				visited[teleportResult] = true;
			}
		}
	}

	return 0;
}

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : 숨바꼭질

	int N; cin >> N;
	int K; cin >> K;

	int result = BFS(N, K);
	cout << result << '\n';

	return 0;
}
