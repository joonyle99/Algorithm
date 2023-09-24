#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int L; cin >> L;
	string str; cin >> str;

	// Hashing Function
	// Sigma(ai * r^i) mod M

	long long result = 0;
	long long r = 1;

	// 문자열의 각 요소를 char로 읽어온다
	for (int i = 0; i < L; ++i)
	{
		constexpr int power = 31;

		/// Moduler 연산의 분배법칙을 사용해야 한다.
		
		// char는 정수형으로 표현이 되는데 -96을 해준다.
		int a = (static_cast<int>(str[i]) - 96) % 1234567891;

		if (i != 0)
			r *= power;

		r %= 1234567891;

		// Hashing 함수를 적용해 result에 저장한다.
		result += (a * r);
	}

	cout << result % 1234567891 << '\n';

	return 0;
}