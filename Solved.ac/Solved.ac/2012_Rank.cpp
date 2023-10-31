#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int Abs(int v)
{
	if (v < 0)
		return v *= -1;

	return v;
}

bool AscendingFunc(int a, int b)
{
	return a < b;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// 등수 매기기

	/*
	 * N : 학생 수 (1 <= N <= 500,000)
	 */

	 // 최대 입력 횟수 N : 500,000개
	 // 시간 제한 : 2초

	 // 사용 가능 알고리즘의 시간복잡도 : O(NlgN) 이상

	int N; cin >> N;

	// 필요한 변수
	std::vector<int> guessRankArr(N + 1);
	long long complainValue = 0;

	// 예상 등수 입력
	for (int i = 1; i <= N; ++i)
		cin >> guessRankArr[i];

	// 예상 등수 오름차순 정렬
	/// 0번째 인덱스를 비워놓기 위해 N + 1개의 배열을 생성했는데, 이 부분을 고려해 0번째 인덱스를 제외한 정렬을 실행해야 한다.
	std::sort(guessRankArr.begin() + 1, guessRankArr.end(), AscendingFunc);

	for (int i = 1; i <= N; ++i)
		complainValue += Abs(i - guessRankArr[i]);

	cout << complainValue << '\n';

	return 0;
}