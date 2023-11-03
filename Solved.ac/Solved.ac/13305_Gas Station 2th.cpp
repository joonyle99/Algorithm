#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// 주유소 2th try

	/*
	 * n : 주유소 개수
	 * lengthArr : 주유소간 거리
	 * priceArr : 주유 가격
	 */

	///
	/// 주유소의 최대 개수 : 100,000
	///	주유소간 최대 거리 : 1,000,000,000 -> 오류 (총 거리)
	///	리터당 주유 가격 : 1,000,000,000
	///
	///	-> 최대 주유 비용 : 100,000 * 1,000,000,000 * 1,000,000,000 = 10^20 (경 다음인 해 단위)
	///
	/// -> 인줄 알았으나 "제일 왼쪽 도시부터 제일 오른쪽 도시까지의 거리는 1이상 1,000,000,000 이하의 자연수."
	///	-> "제일 왼쪽 도시부터 제일 오른쪽 도시까지의 거리"
	///	-> 각 도시간 거리가 아니라 총 거리였다.
	///
	///	-> 최대 주유 비용 : 100,000 (주유소 개수) * 100,000 (주유소간 거리) * 1,000,000,000 (주유 가격) = 10^15 (100경 이하 단위)
	///	-> long long으로 담을 수 있는 정수이다.
	///

	int n; cin >> n;

	std::vector<long long> lengthArr(n);
	std::vector<long long> priceArr(n + 1);

	// 도로의 길이 입력
	for (int i = 1; i <= n - 1; ++i)
		cin >> lengthArr[i];

	// 주유 가격 입력
	for (int i = 1; i <= n; ++i)
		cin >> priceArr[i];

	long long totalMoney = 0;

	// 마지막 주유소까지만 이동하면 되기 때문에 n - 1까지만 반복문을 돈다.
	for (int i = 1; i < n; ++i)
	{
		const long long curPrice = priceArr[i];		// 현재 주유소의 주유비
		int passedCnt = 0;							// 그냥 지나칠 주유소의 수


		/// 무시되는 조건이 있다. (무조건 주유를 하는 이유는 현재 주유소가 지나쳐온 주유소를 반영한 위치이기 때문이다)
		// 현재 주유소에서 다음 주유소까지 주유
		totalMoney += curPrice * lengthArr[i];

		// 지나칠 주유소 계산
		for (int j = i + 1; j < n; ++j)
		{
			// 현재 주유소가 다음 주유소보다 비싸면 미리 계산하지 않는다.
			if (curPrice > priceArr[j])
				break;

			// 다음 주유소보다 싸거나 가격이 같으면 다음 주유소에서 할 주유를 미리 한다.
			totalMoney += curPrice * lengthArr[j];
			passedCnt++;
		}

		i += passedCnt;
	}

	cout << totalMoney << endl;

	return 0;
}