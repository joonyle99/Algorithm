#include <bits/stdc++.h>
using namespace std;

int n = 10;
int heightArr[1000001] = { 15, 25, 22, 357, 16, 23, -53, 12, 46, 3 };
int tmp[1000001]; // merge 함수에서 리스트 2개를 합친 결과를 임시로 저장하고 있을 변수

// mid = (st+en)/2라고 할 때 arr[st:mid], arr[mid:en]은 이미 정렬이 되어있는 상태일 때 arr[st:mid]와 arr[mid:en]을 합친다.
void merge(int st, int en) {
	int mid = (st + en) / 2;

	// arr[st:mid]를 정렬한다
	// arr[mid:en]를 정렬한다

	// O(N)의 시간복잡도로 두 리스트를 합칠 수 있다
	int aIndex = st;
	int bIndex = mid;
	vector<int> vec;
	for (int i = st; i < en; ++i) {
		if (aIndex >= mid) tmp[i] = heightArr[bIndex++];
		else if (bIndex >= en) tmp[i] = heightArr[aIndex++];
		else if (heightArr[aIndex] <= heightArr[bIndex]) tmp[i] = heightArr[aIndex++];
		else tmp[i] = heightArr[bIndex++];
		vec.push_back(i);
	}
	for (const auto i : vec)
	{
		heightArr[i] = tmp[i];
	}
}

void merge_BaaaarkingDog(int st, int en) {
	int mid = (st + en) / 2;

	// arr[st:mid]를 정렬한다
	// arr[mid:en]를 정렬한다

	// O(N)의 시간복잡도로 두 리스트를 합칠 수 있다
	int aIndex = st;
	int bIndex = mid;
	for (int i = st; i < en; ++i) {
		if (aIndex >= mid) tmp[i] = heightArr[bIndex++];
		else if (bIndex >= en) tmp[i] = heightArr[aIndex++];
		else if (heightArr[aIndex] <= heightArr[bIndex]) tmp[i] = heightArr[aIndex++];
		else tmp[i] = heightArr[bIndex++];
	}
	for (int i = st; i < en; ++i)
	{
		heightArr[i] = tmp[i];
	}
}

// arr[st:en]을 정렬하고 싶다.
void merge_sort(int st, int en) {
	if (en == st + 1) return; // 길이 1인 경우
	int mid = (st + en) / 2;
	merge_sort(st, mid); // arr[st:mid]을 정렬한다.
	merge_sort(mid, en); // arr[mid:en]을 정렬한다.
	// merge(st, en); // arr[st:mid]와 arr[mid:en]을 합친다.
	merge_BaaaarkingDog(st, en); // arr[st:mid]와 arr[mid:en]을 합친다.
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	merge_sort(0, n);
	for (int i = 0; i < n; i++) cout << heightArr[i] << ' ';  // -53 3 12 15 16 22 23 25 46 357
}