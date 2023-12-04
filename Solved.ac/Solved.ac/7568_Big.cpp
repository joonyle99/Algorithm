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

	// Title : µ¢Ä¡

	int N; cin >> N;
	std::vector<std::pair<int, int>> myList;

	for (int i = 0; i < N; ++i)
	{
		int x, y;
		cin >> x >> y;

		myList.emplace_back(x, y);
	}

	int people[50] = { 0, };

	for (int i = 0; i < N; ++i)
	{
		const auto value = myList[i];
		for (int j = 0; j < N; ++j)
		{
			if (i == j)
				continue;

			const auto target = myList[j];

			if ((value.first < target.first) && (value.second < target.second))
				people[i]++;
		}
	}

	for(int i=0; i<N; ++i)
		cout << people[i] + 1 << " ";

	return 0;
}
