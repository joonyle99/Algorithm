#include "pch.h"

struct Pos
{
	int x, y;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<vector<int>> mapArray;

	// 상 하 좌 우 / 좌상 우상 좌하 우하
	// (x,y) Pos 배열 사용
	vector<Pos> DirArray =
	{
		{0, 1},
		{0, -1},
		{-1, 0},
		{1, 0},
		{-1, 1},
		{1, 1},
		{-1, -1},
		{1, -1}
	};

	// 입력은 여러 개의 테스트 케이스로 이루어져 있다
	while (true)
	{
		// 각 테스트 케이스의 첫째 줄에는 지도의 너비 w와 높이 h가 주어진다.
		int w, h;
		cout << "w와 h를 입력하세요" << '\n';
		cin >> w; cin >> h;
		cout << "=================" << '\n';

		// 입력의 마지막 줄에는 0이 두 개 주어진다.
		if (w == 0 && h == 0)
		{
			cout << "입력의 마지막 줄에는 0이 두 개 주어진다" << '\n';
			break;
		}

		// w와 h는 50보다 작거나 같은 양의 정수
		if (w < 1 || w > 50 || h < 1 || h > 50)
		{
			cout << "w와 h는 50보다 작거나 같은 양의 정수" << '\n';
			break;
		}

		/*
		// 지도 초기화
		// 루프를 두 번 돌아야 해서 CPU 캐시 활용에서 불리할 수도 있다.
		mapArray.resize(h);
		for (int i = 0; i < h; ++i)
		{
			mapArray[i].resize(w);
			for (int j = 0; j < w; ++j)
			{
				mapArray[i][j] = -1;
			}
		}
		*/

		// 효율적인 지도 초기화
		mapArray.resize(h, std::vector<int>(w, 0));

		// 지도를 그린다
		for (int i = 0; i < h; ++i)			// 세로
		{
			for (int j = 0; j < w; ++j)		// 가로
			{
				// 1은 땅, 0은 바다
				int mapInfo; cin >> mapInfo;
				mapArray[i][j] = mapInfo;
			}
		}

		// 섬의 개수를 구한다
		// -> 뭐라도 있으면 그 경로는 하나의 섬
		for (int i = 0; i < h; ++i)			// 세로
		{
			for (int j = 0; j < w; ++j)		// 가로
			{
				// 섬(1)의 경우만 체크한다 (이미 방문한 섬은 x)
				if (mapArray[i][j] == 1)
				{
					// 모든 방향을 체크하자
					for (int k = 0; k < DirArray.size(); ++k)
					{
						// 해당 방향에 있나?
						if (mapArray[i - DirArray[k].y][j + DirArray[k].y])
						{

						}
					}
				}
			}
		}


		// 각 테스트 케이스에 대해서, 섬의 개수를 출력한다.
		int result = 0;
		cout << "-> 섬의 개수 : " << result << '\n';

		cout << "=================" << '\n';

	}


	return -1;
}