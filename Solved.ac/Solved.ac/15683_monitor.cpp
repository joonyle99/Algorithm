#include <bits/stdc++.h>
using namespace std;

int N, M;
int board[10][10];

vector<pair<int, int>> cameraPositions;

vector<vector<int>> cameraDirs[6] = {
	{},
	{{0}, {1}, {2}, {3} },	// cctv1's cameraDir -> has each dir
	{{0, 2}, {1, 3}},
	{{0, 1}, {1, 2}, {2, 3}, {3, 0} },
	{{0, 1, 2}, {1, 2, 3}, {2, 3, 0}, {3, 0, 1}},
	{{0, 1, 2, 3}},
};

int minCount = 0;

// 동 북 서 남
int dr[4] = { 0, -1, 0, 1 };
int dc[4] = { 1, 0, -1, 0 };

bool OutOfBound(int row, int col) {
	return row < 0 || row >= N || col < 0 || col >= M;
}

/// <summary>
/// 바라보는 방향으로 모든 칸을 방문한다
/// </summary>
vector<vector<bool>> Ray(int row, int col, int dir, vector<vector<bool>> detected)
{
	while (true) {
		row += dr[dir];
		col += dc[dir];
		if (OutOfBound(row, col)) break;
		if (board[row][col] == 6) break;
		detected[row][col] = true;
	}
	return detected;
}

/// <summary>
/// 사각지대의 수를 계산한다
/// </summary>
/// <param name="detected"></param>
void Calc(vector<vector<bool>> detected) {
	int count = 0;
	// 사각지대를 구한다
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] == 0 && detected[i][j] == false) {
				count++;
			}
		}
	}
	minCount = std::min(minCount, count);
}

void Func(int curCount, vector<vector<bool>> detected) {

	if (curCount == cameraPositions.size()) {
		Calc(detected);
		return;
	}

	int cameraPosRow = cameraPositions[curCount].first;
	int cameraPosCol = cameraPositions[curCount].second;

	int number = board[cameraPosRow][cameraPosCol];  // 1, 2, 3, 4, 5

	for (auto cameraDir : cameraDirs[number]) {
		vector<vector<bool>> tempDetected = detected;
		for (auto eachDir : cameraDir) {
			tempDetected = Ray(cameraPosRow, cameraPosCol, eachDir, tempDetected);
		}
		Func(curCount + 1, tempDetected);
	}

}

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : 감시

	// TODO: 박형독 식으로 풀어보기
	// 4진법을 활용해서,, <상 하 좌 우> 를 4진수의 각각에 대응한다
	// 모든 경우의 수는 4^카메라수
	// 2번, 5번 카메라와 같은 경우는 방향 경우의 수가 4개가 아닌 2개 1개인데,
	// 이 부분에 대해서는 임의로 4개라고 해두고 일괄 실행한다

	cin >> N >> M;
	for (int row = 0; row < N; row++) {
		for (int col = 0; col < M; col++) {
			cin >> board[row][col];
			if (board[row][col] == 6 || board[row][col] == 0) {
				minCount++; // cctv가 0개인 경우를 고려해서 초기화한다
				continue;
			}
			cameraPositions.push_back({ row, col });
		}
	}

	vector<vector<bool>> detected(10);
	for (int i = 0; i < 10; i++) {
		detected[i].resize(10);
	}

	Func(0, detected);

	cout << minCount;

	return 0;
}
