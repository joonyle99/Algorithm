#include <bits/stdc++.h>
using namespace std;

int N, M, x, y, K, c;
int board[25][25];
int dice[7] = { 0, };
//    [6]
// [4][2][3]
//    [5]
//    [1]

bool IsOkay(int row, int col) {
	if (row < 0 || row >= N || col < 0 || col >= M)
		return false;
	return true;
}

void Roll(int command) {
	int temp[7];
	for (int i = 1; i <= 6; i++) {
		temp[i] = dice[i];
	}
	// µ¿
	if (command == 1) {
		temp[1] = dice[4];
		temp[2] = dice[3];
		temp[3] = dice[1];
		temp[4] = dice[2];
		temp[5] = dice[5];
		temp[6] = dice[6];
	}
	// ¼­
	else if (command == 2) {
		temp[1] = dice[3];
		temp[2] = dice[4];
		temp[3] = dice[2];
		temp[4] = dice[1];
		temp[5] = dice[5];
		temp[6] = dice[6];
	}
	// ºÏ
	else if (command == 3) {
		temp[1] = dice[5];
		temp[2] = dice[6];
		temp[3] = dice[3];
		temp[4] = dice[4];
		temp[5] = dice[2];
		temp[6] = dice[1];
	}
	// ³²
	else if (command == 4) {
		temp[1] = dice[6];
		temp[2] = dice[5];
		temp[3] = dice[3];
		temp[4] = dice[4];
		temp[5] = dice[1];
		temp[6] = dice[2];
	}
	for (int i = 1; i <= 6; i++) {
		dice[i] = temp[i];
	}
}

void ExecuteCommand(int command)
{
	int row = x;
	int col = y;

	if (command == 1) ++col;
	else if (command == 2) --col;
	else if (command == 3) --row;
	else if (command == 4) ++row;

	if (IsOkay(row, col))
	{
		x = row;
		y = col;

		Roll(command);

		if (board[row][col] == 0)
			board[row][col] = dice[2];
		else {
			dice[2] = board[row][col];
			board[row][col] = 0;
		}

		cout << dice[1] << '\n';
	}
}

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : ÁÖ»çÀ§ ±¼¸®±â

	cin >> N >> M >> x >> y >> K;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> board[i][j];
		}
	}

	while (K--)
	{
		cin >> c;

		ExecuteCommand(c);
	}

	return 0;
}
