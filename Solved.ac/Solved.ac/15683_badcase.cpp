// 삼성 SW 역략테스트 A형 기출 문제
// 시뮬레이션

#include <bits/stdc++.h>
using namespace std;

int N, M;
int maps[10][10];
int firstMaps[10][10];
int normalAreaCount = 0x7F7F7F7F; // 2,130,706,431

class myVector
{
public:
	int x, y;

	myVector() = default;
	myVector(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
};

class cctv
{
public:
	int number;
	int excuteCount;

	cctv(int n, int cnt)
	{
		this->number = n;
		this->excuteCount = cnt;
	}
};

void print_map()
{
	cout << "=============================" << '\n';

	// i는 세로 방향, 즉 y축을 나타낸다
	for (int i = 0; i < N; ++i)
	{
		// j는 가로 방향,  즉 x축을 나타낸다
		for (int j = 0; j < M; ++j)
		{
			// maps[y축][x축]이 들어가야
			// 수평선이 x축이고 수직선이 y축인 데카르트 좌표계가 구현된다
			cout << maps[i][j] << ' ';
		}

		cout << '\n';
	}
}

int check_areaCount()
{
	// 초기화
	int cnt = 0;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (maps[i][j] == 0) cnt++;
		}
	}

	return cnt;
}

void reset_map()
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			maps[i][j] = firstMaps[i][j];
		}
	}
}

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : 감시

	// 사무실의 크기와 상태,
	// CCTV의 정보가 주어졌을 때,
	// CCTV의 방향을 적절히 정해서,
	//
	// 사각 지대의 최소 크기를 구하는 프로그램을 작성

	cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			int input; cin >> input;

			firstMaps[i][j] = input;
			maps[i][j] = input;
		}
	}

	// 최대한 CCTV를 잘 설치해서 많은 영역을 감시할 수 있어야 사각 지대의 수가 최소가 된다

	/// CCTV의 방향 정의

	myVector cctvBasic[4] = { {0, 1}, {0, -1}, {-1, 0}, {1 ,0} };

	// 1. 한쪽 방향 (상 / 하 / 좌 / 우)
	myVector cctv1[4][1] = { cctvBasic[0], cctvBasic[1], cctvBasic[2], cctvBasic[3] };
	// 2. 양쪽 방향 (상 + 하 / 좌 + 우)
	myVector cctv2[2][2] = { {cctvBasic[0], cctvBasic[1]}, {cctvBasic[2], cctvBasic[3]} };
	// 3. 직각 방향 (상 + 우 / 상 + 좌 / 하 + 우 / 하 + 좌)
	myVector cctv3[4][2] = { {cctvBasic[0], cctvBasic[3]}, {cctvBasic[0], cctvBasic[2]}, {cctvBasic[1], cctvBasic[3]}, {cctvBasic[1], cctvBasic[2]} };
	// 4. 세 방향 (상 + 좌 + 우 / 상 + 우 + 하 / 우 + 하 + 좌 / 하 + 좌 + 상)
	myVector cctv4[4][3] = { {cctvBasic[0], cctvBasic[2], cctvBasic[3]}, {cctvBasic[0], cctvBasic[3], cctvBasic[1]}, {cctvBasic[3], cctvBasic[1], cctvBasic[2]}, {cctvBasic[1], cctvBasic[2], cctvBasic[0]} };
	// 5. 네 방향 (상 + 하 + 좌 + 우)
	myVector cctv5[1][4] = { {cctvBasic[0], cctvBasic[1], cctvBasic[2], cctvBasic[3]} };

	int cctvRayCount[5] = { 1,2,2,3,4 };
	int cctvExcuteCount[5] = { 4,2,4,4,1 };

	vector<pair<cctv, myVector>> cctvInfo;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (maps[i][j] >= 1 && maps[i][j] <= 5)
			{
				int cctvNumber = maps[i][j];
				cctv cctv(cctvNumber, cctvExcuteCount[cctvNumber - 1]);
				myVector cctvPosition(j, i);
				cctvInfo.emplace_back(cctv, cctvPosition);
			}
		}
	}

	// N중 for문을 만들어야 한다

	while (true)
	{
		// cctv를 하나씩 돈다
		for (int i = 0; i < cctvInfo.size(); ++i)
		{
			const auto this_cctv = cctvInfo[i];
			myVector curPos = { this_cctv.second.x, this_cctv.second.y };

			// cctv 방향의 개수
			for (int c = 0; c < cctvRayCount[this_cctv.first.number - 1]; ++c)
			{
				// cctv의 방향대로 쭉 쏜다
				while (true)
				{
					myVector nextPos = { 0,0 };

					// 한 방향
					if (this_cctv.first.number == 1)
						nextPos = { curPos.x + cctv1[this_cctv.first.excuteCount - 1][c].x, curPos.y + cctv1[this_cctv.first.excuteCount - 1][c].y };
					// 두 방향
					else if (this_cctv.first.number == 2)
						nextPos = { curPos.x + cctv2[this_cctv.first.excuteCount - 1][c].x, curPos.y + cctv2[this_cctv.first.excuteCount - 1][c].y };
					// 두 방향
					else if (this_cctv.first.number == 3)
						nextPos = { curPos.x + cctv3[this_cctv.first.excuteCount - 1][c].x, curPos.y + cctv3[this_cctv.first.excuteCount - 1][c].y };
					// 세 방향
					else if (this_cctv.first.number == 4)
						nextPos = { curPos.x + cctv4[this_cctv.first.excuteCount - 1][c].x, curPos.y + cctv4[this_cctv.first.excuteCount - 1][c].y };
					// 네 방향
					else if (this_cctv.first.number == 5)
						nextPos = { curPos.x + cctv5[this_cctv.first.excuteCount - 1][c].x, curPos.y + cctv5[this_cctv.first.excuteCount - 1][c].y };

					if (nextPos.x < 0 || nextPos.x >= M || nextPos.y < 0 || nextPos.y >= N) break;
					if (maps[nextPos.y][nextPos.x] == 6) break;

					curPos = nextPos;

					if (maps[nextPos.y][nextPos.x] >= 1 && maps[nextPos.y][nextPos.x] <= 5) continue;

					maps[curPos.y][curPos.x] = 7;
				}
			}
		}

		// 한 사이클 전부 돌았을 때 체크한다
		normalAreaCount = min(check_areaCount(), normalAreaCount);
		reset_map();
	}

	cout << normalAreaCount << '\n';

	return 0;
}
