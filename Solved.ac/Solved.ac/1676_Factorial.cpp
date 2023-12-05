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

	// Title : 팩토리얼 0의 개수

	int N; cin >> N;
	int res = 0;

	for (int i = 5; i <= N; i *= 5)
		res += N / i;

	cout << res << '\n';

	return 0;
}
