===========================================================
### Input char variable, ignoring ' ' until '\n'
### 공백이 있는 문자열 입력받기
===========================================================

```c++
std::string str;
std::getline(cin, str);
```

```c++
std::string inputString; char ch;
while (std::cin.get(ch) && ch != '\n')
	inputString.push_back(ch);
```

===========================================================
### 너비 우선 탐색 (BFS)
===========================================================

#### BFS 본체
---
```c++
int BFS(int startY, int startX)
{
	std::queue<std::pair<int, int>> myQueue;
	visited[startY][startX] = true;
	myQueue.emplace(startX, startY);
	int innerCount = 1;

	while (!myQueue.empty())
	{
		auto front = myQueue.front();
		myQueue.pop();

		// [상 하 좌 우] 탐색
		for (int i = 0; i < 4; ++i)
		{
			// 다음 위치
			std::pair<int, int> nextPos(front.first + dx[i], front.second + dy[i]);

			// 지도를 넘어가면 다시 탐색
			if (nextPos.first < 0 || nextPos.second < 0 || nextPos.first > M - 1 || nextPos.second > N - 1)
				continue;

        	// 방문 정보와 지도 정보를 가지고 탐색 결정
			if (!visited[nextPos.second][nextPos.first] && map[nextPos.second][nextPos.first] == 1)
			{
				visited[nextPos.second][nextPos.first] = true;
				myQueue.push(nextPos);
				innerCount++;
			}
		}
	}

	return innerCount;
}
```

#### BFS를 위한 변수 선언 (전역 변수)
---
```c++
// M : 가로 길이
// N : 세로 길이
// K : 입력 횟수
int M, N, K;

// 지도
int map[MAX_Y][MAX_X] = {};

// 방문 정보
bool visited[MAX_Y][MAX_X] = {};

// 상 하 좌 우
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
```

#### BFS 기본 세팅
---
```c++
cin >> M >> N >> K;

int outterCount = 0;

// 지도 세팅
while (K-- > 0)
{
    int X, Y;
    cin >> X >> Y;

    map[Y][X] = 1;
}

// 모든 지도를 돌면서 BFS 탐색
for (int i = 0; i < N; ++i)
{
    for (int j = 0; j < M; ++j)
    {
        // 방문 정보와 지도 정보를 가지고 탐색 결정
        if (!visited[i][j] && map[i][j] == 1)
        {
            BFS(i, j);
            outterCount++;
        }
    }
}

cout << outterCount << '\n';
```

===========================================================
### 깊이 우선 탐색 (DFS)
===========================================================