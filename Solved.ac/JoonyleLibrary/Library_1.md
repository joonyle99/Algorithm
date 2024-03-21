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
	myQueue.emplace(startX, startY);
	visited[startY][startX] = true;
	int innerCount = 1;

	// 큐에 아무것도 없을 때까지
	while (!myQueue.empty())
	{
		// ** 큐에서 하나의 노드를 꺼낸다 **
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
				// ** 연결된 노드 중 방문하지 않은 노드를 방문하고, 차례대로 큐에 삽입한다. **
				myQueue.push(nextPos);
				visited[nextPos.second][nextPos.first] = true;
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



===========================================================
### Queue (배열로 구현)
===========================================================

### 주의 사항

ArrayQueue 클래스는 지역 변수로 선언된 배열이기 때문에,  
적은 데이터로만 동작이 가능하다.

```c++
class ArrayQueue
{
public:
	// 스택 메모리 1MB는
	// 2^20 byte / 4 byte
	// 262,144개까지 선언할 수 있다
	int array[200001];
	int head = 0, tail = 0;

public:
	int Size() const
	{
		return tail - head;
	}
	bool Empty() const
	{
		return (head == tail);
	}
	int Front() const
	{
		if (Empty()) return -1;

		return array[head];
	}
	int Back() const
	{
		if (Empty()) return -1;

		return array[tail - 1];
	}

public:
	void Push(int v)
	{
		array[tail++] = v;
	}
	int Pop()
	{
		if (Empty()) return -1;

		return array[head++];
	}
};
```

===========================================================
### Queue (연결 리스트로 구현)
===========================================================

```c++
class LinkedListQueue
{
	class Node
	{
	public:
		int value;
		Node* preNode;
		Node* nextNode;

	public:
		Node(int v)
		{
			this->value = v;

			preNode = nullptr;
			nextNode = nullptr;
		}
		void SetPreNode(Node* node)
		{
			this->preNode = node;
		}
		void SetNextNode(Node* node)
		{
			this->nextNode = node;
		}
	};

public:
	Node* front = nullptr;
	Node* rear = nullptr;
	int nodeCount = 0;

public:
	int Size() const
	{
		return nodeCount;
	}
	bool Empty() const
	{
		return (nodeCount == 0);
	}
	int Front() const
	{
		if (Empty()) return -1;

		return front->value;
	}
	int Back() const
	{
		if (Empty()) return -1;

		return rear->value;
	}

public:
	void PrintAllNode()
	{
		while (!Empty())
		{
			cout << Front() << '\n';
			Pop();
		}
	}

public:
	void Push(int v)
	{
		// 노드 생성
		Node* newNode = new Node(v);

		// 노드 개수 증가
		nodeCount++;

		if (nodeCount == 1)
		{
			front = newNode;
			rear = newNode;
			return;
		}

		// rear와 newNode의 Pointing 변경
		newNode->SetNextNode(rear);
		rear->SetPreNode(newNode);

		// rear를 newNode로 대체
		rear = newNode;
	}
	int Pop()
	{
		if (Empty()) return -1;

		// 노드 개수 감소
		nodeCount--;

		// 삭제하는 노드의 value
		const int returnValue = front->value;

		// front를 가리키고 있던 노드로 front를 대체
		front = front->preNode;

		return returnValue;
	}
};
```