#include <bits/stdc++.h>
using namespace std;

int n;
int sequence[100005];
int res = -0x7f7f7f7f;

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : 연속합

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> sequence[i];
	}

	/*
	// 1. brute force
	// o(N^2) -> 100,000 x 100,000 = 10^10 = 100억
	// 1초에 1억인데 100억이면 말도 안되는 연산량이다
	for (int i = 0; i < n; i++) {		// start point
		int sum = arr[i];
		res = max(res, sum);
		for (int j = i + 1; j < n; j++) {	// next target point
			sum += arr[j];
			res = max(res, sum);
		}
	}
	*/

	// 2. dynamic programming
	// 10 -4 3 1 5 6 -35 12 21 -1
	// 음수를 만났는데 다음 수가 계산값보다 크다?
	// 그러면 연속해서 계산할 이유가 없다
	// 왜냐하면 다음 수를 시작으로하는 게 이득이기 때문이다

	int curSum = 0;
	for (int i = 0; i < n; i++) {
		/*
		if (curSum + arr[i] < arr[i]) {
			curSum = arr[i];
		}
		else {
			curSum += arr[i];
		}
		*/
		curSum = max(curSum + sequence[i], sequence[i]); // ** 위의 주석 부분을 대체할 수 있는 한 줄의 코드 **
		res = max(res, curSum);
	}

	cout << res;

	return 0;
}
