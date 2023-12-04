#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <algorithm>

using std::cin;
using std::cout;

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : 스택 수열

	int n; cin >> n;

	// Stack으로 수열 만들기
	// 4 3 6 8 7 5 2 1

	std::queue<int> myQueue;
	for (int i = 0; i < n; ++i)
	{
		int value; cin >> value;
		myQueue.push(value);
	}

	std::stack<int> myStack;
	int value = 1;
	while (!myQueue.empty())
	{
		if (value == myQueue.front())
		{
			myStack.pop();
			myQueue.pop();
			cout << '-' << '\n';
			continue;
		}

		myStack.push(value);
		cout << '+' << '\n';

		value++;
	}

	return 0;
}
