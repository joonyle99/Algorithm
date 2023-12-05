#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <algorithm>
#include <string>

using std::cin;
using std::cout;
using std::string;

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : ±ÕÇüÀâÈù ¼¼»ó

	while (true)
	{
		string inputString;
		bool isYes = true;

		char ch;
		while (std::cin.get(ch) && ch != '\n') {
			inputString.push_back(ch);
		}

		if (inputString == ".")
			break;

		const size_t length = inputString.length() - 1;

		std::stack<int> myStack;
		for (size_t i = 0; i < length; ++i)
		{
			const char ch = inputString[i];

			if (ch == '(' || ch == '[')
				myStack.push(ch);

			if (ch == ')')
			{
				// no
				if (myStack.empty())
				{
					isYes = false;
					break;
				}
				else
				{
					if ('(' == myStack.top())
						myStack.pop();
					else
					{
						isYes = false;
						break;
					}
				}
			}
			else if (ch == ']')
			{
				// no
				if (myStack.empty())
				{
					isYes = false;
					break;
				}
				else
				{
					if ('[' == myStack.top())
						myStack.pop();
					else
					{
						isYes = false;
						break;
					}
				}
			}
		}

		if (myStack.empty() && isYes)
			cout << "yes" << '\n';
		else if (!myStack.empty() || !isYes)
			cout << "no" << '\n';
	}

	return 0;
}
