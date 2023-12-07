#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <algorithm>

using std::cin;
using std::cout;

bool compare(std::pair<int, int> a, std::pair<int, int> b)
{
	if (a.first == b.first)
		return a.second > b.second;

	return a.first < b.first;
}

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : 마인크래프트

	// N x M x B = 500 x 500 x 256 = 64,000,500 (약 6천만)
	// 1초에 약 1억번 연산이 가능하므로, 위와 같이 모든 경우를 탐색하는 "브루트 포스" 알고리즘을 사용할 수 있다.

	int N, M, B;
	cin >> N >> M >> B;

	std::vector<std::vector<int>> height(N);
	for (auto& vec : height)
		vec.resize(M);

	// 지형 생성
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			int landHeight; cin >> landHeight;
			height[i][j] = landHeight;
		}
	}

	// 지형을 평평하게 만들자

	const int rowCount = N;
	const int columnCount = M;

	int minElapsedTime = INT32_MAX;
	int resultHeight = 0;

	// 0층부터 256층까지 돌면서 각 층에서의 필요한 블럭 개수가 가장 최소인 곳이 타겟 층이다.
	for (int targetHeight = 0; targetHeight <= 256; ++targetHeight)
	{
		int elapsedTime = 0;
		int removeCount = 0;
		int addCount = 0;

		// 해당 층에 대해서 추가 / 제거가 필요한 블럭의 수를 계산
		for (int i = 0; i < rowCount; ++i)
		{
			for (int j = 0; j < columnCount; ++j)
			{
				// 제거가 필요함
				if (height[i][j] - targetHeight > 0)
					removeCount += height[i][j] - targetHeight;
				// 추가가 필요함
				else
					addCount += targetHeight - height[i][j];
			}
		}

		// 블럭이 부족하면 안된다.
		if (addCount > removeCount + B)
			continue;

		// 시간 비용 계산
		// 이렇게 한번에 몰아서 시간을 계산할 수 있다.
		// * remove와 add 작업을 실시간으로 하지 않아도 된다. 마지막에 한번만 *
		elapsedTime += removeCount * 2 + addCount * 1;

		// 최소 비용인지 판단
		if (minElapsedTime >= elapsedTime)
		{
			minElapsedTime = elapsedTime;
			resultHeight = targetHeight;
		}
	}

	cout << minElapsedTime << " " << resultHeight << '\n';

	return 0;
}
