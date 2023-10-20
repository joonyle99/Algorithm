#include <iostream>

#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// 걷기

	// 학교(0,0) -> 집(x,y)
	// 가로 / 세로 / 대각선 이동 가능
	// 집까지 가는데 걸리는 '최소 시간'?

	// 집의 위치 X, Y
	// 한 블록 가는데 걸리는 시간 W
	// 한 블록 대각선 이동 시간 S

	// 시간 제한 : 2초
	// 1 <= x,y <= 10억
	// 1 <= w,s <= 10000
	// 엄청 커다란 수의 연산이 나올 것이므로 long long을 사용한다.

	long long x, y; cin >> x; cin >> y;
	long long w, s; cin >> w; cin >> s;

	// 더 큰 수를 오른쪽에 둔다.
	// std::max or std::min 같은걸 사용하지 않아도 된다.
	if (x > y)
		std::swap(x, y);

	// 축 이동만 하는 경우
	long long res = (x + y) * w;

	/// 경우의 수를 완벽하게 나눈다..
	/// 너무 싫다 경우의 수,, 문제를 꼼꼼하게 생각하고 완벽하게 이해해야한다. 반례까지

	// 대각선 이동을 하는 경우
	if (s < 2 * w)
	{
		// 대각선이 더 느린 경우
		if (s > w)
		{
			res = x * s + (y - x) * w;
		}
		// 대각선이 더 빠른 경우
		else
		{
			// 짝수라면
			if ((x + y) % 2 == 0)
			{
				res = y * s;
			}
			// 홀수라면
			else
			{
				res = (y - 1) * s + w;
			}
		}
	}

	cout << res << endl;

	return 0;
}