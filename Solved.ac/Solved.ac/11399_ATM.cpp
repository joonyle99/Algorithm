#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N; cin >> N;
	int partialSum = 0;
	int res = 0;

	std::vector<int> timeVec(N + 1);

	for (int i = 1; i <= N; ++i)
		cin >> timeVec[i];

	// atm 1대에 n명이 줄을 섬
	// n명은 1번부터 n번까지 번호가 매겨짐
	// ** 줄을 서는 순서에 따라 인출 시간합이 달라짐 **
	// 3 1 4 3 2인 경우 = 39분
	// 1 2 3 3 4인 경우 = 32분
	// 돈을 인출하는데 필요한 시간의 합의 최소값 구하기

	// 인출하는 시간이 적은 사람부터 돈을 인출해야 한다.
	std::sort(timeVec.begin(), timeVec.end());

	for (int i = 1; i <= N; ++i)
	{
		partialSum += timeVec[i];
		res += partialSum;
	}

	cout << res << endl;

	return 0;
}