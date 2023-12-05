#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <algorithm>
#include <string>

using std::cin;
using std::cout;

std::string GetStringFromStack(std::stack<char>& myStack)
{
	std::string tempString;

	// 스택에 있는 모든 문자를 빼낸다 (뒤집힌 문자열)
	while (!myStack.empty())
	{
		tempString += myStack.top();
		myStack.pop();
	}

	return tempString;
}

std::string ReverseString(std::string inputString)
{
	size_t length = inputString.length();
	for (int i = 0; i < length / 2; ++i)
		std::swap(inputString[i], inputString[length - 1 - i]);

	return inputString;
}

std::string Solution(const std::string& inputString)
{
	const size_t length = inputString.length();
	std::string resultString;
	bool isTag = false;

	// 하나의 스택에서 문자들을 넣고 빼고 관리한다
	std::stack<char> myStack;

	// inputString을 모두 읽는다
	for (size_t i = 0; i < length; ++i)
	{
		// 하나의 문자
		char ch = inputString[i];

		// 단어인 경우
		if (!isTag)
		{
			// ' '이 아닌 다른 문자라면 스택에 넣는다
			if (ch != ' ')
			{
				// '<'이 나온다면 단어의 끝. 그리고 다음에 태그가 나온다는 뜻
				if (ch == '<')
				{
					isTag = true;

					// '<'을 첫 문자에서 만난 게 아니라면 단어의 종료를 뜻함
					if (i != 0)
						resultString += GetStringFromStack(myStack);
				}

				myStack.push(ch);
			}
			// ' '이 나온다면 단어의 끝. 그리고 다음에 단어가 또다시 나온다는 뜻
			else if (ch == ' ')
			{
				resultString += GetStringFromStack(myStack);
				resultString += ' ';
			}

			// 단어의 경우 마지막 문자까지 도착했는데, ' '을 만나지 못하기 때문에 직접 종료시킨다.
			if (i == length - 1)
			{
				resultString += GetStringFromStack(myStack);
				break;
			}
		}
		// 태그인 경우
		else
		{
			// 무조건 스택에 넣는다.
			myStack.push(ch);

			// 태그의 끝을 알리는 '>'를 만나면
			if (ch == '>')
			{
				// 태그를 전부 임시 문자열에 넣고 다시 뒤집어줌
				const std::string temp = GetStringFromStack(myStack);
				resultString += ReverseString(temp);

				isTag = false;
			}
		}
	}

	return resultString;
}

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : 단어 뒤집기 2 - 스택으로 해결

	std::string str;
	std::getline(cin, str);

	cout << Solution(str) << '\n';

	return 0;
}
