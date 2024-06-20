#include <bits/stdc++.h>
using namespace std;

// TODO: curCount가 하거나 안 하거나 둘 중 하나로 선택되면서 2^N의 경우의 수가 되는 백트래킹이 있고, 조건이 충족되는 경우만 취하는 백트래킹이 있다. 그래서 종료 조건이 curCount == K 이지만 다른 느낌이다.

int N, M, K;
vector<vector<int>> stickers[105];

int maxCount = -1000000000;

bool CanAttach(const vector<vector<int>>& sticker, const vector<vector<int>>& notebook, int moveRow, int moveCol)
{
	for (int row = 0; row < sticker.size(); row++) {
		for (int col = 0; col < sticker[row].size(); col++) {
			if (notebook[moveRow + row][moveCol + col] == 1 && sticker[row][col] == 1)		// 하나라도 겹치면 안된다
				return false;
		}
	}
	return true;
}

vector<vector<int>> AttachSticker(const vector<vector<int>>& sticker, const vector<vector<int>>& notebook, int moveRow, int moveCol)
{
	vector<vector<int>> tempNotebook = notebook;
	for (int row = 0; row < sticker.size(); row++) {
		for (int col = 0; col < sticker[row].size(); col++) {
			if (sticker[row][col] == 0) continue;		// 스티커 부분만 붙힌다
			tempNotebook[moveRow + row][moveCol + col] = sticker[row][col];
		}
	}
	return tempNotebook;
}

/// <summary>
/// 행렬을 시계 방향으로 90도 회전시키면, 각 좌표 (i, j)는 (j, N − 1 − i)로 변환됩니다. (N은 원래 행렬의 행 수)
/// 행렬을 반시계 방향으로 90도 회전시키면, 각 좌표 (i, j)는 (M - 1 - j, i)로 변환됩니다. (M은 원래 행렬의 열 수)
/// 
/// ===
/// 
/// N은 행의 수 M은 열의 수를 나타낼 때,
/// 
/// 행렬을 시계 방향으로 90도 회전하면 행렬의 행과 열이 바뀐다.
/// 
/// ===
/// 
/// 행렬의 첫 번째 행은 회전 후, 마지막 열이 된다.
/// 행렬의 두 번째 행은 회전 후, 두 번째 마지막 열이 된다.
/// 
/// ..
/// 
/// 행렬의 마지막 행은 회전 후, 첫 번째 열이 된다.
/// 
/// ===
/// 
/// 행렬의 첫 번째 열은 회전 후, 첫 번째 행이 된다.
/// 행렬의 두 번째 열은 회전 후, 두 번째 행이 된다.
/// 
/// ..
/// 
/// 행렬의 마지막 열은 회전 후, 마지막 행이 된다.
/// 
/// ===
/// 
/// 이를 종합해 보면 각 좌표 (i, j)는 (j, N - 1 - i)가 된다.
/// 
/// </summary>
/// <param name="rotatedCount"></param>
/// <param name="sticker"></param>
/// <returns></returns>
vector<vector<int>> RotateSticker(int rotatedCount, const vector<vector<int>>& originSticker) {
	if (rotatedCount == 0) return originSticker;

	int rowCount = originSticker.size();
	int colCount = originSticker[0].size();

	vector<vector<int>> rotatedSticker;

	switch (rotatedCount) {
	case 1:
		rotatedSticker = vector<vector<int>>(colCount, vector<int>(rowCount));
		for (int row = 0; row < rowCount; row++) {
			for (int col = 0; col < colCount; col++) {
				rotatedSticker[col][rowCount - 1 - row] = originSticker[row][(col)];
			}
		}
		break;
	case 2:
		rotatedSticker = vector<vector<int>>(rowCount, vector<int>(colCount));
		for (int row = 0; row < rowCount; row++) {
			for (int col = 0; col < colCount; col++) {
				rotatedSticker[rowCount - 1 - row][colCount - 1 - col] = originSticker[row][col];
			}
		}
		break;
	case 3:
		rotatedSticker = vector<vector<int>>(colCount, vector<int>(rowCount));
		for (int row = 0; row < rowCount; row++) {
			for (int col = 0; col < colCount; col++) {
				rotatedSticker[colCount - 1 - col][row] = originSticker[row][col];
			}
		}
		break;
	}

	return rotatedSticker;
}

/// <summary>
/// 스티커를 노트북에 붙일 수 있는 경우의 수를 탐색한다
/// 왼쪽 상단을 최우선으로하고, 회전도 가능하다
/// 따라서 스티커를 '이동'시키고 '회전'시키는 기능을 구현해야 한다.
/// 
/// 스티커가 4개라면 (회전: 4) x (이동: 40 x 40) x (확인: 10 x 10) x (스티커 개수: 100) = 64000000 의 연산량
/// 
/// </summary>
/// <param name="curCount"></param>
/// <param name="notebook"></param>
void Recursive(int checkedCount, const vector<vector<int>>& notebook) {

	// 모든 스티커를 탐색해봤으면 종료
	if (checkedCount == K) {
		int count = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (notebook[i][j] == 1)
					count++;
			}
		}
		maxCount = std::max(maxCount, count);
		return;
	}

	auto oldSticker = stickers[checkedCount];
	
	// 회전 (0도, 90도, 180도, 270도 - 시계 방향)
	for (int rotatedCount = 0; rotatedCount < 4; rotatedCount++) {
		auto newSticker = RotateSticker(rotatedCount, oldSticker);
		bool canAttach = false;
		// 스티커를 이동하며 붙일 수 있는지 체크한다
		for (int moveRow = 0; moveRow < N; moveRow++) {
			for (int moveCol = 0; moveCol < M; moveCol++) {
				// 스티커가 범위를 벗어나면 스킵한다
				if (moveRow + newSticker.size() > N || moveCol + newSticker[0].size() > M) continue;
				canAttach = CanAttach(newSticker, notebook, moveRow, moveCol);
				if (canAttach) {
					auto attachedNotebook = AttachSticker(newSticker, notebook, moveRow, moveCol);
					Recursive(checkedCount + 1, attachedNotebook);
				}
			}
		}
		if (!canAttach) {
			Recursive(checkedCount + 1, notebook);
		}
	}
}

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : 스티커 붙이기

	cin >> N >> M >> K;
	// K개의 스티커 설정
	for (int i = 0; i < K; i++) {
		// 각 스티커의 크기 설정
		int R, C; cin >> R >> C;
		stickers[i].resize(R);
		// 각 스티커 요소 설정
		for (int row = 0; row < R; row++) {
			stickers[i][row].resize(C);
			for (int col = 0; col < C; col++) {
				cin >> stickers[i][row][col];
			}
		}
	}

	vector<vector<int>> notebook(N, vector<int>(M, 0));
	Recursive(0, notebook);

	cout << maxCount;

	return 0;
}
