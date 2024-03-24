#include <bits/stdc++.h>

int n = 10;
int heightArr[1000001] = { 15, 25, 22, 357, 16, 23, -53, 12, 46, 3 };

using namespace std;

// merge_sort 처럼 재귀적으로 구현되는 정렬
// 매 작업마다 pivot을 제자리로 보내야 한다
void quick_sort(int st, int en) // arr[st::en]를 정렬한다
{
	if (st + 1 >= en) return;

	int pivot = st;
	int left = st + 1;
	int right = en - 1;

	while (true)
	{
		while (heightArr[pivot] >= heightArr[left] && left <= right) left++;
		while (heightArr[pivot] < heightArr[right] && left <= right) right--;

		if (left > right) break;

		swap(heightArr[left], heightArr[right]);
	}

	swap(heightArr[pivot], heightArr[right]);
	swap(pivot, right);

	quick_sort(st, pivot);
	quick_sort(pivot + 1, en);
}

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	quick_sort(0, n);

	for (int i = 0; i < n; i++) cout << heightArr[i] << ' ';

	return 0;
}
