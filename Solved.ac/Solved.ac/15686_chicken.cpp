#include <bits/stdc++.h>
using namespace std;

int N, M;
int city[55][55];
bool closed[55][55];
vector<pair<int, int>> chickens;
vector<pair<int, int>> houses;
int minCityDist = 0x7f7f7f7f;

void CalcCityDistance()
{
	int cityDist = 0;
	// 각각의 집을 순회하면서
	for (const auto& house : houses) {
		int chickenDist = 0x7f7f7f7f;
		// 치킨집과의 거리를 계산한다
		for (const auto& chicken : chickens) {
			// 폐업한 곳은 건너뛴다
			if (closed[chicken.first][chicken.second]) continue;
			// 치킨 거리 계산
			int dist = std::abs(house.first - chicken.first) + std::abs(house.second - chicken.second);
			chickenDist = std::min(chickenDist, dist);
		}
		// 도시의 치킨 거리 계산
		cityDist += chickenDist;
	}
	// 도시의 치킨 거리 최솟값
	minCityDist = std::min(minCityDist, cityDist);
}

/// <summary>
/// Recursive 함수는 모든 가능한 치킨집 폐업 조합을 생성하는 역할을 합니다
/// </summary>
/// <param name="closedCount"></param>
void Recursive(int closedCount)
{
	// 폐업할 치킨집 선정을 완료했다면
	if (closedCount == chickens.size() - M) {

		// chickens.size()는 치킨집 개수
		// M은 살아남을 수 있는 치킨집 개수
		// chickens.size() - M는 폐업한 치킨집 개수

		CalcCityDistance();
		return;
	}

	// 치킨집을 찾아 폐업시킨다
	for (int i = 0; i < chickens.size(); i++) {
		int r = chickens[i].first;
		int c = chickens[i].second;
		if (!closed[r][c]) {
			closed[r][c] = true;
			Recursive(closedCount + 1);
			closed[r][c] = false;
		}
	}
}

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : 치킨 배달

	// 시간 복잡도 계산
	// 1. 100 (집의 개수 2 * 50) x 13 (치킨집의 개수) x 13C6 = 대략 200만

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> city[i][j];
			if (city[i][j] == 1) houses.push_back({ i, j });
			else if (city[i][j] == 2) chickens.push_back({ i, j });
		}
	}

	Recursive(0);

	cout << minCityDist;

	return 0;
}
