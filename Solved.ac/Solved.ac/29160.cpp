#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define POSITION_COUNT 11

struct PlayerByPos
{
	int number;
	int worth;

	PlayerByPos() = default;
	PlayerByPos(int n, int w)
		: number(n), worth(w)
	{}
};

bool MaxWorth(const PlayerByPos& a, const PlayerByPos& b)
{
	if (a.worth < b.worth)
		return true;

	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// N : 선수의 수
	// K : after year
	int N, K;
	cin >> N >> K;

	vector<vector<PlayerByPos>> playersByPos(POSITION_COUNT);

	int teamWorth = 0;

	// 0. 팀은 총 11명으로, 포지션 번호는 1이상 11이하인 정수이다.
	for (int playerNum = 1; playerNum <= N; ++playerNum)
	{
		int p, w;
		cin >> p >> w;

		playersByPos[p - 1].push_back(PlayerByPos(playerNum, w));
	}

	bool isOverNov = false;
	bool isOverAug = false;
	bool isOverK = false;

	// K년의 경과
	while (K > 0)
	{
		// 1. 3월에 포지션별 선수 가치가 가장 높은 선수를 선발
		for (int positionNum = 0; positionNum < POSITION_COUNT; ++positionNum)
		{
			// 2. 포지션에 해당하는 선수가 없을 시, 해당 포지션을 공석으로 팀을 구성
			if (!playersByPos[positionNum].empty())
			{
				// 선수 가치가 가장 높은 선수 선발
				auto max_it = std::max_element(playersByPos[positionNum].begin(), playersByPos[positionNum].end(), MaxWorth);

				// 가치가 가장 높은 선수의 번호 구하기
				if (max_it != playersByPos[positionNum].end())
				{
					auto index = std::distance(playersByPos[positionNum].begin(), max_it);

					// 3. 8월에 선발 선수의 선수 가치는 -1 (>= 0)
					if (!isOverAug && !isOverNov && !isOverK)
					{
						if (playersByPos[positionNum][index].worth > 0)
							playersByPos[positionNum][index].worth--;
					}
					// 5. K년 12월에 선수 가치 합 출력
					else if (isOverAug && isOverNov && isOverK)
					{
						teamWorth += playersByPos[positionNum][index].worth;
					}
				}
			}
		}

		// 4. 11월에 1의 조건으로 재구성
		if (!isOverNov)
		{
			// 8월이 지남
			isOverAug = true;

			// 11월이 지남
			isOverNov = true;

			// 마지막 해인 경우에
			if (K == 1)
				isOverK = true;

			continue;
		}

		isOverNov = false;
		isOverAug = false;

		K--;
	}

	cout << teamWorth << endl;

	return 0;
}