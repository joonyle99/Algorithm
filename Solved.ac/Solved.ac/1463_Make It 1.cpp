#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <algorithm>

using std::cin;
using std::cout;

int BFS(int number)
{
	int result = 0;

	std::queue<std::pair<int, int>> myQueue;
	myQueue.emplace(number, 0);

	while (!myQueue.empty())
	{
		auto front = myQueue.front();
		int frontNumber = front.first;
		int frontCount = front.second;

		if (frontNumber == 1)
		{
			result = frontCount;
			break;
		}

		myQueue.pop();

		if (frontNumber % 3 == 0)
			myQueue.emplace(frontNumber / 3, frontCount + 1);

		if (frontNumber % 2 == 0)
			myQueue.emplace(frontNumber / 2, frontCount + 1);

		myQueue.emplace(frontNumber - 1, frontCount + 1);
	}

	return result;
}

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : 1로 만들기

	// Tag : BFS (Breadth First Search)

	int N; cin >> N;

	cout << BFS(N) << '\n';

	return 0;
}
