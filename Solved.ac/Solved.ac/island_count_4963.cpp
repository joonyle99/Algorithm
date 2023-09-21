#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct Pos
{
	int x, y;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// 상 / 하 / 좌 / 우 / 좌상 / 우상 / 좌하 / 우하
	const vector<Pos> DirArray =
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
		int w; cin >> w;
		int h; cin >> h;

		// 입력의 마지막 줄에는 0이 두 개 주어진다.
		if (w == 0 && h == 0) break;
		// w와 h는 50보다 작거나 같은 양의 정수
		if (w < 1 || w > 50 || h < 1 || h > 50) break;

		// 효율적인 지도 초기화
		vector<vector<int>> mapArray;
		mapArray.resize(h, std::vector<int>(w, 0));

		int islandCnt = 0;

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
		// -> 뭐라도 점이 있으면 그 경로는 하나의 섬
		for (int i = 0; i < h; ++i)	// 세로
		{
			for (int j = 0; j < w; ++j)	// 가로
			{
				// 만약 점이 하나 있으면 그 점을 기준으로 탐색을 시작한다 ==> "시작점"
				if (mapArray[i][j] == 1)
				{
					// 처음 섬 탐색 시작 점을 curPos로 두고 시작한다
					Pos curPos = { j,i };

					// 지나온 곳은 map에서 기록한다
					mapArray[curPos.y][curPos.x] = -1;

					// 왔던곳을 돌아가기 위해서 지나온 점을 기억한다.
					stack<Pos> posStack;
					posStack.push(curPos);

					// 섬이 어디까지 이어지는지 체크
					while(true)
					{
						bool isFind = false;

						// 모든 방향을 체크하자
						for (int k = 0; k < DirArray.size(); ++k)
						{
							// 탐색하려는곳이 지도를 벗어나지 않는지 체크
							if (curPos.y - DirArray[k].y >= 0 &&
								curPos.x + DirArray[k].x >= 0 &&
								curPos.y - DirArray[k].y < h &&
								curPos.x + DirArray[k].x < w)
							{
								// 해당 방향에 있나?
								if (mapArray[curPos.y - DirArray[k].y][curPos.x + DirArray[k].x] == 1)
								{
									// 현재 위치도 이동
									curPos = { curPos.x + DirArray[k].x , curPos.y - DirArray[k].y };

									// 이동한 위치를 스택에 넣는다
									posStack.push(curPos);

									// 지나온 곳은 map에서 기록한다
									mapArray[curPos.y][curPos.x] = -1;

									isFind = true;

									break;
								}
							}
						}

						// 다 찾아봤는데도 없다..?
						if (!isFind)
						{
							// 섬 탐색 종료
							if (posStack.empty())
							{
								islandCnt++;
								break;
							}

							// 뒤로 돌아간다
							posStack.pop();

							if (!posStack.empty())
								curPos = posStack.top();
						}
					}
				}
			}
		}

		// 각 테스트 케이스에 대해서, 섬의 개수를 출력한다.
		cout << islandCnt << '\n';
	}

	return 0;
}