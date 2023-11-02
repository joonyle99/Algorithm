#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// 체인

	/*
	 * N : 체인의 개수
	 */

	int N; cin >> N;

	std::vector<int> lengthArr(N + 1);

	for (int i = 1; i <= N; ++i)
	{
		cin >> lengthArr[i];
	}

	/// 그리디 알고리즘의 핵심이 되는 포인트 1 - 체인을 전부 소모시키면 연결고리의 개수가 줄기 때문에 오른차순 정렬을 사용.
	///	'입력 배열의 순서가 중요한지 판단'
	std::sort(lengthArr.begin(), lengthArr.end());

	/// 그리디 알고리즘의 핵심이 되는 포인트 2 - 필요한 연결고리의 개수와 고리가된 체인의 개수를 이용해 문제를 해결한다.
	///	다양한 예외가 존재할 것같이 생긴 복잡한 문제라도 자연스럽게 그 문제들이 해결되는 '단순화' 과정을 거쳐 쉽게 해결
	int needGoriCnt = N - 1;
	int totalGoriCnt = 0;

	for (int i = 1; i <= N; ++i)
	{
		int curChainCnt = lengthArr[i];

		// 체인의 길이만큼 돈다
		for (int j = 0; j < lengthArr[i]; ++j)
		{
			if (needGoriCnt == totalGoriCnt)
				break;

			// 체인을 고리로 만든다.
			curChainCnt--;
			totalGoriCnt++;

			// 체인을 전부 소진해 해체된 경우
			if (curChainCnt <= 0)
			{
				needGoriCnt--;
				break;
			}
		}


		if (needGoriCnt <= totalGoriCnt)
			break;
	}

	cout << totalGoriCnt << endl;

	return 0;
}