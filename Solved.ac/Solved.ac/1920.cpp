#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/// <summary>
/// 이분 탐색 (바이너리 서치)
/// </summary>
/// <param name="targetArr"></param>
/// <param name="value"></param>
/// <returns></returns>
bool binarySearch(std::vector<int>& targetArr, int value)
{
	int first = 0;
	int last = targetArr.size() - 1;
	int mid = (first + last) / 2;

	// 이분탐색
	// 위에서 선언한 변수를 "사용"부터 먼저 한다
	// 다른 방법으로는 "계산" 후 "사용"한다.
	while (last > first)
	{
		// 중간 인덱스보다 왼쪽에 있는 경우
		if (value < targetArr[mid])
			last = mid - 1;
		// 중간 인덱스보다 오른쪽에 있는 경우
		else if (value > targetArr[mid])
			first = mid + 1;

		// mid index를 계산
		mid = (first + last) / 2;

		// 값이 일치하는지 판단
		if (value == targetArr[mid])
			return true;
	}

	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// 수 찾기

	int N; cin >> N;
	std::vector<int> arr(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];
	}

	std::sort(arr.begin(), arr.end());

	int M; cin >> M;
	for (int i = 0; i < M; ++i)
	{
		int value; cin >> value;

		// if (std::binary_search(arr.begin(), arr.end(), value))
		if (binarySearch(arr, value))
			printf("%d\n", true);
		else
			printf("%d\n", false);
	}

	return 0;
}