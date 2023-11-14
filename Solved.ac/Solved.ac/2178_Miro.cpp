#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>

using namespace std;

struct Position
{
	int x, y;

	Position()
		:x(0), y(0)
	{}
	Position(int _x, int _y)
		: x(_x), y(_y)
	{}

	bool operator == (const Position& pos) const
	{
		if (x == pos.x && y == pos.y)
			return true;

		return false;
	}
};

// 입력값
int N, M;

// 미로 맵
int map[102][102];

// 미로 방문 여부
int visited[102][102];

// 상하좌우 배열
int dirX[4] = { 0,0,-1,1 };
int dirY[4] = { -1,1,0,0 };

// DFS로 구한 최단 거리
int DFSLength = 100 * 100;

// BFS로 구한 최단 거리
int BFSLength = 100 * 100;

Position curPos;
Position goalPos;

/// <summary>
/// DFS로 하면 깊이 우선으로 모든 경로를 탐색할 수 있다.
///	최단 거리를 구하는 문제에서는 비효율적이다. BFS를 이용하자
/// </summary>
void DFS(Position pos, int depth)
{
	// 범위 넘어가면 리턴
	if (pos.x < 1 || pos.y < 1 || pos.x > M || pos.y > N)
		return;

	if (pos == goalPos)
	{
		if (DFSLength > depth)
			DFSLength = depth;

		return;
	}

	for (int i = 0; i < 4; ++i)
	{
		Position nextPos(pos.x + dirX[i], pos.y + dirY[i]);

		// 갈 수 있다
		if (visited[nextPos.y][nextPos.x] == false && map[nextPos.y][nextPos.x] == true)
		{
			visited[nextPos.y][nextPos.x] = true;
			DFS(nextPos, depth + 1);
			visited[nextPos.y][nextPos.x] = false;
		}
	}
}

/// <summary>
/// BFS를 이용해 너비 우선 탐색을 진행한다.
///	"최단 경로"를 탐색하는데 효율적이다.
///	Queue를 이용한다
/// </summary>
void BFS(Position pos, int depth)
{

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	/// 미로 탐색 문제

	cin >> N >> M;

	goalPos = { M,N };
	curPos = { 1, 1 };

	// 시작 위치는 이미 방문한 상태
	visited[curPos.y][curPos.x] = true;

	// 미로 생성
	for (int i = 1; i <= N; ++i)
	{
		string row; cin >> row;

		for (int j = 0; j < M; ++j)
		{
			if (row[j] == '1')
				map[i][j + 1] = 1;
		}
	}

	// DFS로 미로 탐색
	DFS(curPos, 1);

	// BFS로 미로 탐색
	BFS(curPos, 1);

	// 최단 거리 출력
	cout << DFSLength << endl;

	return 0;
}