#include <bits/stdc++.h>
using namespace std;

int N;
int boxArray[10];

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : ¹æ ¹øÈ£

	cin >> N;

	while (N != 0) {
		boxArray[N % 10]++;
		N /= 10;
	}

	int count = -999;
	for (int i = 0; i < 10; ++i) {
		if (i != 6 && i != 9) count = std::max(boxArray[i], count);
	}

	cout << std::max(count, (boxArray[6] + boxArray[9] + 1) / 2);

	return 0;
}
