#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	/*
	 * t : 테스트 케이스 횟수
	 * n : 날짜 수
	 */

	 // 주식

	// 최대 이윤 : 1,000,000번 * 10,000원 = 100억원
	// 이 정수를 담기 위해서는 int가 아닌 long long을 사용한다.

	int t; cin >> t;

	for (int i = 0; i < t; ++i)
	{
		int n; cin >> n;
		std::vector<int> stockArr(n + 1);

		// 날 별 주식 입력
		for (int j = 1; j <= n; ++j)
			cin >> stockArr[j];

		long long result = 0;
		int maxPrice = stockArr[n];

		/// 최고 주가 기준으로 뒤에서부터 연산을 한다 (주식을 살지 말지 빠른 판별이 가능하다)
		for (int j = n - 1; j >= 1; --j)
		{
			if (maxPrice < stockArr[j])
				maxPrice = stockArr[j];
			else
				result += maxPrice - stockArr[j];
		}

		cout << result << endl;
	}

	return 0;
}