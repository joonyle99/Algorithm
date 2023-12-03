#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <algorithm>

using std::cin;
using std::cout;

std::vector<std::vector<int>> vecArr;
std::vector<bool> visited;

void ResetVisited()
{
	for (int i = 0; i < visited.size(); ++i)
		visited[i] = false;
}

// user에서 target까지 최소 connect count 구하기
int GetMinConnectEachPerson(int start, int target)
{
	int count = 0;

	// 이 문제에서의 핵심 포인트 : Queue에 (사람 번호)와 (거쳐온 횟수)를 함께 가지고 있도록 한다.
	std::queue<std::pair<int, int>> myQueue;
	myQueue.push(std::make_pair(start, 0));
	visited[start] = true;

	while (!myQueue.empty())
	{
		const auto fromInfo = myQueue.front();
		myQueue.pop();

		// 친구 중에 타겟이 있다면 그때의 거쳐온 횟수를 가지고 리턴한다.
		if (fromInfo.first == target)
		{
			count = fromInfo.second;
			break;
		}

		for (int i = 0; i < vecArr[fromInfo.first].size(); ++i)
		{
			int myFriend = vecArr[fromInfo.first][i];

			if (!visited[myFriend])
			{
				myQueue.push(std::make_pair(myFriend, fromInfo.second + 1));
				visited[myFriend] = true;
			}
		}
	}

	return count;
}

// 해당 유저의 베이컨 넘버를 알아내는 함수
int GetKevinBaconNumber(int user)
{
	int kevinBaconNumber = 0;

	for (int target = 1; target <= vecArr.size(); ++target)
	{
		if (user == target)
			continue;

		kevinBaconNumber += GetMinConnectEachPerson(user, target);
		ResetVisited();
	}

	return kevinBaconNumber;
}

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// 케빈 베이컨 문제

	int N; cin >> N;
	int M; cin >> M;

	vecArr.resize(N + 1);
	visited.resize(N + 1);

	while (M-- > 0)
	{
		int from; cin >> from;
		int to; cin >> to;

		if (from == to)
			continue;

		vecArr[from].push_back(to);
		vecArr[to].push_back(from);
	}

	int minKevin = 9999999999;
	int personNumber = 0;

	for (int user = 1; user <= N; ++user)
	{
		int kevinBaconNumber = GetKevinBaconNumber(user);
		if (minKevin > kevinBaconNumber)
		{
			minKevin = kevinBaconNumber;
			personNumber = user;
		}
	}

	cout << personNumber << '\n';

	return 0;
}
