#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 하나 하나 타고 들어간다.
void DFS(int node, std::vector<int>& numberArr, std::vector<int>& alreadyDone)
{
	auto it = std::find(alreadyDone.begin(), alreadyDone.end(), node);

	// 하나의 사이클 종료
	if (it != alreadyDone.end())
		return;
	else
		alreadyDone.push_back(node);

	DFS(numberArr[node], numberArr, alreadyDone);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// 순열 사이클 개수 구하기

	/*
	 * T : 테스트 케이스 개수
	 * N : 순열의 크기
	 */

	int T; cin >> T;

	// 테스트 케이스
	for (int i = 0; i < T; ++i)
	{
		int N; cin >> N;

		int cnt = 0;

		std::vector<int> numberArr(N + 1);
		std::vector<int> already_done;

		// 방향 그래프 생성
		for (int j = 1; j <= N; ++j)
		{
			int value; cin >> value;
			numberArr[j] = value;
		}

		// 아직 돌지 않은 사이클을 돈다.
		for (int j = 1; j <= N; ++j)
		{
			auto it = std::find(already_done.begin(), already_done.end(), j);
			if (it != already_done.end())
				continue;
			else
			{
				// 하나 하나 타고 들어간다
				DFS(j, numberArr, already_done);
				cnt++;
			}
		}

		cout << cnt << endl;
	}

	return 0;
}