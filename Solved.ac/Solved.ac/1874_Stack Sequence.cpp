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

	std::string result;

	// 여기서 큐는 내가 입력한 순서대로 나오기 위해 사용한 자료구조
	std::queue<int> myQueue;
	for (int i = 0; i < n; ++i)
	{
		int value; cin >> value;
		myQueue.push(value);
	}

	// 스택 수열을 구현하기 위해 사용한 자료구조
	std::stack<int> myStack;
	for (int value = 1; value <= n; ++value)
	{
		// 우선 오름차순으로 스택에 값을 넣는다
		myStack.push(value);
		result += '+';
		result += '\n';

		// 스택(앞으로 사용할 값들)과 큐(수열의 값)가 비어있지 않으면서 상단의 값이 일치해야함
		while(!myStack.empty() && !myQueue.empty() && (myStack.top() == myQueue.front()))
		{
			myStack.pop();
			myQueue.pop();
			result += '-';
			result += '\n';
		}
	}

	// 스택 자료구조로 주어진 수열을 만들지 못했다는 의미
	if (!myQueue.empty())
		cout << "NO" << '\n';
	else
		cout << result;

	return 0;
}
