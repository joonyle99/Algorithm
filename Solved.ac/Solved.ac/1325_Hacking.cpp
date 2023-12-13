#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;

// 인접 리스트 방식
std::vector<std::vector<int>> reverseTrustList;

// 방문 정보
bool visited[10001] = {};

// 해킹 가능 횟수
int hackingCount = 0;

// second(해킹 횟수)는 큰 순서대로, first(컴퓨터 번호)는 작은 순서대로
bool compare(std::pair<int, int> a, std::pair<int, int> b)
{
	if (a.second == b.second)
		return a.first < b.first;

	return a.second > b.second;
}

void ResetVisited()
{
	for(int i=0; i<10001; ++i)
		visited[i] = false;
}

void DFS(int parentNumber)
{
	// targetNumber를 방문처리
	visited[parentNumber] = true;

	// 자신을 신뢰하는 모든 컴퓨터를 "동시에" 해킹할 수 있다.
	hackingCount++;

	// 자신을 신뢰하는 모든 컴퓨터를 모두 순회
	for (int i = 0; i < reverseTrustList[parentNumber].size(); ++i)
	{
		int targetNumber = reverseTrustList[parentNumber][i];

		if (!visited[targetNumber])
			DFS(targetNumber);
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
	std::vector<std::pair<int, int>> computerArr;

	for (int i = 1; i <= N; ++i)
	{
		// i번 컴퓨터를 해킹
		DFS(i);

		// 방문 정보 초기화
		ResetVisited();

		// i번 컴퓨터와 해당 컴퓨터에 대한 해킹 카운트를 배열에 추가
		computerArr.emplace_back(i, hackingCount);

		hackingCount = 0;
	}

	std::sort(computerArr.begin(), computerArr.end(), compare);

	int maxHackingCount = computerArr[0].second;

	for (const auto v : computerArr)
	{
		if (v.second != maxHackingCount)
			break;

		cout << v.first << " ";
	}

	return 0;
}
