#include <bits/stdc++.h>
using namespace std;

int N;
int w[100005];

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : ทฮวม

	cin >> N;

	for (int i = 0; i < N; ++i) {
		cin >> w[i];
	}

	sort(w, w + N);

	int res = 0;
	int sum = 0;

	for (int i = N - 1; i >= 0; --i) {
		int cnt = N - i;
		res = max(res, w[i] * cnt);
	}

	cout << res;

	return 0;
}
