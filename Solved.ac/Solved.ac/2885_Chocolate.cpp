#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// 초콜릿 식사

	/*
	 * K : 적어도 먹어야하는 초콜릿 정사각형 개수
	 * C : 가장 작은 초콜릿의 크기
	 * Cnt : 쪼개야 하는 횟수
	 */

	int K; cin >> K;
	int C = 1;
	int Cnt = 0;

	// 가장 작은 초콜릿의 크기 구하기 : K와 같거나 큰 2의 제곱수
	while(true)
	{
		if (C >= K)
			break;
		C *= 2;
	}
	const int finalC = C;

	// 최소 몇 번 쪼개야 하는지 구하기
	while(K > 0)
	{
		// 여기 부분이 핵심 if문을 잘 써준다
		if (K < C)
		{
			C /= 2;
			Cnt++;
		}
		else
		{
			K -= C;
		}
	}

	cout << finalC << " " << Cnt << '\n';

	return 0;
}