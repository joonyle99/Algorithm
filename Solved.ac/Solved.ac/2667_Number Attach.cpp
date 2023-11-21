#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// 단지 번호 붙이기

	int N; cin >> N;

	std::vector<std::vector<char>> map(N + 1);
	for (auto& vec : map)
		vec.resize(N + 1);

	// Map 제작
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



	return 0;
}