#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;

	vector<int> vec;

	// n개의 정수로 이루어진 임의의 수열이 주어진다
	for (int i = 0; i < n; ++i)
	{
		int value; cin >> value;
		vec.push_back(value);
	}

	// 몇 개의 수를 선택해서 구할 수 있는 합 중 가장 큰 합
	// 한 개 이상 선택
	// 10, -4, 3, 1, 5, 6, -35, 12, 21, -1
	// 12 + 21인 33

	/*
	* 방법 1 : Brute Force (시간 복잡도 O(n^2))*
	int sum = 0;
	int res = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = i; j < n; ++j)
		{
			// 모든 경우를 일일이 다 해본다,,
			// 1 ~ n , 2 ~ n , 3 ~ n , ...
			sum += vec[j];
			res = std::max(sum, res);
		}

		sum = 0;
	}

	cout << res << endl;
	*/

	/*
	* 방법 2 : 음수가 나오는 경우 리셋 (착각해서 잘못 품) *
	int curSum = 0;
	int maxSum = 0;
	for (int i = 0; i < n; ++i)
	{
		curSum += vec[i];
		maxSum = std::max(curSum, maxSum);

		// 내가 하나 간과한 점
		// * 음수가 나온다고 무조건 리셋할게 아니네,, 착각했다 *
		if (vec[i] < 0)
			curSum = 0;
	}

	cout << maxSum << endl;
	*/

	// Dynamic Programming (동적 프로그래밍)을 이용한 풀이 방법
	// (시간 복잡도 O(n))
	// DP는 쉽게 말해 "기억해서 풀기"이다.

	int curSum = vec[0];
	int maxSum = vec[0];

	for (int i = 1; i < n; ++i)
	{
		// ** 아래 경우를 판단 **
		// 10 -4 3 => 10 - 4가 3보다 크다
		// 3 1 5 6 -35 12 => 3 + 1 + 5 + 6 - 35가 12보다 작다
		curSum = std::max(vec[i], curSum + vec[i]);
		maxSum = std::max(maxSum, curSum);
	}

	cout << maxSum << endl;

	return 0;
}