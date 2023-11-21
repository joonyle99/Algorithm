#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	std::vector<int> arr;

	int a, b;
	cin >> a >> b;

	// 최대 공배수 계산을 위한 변수
	const int abMul = a * b;

	// 최대 공약수와 최소 공배수

	/// a와 b중 더 작은값 구하기

	// 1. b가 크면, 더 작은 a를 b에 넣어주는 방식
	if (a < b) std::swap(a, b);

	/// 최대 공약수 구하기

	// 1 - 1) 브루트포스 방식 (멍청한 방식)
	/*
	while (a > 0)
	{
		bool hasNum = false;

		// 작은수를 기준으로 약수를 찾는다
		for (int i = 2; i <= b; ++i)
		{
			// a : 24 b : 12
			// 17 51

			if (a % i == 0 && b % i == 0)
			{
				a /= i;
				b /= i;
				arr.push_back(i);
				hasNum = true;
				break;
			}
		}

		// 약수가 없다면 종료
		if (!hasNum)
			break;
	}

	// 최대 공약수 계산
	int gcd = 1;
	for (const auto v : arr)
		gcd *= v;
	*/

	// 1 - 2) 브루트포스 방식 (그나마 나은 방식)
	// 그냥 작은 수 기준으로 나눠보면 되잖아.. 이 바보야
	/*
	int gcd = 1;
	for (int i = b; i >= 2; --i)
	{
		if ((a % i == 0) && (b % i == 0))
		{
			gcd = i;
			break;
		}
	}
	*/

	// 1 - 3) 유클리드 호제법
	// 1. 큰 숫자를 작은 숫자로 mod연산을 한다.
	// 2. 작은 숫자를 1번에서 구한 나머지 mod연산을 한다.
	// 3. 위 과정을 mod연산의 결과가 0이 나올때 까지 계속 반복한다.
	// 4. 이때 나누는 수로 사용된 수가 두 수의 최대공약수가 된다.
	while (true)
	{
		int c = a % b;

		if (c == 0)
			break;

		a = b;
		b = c;
	}
	int gcd = b;

	// 2) 최대 공배수 계산 (두 수의 곱을 최대 공약수로 나눈값)
	int lcm = abMul / gcd;

	cout << gcd << endl;
	cout << lcm << endl;

	return 0;
}