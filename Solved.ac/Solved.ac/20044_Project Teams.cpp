#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// Project Teams

	// 각 학생들의 코딩 역량은 모두 다르다.
	// 팀원 코딩 역량의 합을 최대한 일정하게 유지
	// 학생수는 2n

	// 시간 제한 : 0.5초
	// N : 2 * n = 10,000회
	// -> 0.5초 동안 5천만번 연산 실행 가능
	// -> 10000 * 10000 = 1억이므로 O(N^2) 알고리즘으로 설계 불가능
	// -> O(N) or O(NlogN) 가능

	int n; cin >> n;
	int arr[10001];

	for (int i = 1; i <= 2 * n; ++i)
		cin >> arr[i];

	// '가장 큰 코딩역량과 가장 작은 역량의 합을 구하기 위해 정렬이 필요'
	// 코딩 역량 오름차순 정렬
	std::sort(arr + 1, (arr + 2 * n) + 1);

	// min값이 충분히 커야한다.
	// 두 학생의 코딩 역량의 합이 min보다 높은 경우만 있는 경우 min의 값이 올바르지 않게 출력된다.
	int min = arr[1] + arr[2 * n];

	for (int i = 1; i <= 2 * n; ++i)
	{
		if (min >= (arr[i] + arr[2 * n - i + 1]))
			min = arr[i] + arr[2 * n - i + 1];
	}

	cout << min << endl;

	return 0;
}