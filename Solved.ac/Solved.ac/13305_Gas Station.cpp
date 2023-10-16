#include <iostream>

using namespace std;

int main()
{
	// 목적지까지 최소 주유비를 사용해서 도착

	///  Greedy를 설계할 때, "문제를 매우 간단하게 바꿀 수 있는 숨겨진 조건"이 있는지를 잘 찾아보는 습관을 가지자.
	///	 "최소 주유비를 위해선, 매 주유소를 지날때마다 가장 싼 주유비를 택해야 한다."

	int n; cin >> n;

	long long dist[1000];
	int cost[1001];

	for (int i = 1; i < n; ++i)
		cin >> dist[i];

	for (int i = 1; i <= n; ++i)
		cin >> cost[i];

	// 최대한 싼 곳에서 많이 사둬야 한다.
	long long res = 0;
	long long minCost = 9999;

	/// 문제를 간단하게 생각하는 가장 핵심적인 부분
	for (int i = 1; i < n; ++i)
	{
		if (cost[i] < minCost)
			minCost = cost[i];

		/// 곱셈 과정에서의 오버플로우 주의
		res += minCost * dist[i];
	}

	cout << res << '\n';

	return 0;
}