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

	// Title : 영역 구하기

	int M, N, K;
	cin >> M >> N >> K;

	std::vector<std::vector<int>> matrix(M + 1);

	for (int i = 0; i < matrix.size(); ++i)
		matrix[i].resize(N + 1);

	while (K-- > 0)
	{
		int bl_x, bl_y, tr_x, tr_y;
		cin >> bl_x >> bl_y >> tr_x >> tr_y;

		matrix[][];
	}


	return 0;
}