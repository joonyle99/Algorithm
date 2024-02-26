#include <bits/stdc++.h>
using namespace std;

int n = 10;
int arr[1000001] = { 15, 25, 22, 357, 16, 23, -53, 12, 46, 3 };
int tmp[1000001] = {};

// 1. Stable Sort의 성질을 가지고 있다
// 이 성질을 만족시키려면
// 앞 리스트에서 현재 보는 원소와 뒷 리스트에서 현재 보는 원소의 우선순위가 같을 때
// 앞 리스트의 원소를 먼저 보내주는 작업을 merge sort에서 자연스럽게 했다 (왼쪽부터 재귀적으로 돌아갔다)
void merge(int st, int en)
{
	int mid = (st + en) / 2;
	int leftIndex = st;
	int rightIndex = mid;
	for (int i = st; i < en; ++i)
	{
		// leftIndex가 꽉찬 경우
		if (leftIndex >= mid) tmp[i] = arr[rightIndex++];
		// rightIndex가 꽉찬 경우
		else if (rightIndex >= en) tmp[i] = arr[leftIndex++];
		// left의 값이 right의 값 보다 작은 경우
		else if (arr[leftIndex] < arr[rightIndex]) tmp[i] = arr[leftIndex++];
		else tmp[i] = arr[rightIndex++];
	}
	for (int i = st; i < en; ++i)
	{
		arr[i] = tmp[i];
	}
}

void merge_sort(int st, int en)
{
	if (st + 1 == en) return;
	int mid = (st + en) / 2;
	merge_sort(st, mid);
	merge_sort(mid, en);
	merge(st, en);
}

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	merge_sort(0, n);

	for (int i = 0; i < n; i++) cout << arr[i] << ' ';  // -53 3 12 15 16 22 23 25 46 357

	return 0;
}
