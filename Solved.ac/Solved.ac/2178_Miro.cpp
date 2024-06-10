#include <iostream>
#include <string>
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
int visited_J[102][102];

// 상하좌우 배열
int dirX[4] = { 0,0,-1,1 };
int dirY[4] = { -1,1,0,0 };

// DFS로 구한 최단 거리
int DFSLength = 100 * 100;

// BFS로 구한 최단 거리
int BFSLength = 100 * 100;

// BFS 거리 맵
int distMap[102][102];

Position curPos;
Position goalPos;

ostream& operator << (ostream& os, Position pos)
{
	os << "(" << pos.x << " " << pos.y << ") ";

	return os;
}

void PrintQueue(std::queue<Position> myQueue)
{
	system("cls");

	// 큐에 있는 모든 요소를 출력
	while (!myQueue.empty())
	{
		std::cout << myQueue.front();
		myQueue.pop();
	}

	cout << endl;
}

/// <summary>
/// DFS로 하면 깊이 우선으로 모든 경로를 탐색할 수 있다.
///	최단 거리를 구하는 문제에서는 비효율적이다. BFS를 이용하자
/// </summary>
void DFS(Position pos, int depth)
{
	// 범위 넘어가면 리턴
	if (pos.x < 1 || pos.y < 1 || pos.x > M || pos.y > N)
		return;

	// 목표 지점 도달 시, 거리 갱신
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
		if (visited_J[nextPos.y][nextPos.x] == false && map[nextPos.y][nextPos.x] == true)
		{
			visited_J[nextPos.y][nextPos.x] = true;
			DFS(nextPos, depth + 1);

			// 실패한 경로를 다시 초기화
			visited_J[nextPos.y][nextPos.x] = false;
		}
	}
}

/// <summary>
/// BFS를 이용해 너비 우선 탐색을 진행한다.
///	"최단 경로"를 탐색하는데 효율적이다.
///	Queue를 이용한다
/// </summary>
int BFS(Position startPos)
{
	// Queue를 이용해 최단 경로 탐색 (완전 탐색)
	std::queue<Position> myQueue;

	// 시작점 세팅
	myQueue.push(startPos);
	visited_J[startPos.y][startPos.x] = true;
	distMap[startPos.y][startPos.x] = 1;

	// 큐에 값이 있는 동안 계속해서 반복
	while(!myQueue.empty())
	{
		// 한 위치에서 갈 수 있는 모든 방향을 탐색한다.
		// 문어발 방식
		for (int i = 0; i < 4; ++i)
		{
			// 다음에 이동할 위치 계산
			Position nextPos(myQueue.front().x + dirX[i], myQueue.front().y + dirY[i]);

			// 갈 수 있다면
			if (visited_J[nextPos.y][nextPos.x] == false && map[nextPos.y][nextPos.x] == true)
			{
				// Queue에 넣어둔다.
				myQueue.push(nextPos);

				// 방문 처리
				visited_J[nextPos.y][nextPos.x] = true;

				// 거리 계산 (누적)
				distMap[nextPos.y][nextPos.x] = distMap[myQueue.front().y][myQueue.front().x] + 1;
			}
			else
				continue;
		}

		// 다 돌았으면 맨 앞에 있는 요소 제거
		myQueue.pop();
	}

	return distMap[N][M];
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
	visited_J[curPos.y][curPos.x] = true;

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

	// DFS 최단 거리 출력
	cout << DFSLength << endl;

	// BFS로 미로 탐색
	BFSLength = BFS(curPos);

	// BFS 최단 거리 출력
	cout << BFSLength << endl;

	return 0;
}