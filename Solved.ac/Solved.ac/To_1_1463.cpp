#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Solution(int& x)
{
	int cnt = 0;

	// x -> 1
	while (x != 1)
	{
		// 3으로 나누어 떨어지면 3으로 나눈다
		if (x % 3 == 0)
		{
			x /= 3;
		}
		// 2로 나누어 떨어지면 2로 나눈다
		else if (x % 2 == 0)
		{
			x /= 2;
		}
		// 1을 뺀다
		else
		{
			x -= 1;
		}

		// 연산을 사용한 횟수 증가
		cnt++;
	}

	return cnt;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N; cin >> N;

	// 연산을 하는 최소 횟수를 출력
	std::cout << Solution(N) << std::endl;

	return 0;
}