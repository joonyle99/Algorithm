#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <algorithm>

using std::cin;
using std::cout;

// 인접 리스트 방식
std::vector<std::vector<int>> reverseTrustList;

// 방문 정보
bool visited[10001] = {};

// 해킹 가능 횟수
int hackingCount = 0;

// 최대 해킹 가능 횟수
int maxHackingCount = 0;

void DFS(int startNumber, int curNumber)
{
	// 자신을 신뢰하는 모든 컴퓨터를 "동시에" 해킹할 수 있다.
	hackingCount++;

	// 자신을 신뢰하는 모든 컴퓨터를 모두 순회
	for (int i = 0; i < reverseTrustList[curNumber].size(); ++i)
	{
		int targetNumber = reverseTrustList[curNumber][i];

		if (!visited[targetNumber])
		{
			visited[targetNumber] = true;
			DFS(startNumber, targetNumber);
			visited[targetNumber] = false;
		}
	}
}

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : 효율적인 해킹

	/*
	 * N : 컴퓨터 번호 개수
	 * M : 신뢰 개수
	 */

	/// 처음에 문제를 잘못 이해했다.
	///	자신을 신뢰하는 컴퓨터 중 하나만 해킹할 수 있다고 생각해 버린 것
	///	자신을 신뢰하는 모든 컴퓨터를 동시에 해킹할 수 있었다.

	int N, M;
	cin >> N >> M;

	// 인접행렬은 용량 초과로 사용 불가
	// int reverseTrustList[10001][10001];

	reverseTrustList.resize(N + 1);

	for (int i = 0; i < M; ++i)
	{
		int from, to;
		cin >> from >> to;

		reverseTrustList[to].push_back(from);
	}

	// 최대 해킹 가능한 컴퓨터 배열
	std::vector<int> computerArr;

	for (int i = 1; i <= N; ++i)
	{
		if (reverseTrustList[i].empty())
			continue;

		visited[i] = true;
		DFS(i, i);
		visited[i] = false;

		if(maxHackingCount <= hackingCount)
		{
			maxHackingCount = hackingCount;
			computerArr.emplace_back(i);
		}

		hackingCount = 0;
	}

	std::sort(computerArr.begin(), computerArr.end());

	for (const auto v : computerArr)
		cout << v << " ";

	return 0;
}
