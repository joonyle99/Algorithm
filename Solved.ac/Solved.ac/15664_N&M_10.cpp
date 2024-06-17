#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[10];
int res[10];
bool isUsed[10];

void Func(int curCount) {
	if (curCount == M) {
		for (int i = 0; i < curCount; i++) {
			cout << res[i] << ' ';
		}
		cout << '\n';
		return;
	}

	int temp = -1;
	for (int i = 0; i < N; i++) {
		if (isUsed[i]) continue;
		if (temp == arr[i]) continue;
		if (curCount > 0) {
			if (arr[i] < res[curCount - 1])
				continue;
		}
		temp = arr[i];
		res[curCount] = arr[i];
		isUsed[i] = true;
		Func(curCount + 1);
		isUsed[i] = false;
	}
}
int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : N과 M (10)

	// 1. 고른 수열은 비내림차순이어야 한다.
	// => 길이가 K인 수열 A가 A1 ≤ A2 ≤ ... ≤ AK-1 ≤ AK를 만족하면, 비내림차순이라고 한다.

	// 2. 같은 수가 입력될 수 있다

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	std::sort(arr, arr + N);
	Func(0);
	return 0;
}
