#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

#define POSITION_COUNT 11

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// N : 선수의 수
	// K : after year
	int N, K;
	cin >> N >> K;

	// 0번 인덱스는 사용하지 않음
	vector<vector<size_t>> players(POSITION_COUNT + 1);

	// 0. 팀은 총 11명으로, 포지션 번호는 1이상 11이하인 정수이다.
	for (size_t i = 0; i < N; ++i)
	{
		int P, W;
		cin >> P >> W;

		players[P].push_back(W);
	}

	// 1. 포지션 별로 선수 가치에 따라 내림차순 정렬
	for (size_t i = 1; i <= POSITION_COUNT; ++i)
	{
		sort(players[i].begin(), players[i].end(), greater<size_t>());
	}

	while (K > 0)
	{
		// 2. 3월에 포지션별 선수 가치가 가장 높은 선수를 선발
		for (size_t i = 1; i <= POSITION_COUNT; ++i)
		{
			if (!players[i].empty())
			{
				// 3. 8월에 선발 선수의 선수 가치는 -1 (>= 0)
				if (players[i][0] > 0)
				{
					players[i][0]--;

					// 4. 11월에 2의 조건으로 재구성
					for (size_t j = 1; j < players[i].size(); ++j)
					{
						if (players[i][j] < players[i][0])
						{
							swap(players[i][0], players[i][j - 1]);
							break;
						}
					}
				}
			}
		}

		K--;
	}

	size_t teamWorth = 0;

	for (size_t i = 1; i <= POSITION_COUNT; ++i)
	{
		if (!players[i].empty())
		{
			teamWorth += players[i][0];
		}
	}

	cout << teamWorth << '\n';

	return 0;
}