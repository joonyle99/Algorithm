#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <algorithm>

using std::cin;
using std::cout;

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : 체스판 다시 칠하기

	// Group : Brute Force 알고리즘

	int N, M;
	cin >> N >> M;

	std::vector<std::vector<char>> board(N);
	for (auto& vec : board)
		vec.resize(M);

	/// 핵심 포인트..! (머리가 좋아야 몸이 고생 안한다..)
	std::string WB[8] = {
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW"
	};

	std::string BW[8] = {
			"BWBWBWBW",
			"WBWBWBWB",
			"BWBWBWBW",
			"WBWBWBWB",
			"BWBWBWBW",
			"WBWBWBWB",
			"BWBWBWBW",
			"WBWBWBWB"
	};

	// 보드 생성
	for (int i = 0; i < N; ++i)
	{
		// 각 행의 상태가 주어진다.
		std::string inputString;
		cin >> inputString;
		for (int j = 0; j < inputString.length(); ++j)
		{
			char ch = inputString[j];
			if (ch == 'W')
				board[i][j] = 'W';
			else
				board[i][j] = 'B';
		}
	}

	// 대충 21억 4천만
	int resultMinCount = 0x7f7f7f7f;

	for (int a = 0; a <= N - 8; ++a)
	{
		for (int b = 0; b <= M - 8; ++b)
		{
			int rowStart = a;
			int columnStart = b;

			int wb_count = 0;
			int bw_count = 0;

			for (int i = rowStart; i < rowStart + 8; ++i)
			{
				for (int j = columnStart; j < columnStart + 8; ++j)
				{
					// WB와 비교
					if(board[i][j] != WB[i - rowStart][j - columnStart])
						wb_count++;

					// Bw와 비교
					if (board[i][j] != BW[i - rowStart][j - columnStart])
						bw_count++;
				}
			}

			int minCount = std::min(wb_count, bw_count);
			resultMinCount = std::min(resultMinCount, minCount);
		}
	}

	cout << resultMinCount << '\n';

	return 0;
}
