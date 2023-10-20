#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool Compare(pair<int, int> a, pair<int, int> b)
{
	// 종료 시간이 같을 때, 시작 시간이 더 작은 순서대로 정렬되도록 한다.
	if (a.second == b.second)
		return a.first < b.first;

	return a.second < b.second;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// 회의실 배정

	// 조건
	// 1. 각 회의는 겹치지 않는다.
	// 2. 회의는 시작하면 중단이 불가하다.
	// 3. 회의가 끝나는 동시에 다음 회의가 시작될 수 있다.
	// 4. 회의 시작 시간과 종료 시간이 같을 수 있다.

	// e.g) (1, 4) -> (4, 4) 가능

	// 첫째 줄에 회의의 수 N(1 ≤ N ≤ 100,000)이 주어진다
	int n; cin >> n;
	int cnt = 0;
	int time = 0;
	vector<pair<int, int>> pairs(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> pairs[i].first;
		cin >> pairs[i].second;
	}

	// 회의 종료 시간이 적은 순서대로 정렬하기
	std::sort(pairs.begin(), pairs.end(), Compare);

	// 첫번째 회의
	time = pairs[0].second;
	cnt++;

	for (int i = 1; i < n; i++)
	{
		// 종료 시간이 다음 회의 시작 시간보다 작거나 같으면
		if (time <= pairs[i].first)
		{
			// 그 회의를 할 수 있고, 종료 시간을 저장한다.
			time = pairs[i].second;
			cnt++;
		}
	}

	// 최대 사용할 수 있는 회의의 최대 개수를 출력
	cout << cnt << endl;

	return 0;
}