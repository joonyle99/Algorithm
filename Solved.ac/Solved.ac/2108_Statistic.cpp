#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <algorithm>
#include <math.h>

using std::cin;
using std::cout;

bool compare(std::pair<int, int> a, std::pair<int, int> b)
{
	if(a.second == b.second)
		return a.first < b.first;

	return a.second > b.second;
}

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : 통계학

	int N; cin >> N;

	float average;
	int midian;
	int mode;
	int range;

	std::vector<int> numberArr(N);
	int countArr[8001] = { 0, };

	int sum = 0;

	for (int i = 0; i < N; ++i)
	{
		int integer; cin >> integer;
		numberArr[i] = integer;

		sum += integer;
		countArr[integer + 4000]++;
	}

	// 산술 평균
	if(sum > 0)
	{
		average = round(static_cast<float>(sum) / N);
	}
	else
	{
		float EditableAverage = static_cast<float>(sum) / N;

		if (EditableAverage > -1)
			EditableAverage = 0.f;

		average = round(EditableAverage);
	}
	cout << average << '\n';

	// 중간값
	std::sort(numberArr.begin(), numberArr.end());
	midian = numberArr[N / 2];
	cout << midian << '\n';

	// 최빈값
	int max = INT32_MIN;
	std::vector<std::pair<int, int>> modeArr;
	for (int i = 0; i < 8001; ++i)
	{
		if (countArr[i] >= max)
		{
			max = countArr[i];
			int tempMode = i - 4000;
			modeArr.emplace_back(tempMode, countArr[i]);
		}
	}
	std::sort(modeArr.begin(), modeArr.end(), compare);
	if (modeArr[0].second == modeArr[1].second)
		mode = modeArr[1].first;
	else
		mode = modeArr[0].first;
	cout << mode << '\n';

	// 범위
	range = numberArr[N - 1] - numberArr[0];
	cout << range << '\n';

	return 0;
}
