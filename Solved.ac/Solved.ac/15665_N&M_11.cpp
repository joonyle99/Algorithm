#include <bits/stdc++.h>
using namespace std;
int N, M;
int arr[10];
int res[10];
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
		if (temp == arr[i]) continue;
		temp = arr[i];					/// ** 같은 깊이에서 이전 숫자와 중복되는 수를 넣으려고 하면 중복되는 수열이 만들어지기 때문에 X
		res[curCount] = arr[i];
		Func(curCount + 1);
	}
}
int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : N과 M (11)

	// 1. 같은 수를 여러 번 골라도 된다.

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	std::sort(arr, arr + N);
	Func(0);

	return 0;
}
