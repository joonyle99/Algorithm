#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N;

int visited_J[26][26];

int deltaCol[4] = { 0, 0, -1, 1 };
int deltaRow[4] = { -1, 1, 0,0 };

struct Position
{
	int x, y;

	Position(int _x, int _y)
		: x(_x), y(_y)
	{}
};

int SearchAptBlock_BFS(std::vector<std::vector<char>>& map, Position pos)
{
	std::queue<Position> myQueue;
	visited_J[pos.y][pos.x] = true;
	myQueue.push(pos);
	int aptCnt = 1;

	while (!myQueue.empty())
	{
		// 상하좌우 순서대로 탐색
		for (int k = 0; k < 4; ++k)
		{
			Position nextPos(myQueue.front().x + deltaCol[k], myQueue.front().y + deltaRow[k]);

			if (nextPos.x > N || nextPos.y > N || nextPos.x < 1 || nextPos.y < 1)
				continue;

			if (map[nextPos.y][nextPos.x] == '1' && visited_J[nextPos.y][nextPos.x] == false)
			{
				visited_J[nextPos.y][nextPos.x] = true;
				myQueue.push(nextPos);
				aptCnt++;
			}
		}

		myQueue.pop();
	}

	return aptCnt;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// 단지 번호 붙이기

	cin >> N;

	std::vector<std::vector<char>> map(N + 1);
	for (auto& vec : map)
		vec.resize(N + 1);

	// Map 생성
	for (int i = 1; i <= N; ++i)
	{
		string input; cin >> input;

		for (int j = 1; j <= N; ++j)
		{
			map[i][j] = input[j - 1];
		}
	}

	// 1. n x n의 Map을 (1,1)부터 (n,n)까지 순회한다.
	// 2. 순회 하면서 1을 찾은 순간 아파트 단지를 구한다
	// 3. 더이상 단지가 없다면 모두 방문처리를 하여 한 아파트 단지를 마무리 한다
	// 4. 순회한 지점부터 다시 (1)을 시작으로 재실행한다.
	// 5. 그렇게 단지의 수, 단지의 집의 수를 구한다 (오름차순 정렬)

	int aptBlockCnt = 0;
	std::vector<int> aptCntArr;

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			// 아파트 단지 찾음
			if (map[i][j] == '1' && visited_J[i][j] == false)
			{
				aptBlockCnt++;

				const Position searchPos(j, i);

				// 단지를 탐색
				int aptCnt = SearchAptBlock_BFS(map, searchPos);

				// 단지 내 아파트의 개수
				aptCntArr.push_back(aptCnt);
			}
		}
	}

	// 단지 내 아파트의 개수를 정렬
	std::sort(aptCntArr.begin(), aptCntArr.end());

	cout << aptBlockCnt << endl;
	for (const auto& v : aptCntArr)
		cout << v << endl;

	return 0;
}