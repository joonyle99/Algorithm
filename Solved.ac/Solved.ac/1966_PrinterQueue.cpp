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

	// Title : 프린터 큐

	int T; cin >> T;

	while (T-- > 0)
	{
		// N : 문서의 개수
		// M : 뭐가 놓여있는지 궁금한 위치 (0은 맨 왼쪽)
		int N, M;
		cin >> N >> M;

		std::queue<std::pair<int, int>> myQueue;

		for (int i = 0; i < N; ++i)
		{
			// 1 ~ 9의 중요도
			int priority; cin >> priority;
			myQueue.emplace(i, priority);
		}

		int order = 0;

		while (!myQueue.empty())
		{
			std::queue<std::pair<int, int>> tempQueue = myQueue;

			auto myElement = myQueue.front();

			// 우선순위가 제일 높아서 그냥 뺄 수 있든 뒤로 넘가야하든 우선 Pop을 한다
			myQueue.pop();

			// 뒤로 넣을지 여부
			bool isPush = false;

			// 뒤에 나보다 중요도가 높은 문서가 있는지 확인하기
			while (!tempQueue.empty())
			{
				// 나보다 우선순위 높은 경우
				if (myElement.second < tempQueue.front().second)
				{
					// 뒤로 다시 넣는다.
					isPush = true;
					break;
				}
				// 다음 요소와 비교를 위한 Pop
				else
					tempQueue.pop();
			}

			if (isPush)
				myQueue.push(myElement);
			else
			{
				order++;

				if (myElement.first == M)
				{
					cout << order << '\n';
					break;
				}
			}
		}
	}


	return 0;
}
