#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool Descending(int a, int b)
{
	return a > b;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// TOTO

	/*
	 * n : 과목 수 (1 <= n <= 100)
	 * m : 주어진 마일리지 (1 <= m <= 100)
	 * pArr : 각 과목에 신청한 사람의 수를 담은 배열
	 * lArr : 각 과목의 수강 인원
	 * mArr : 각 사람이 마일리지를 얼마나 넣었는지
	 */

	int n; cin >> n;
	int m; cin >> m;

	std::vector<int> pArr(n + 1);
	std::vector<int> lArr(n + 1);

	std::vector<vector<int>> mArr(n + 1);
	std::vector<int> bestChoiceArr(n + 1);

	size_t cnt = 0;

	for (int i = 1; i <= n; ++i)
	{
		cin >> pArr[i];
		cin >> lArr[i];

		mArr[i].resize(pArr[i] + 1);
		for (int j = 1; j <= pArr[i]; ++j)
		{
			cin >> mArr[i][j];
		}

		// 과목당 마일리지 내림차순 정렬
		std::sort(mArr[i].begin() + 1, mArr[i].end(), Descending);
	}

	// 수강신청 정원이 중요한 상황
	// 문닫고 들어가는게 가장 좋잖아? like me?

	for (int i = 1; i <= n; ++i)
	{
		/// 신청한 인원수 (pArr) 가 수강 가능 인원수 (lArr) 보다 적으면 그냥 1만 마일리지 넣어도 신청이 가능하다.

		if (pArr[i] < lArr[i])
			bestChoiceArr[i] = 1;
		else
			bestChoiceArr[i] = mArr[i][lArr[i]];
	}

	// 오름차순 정렬
	sort(bestChoiceArr.begin() + 1, bestChoiceArr.end());

	for(auto it = bestChoiceArr.begin() + 1; it != bestChoiceArr.end(); ++it)
	{
		m -= *it;

		if (m < 0)
			break;

		cnt++;
	}

	cout << cnt << endl;

	return 0;
}