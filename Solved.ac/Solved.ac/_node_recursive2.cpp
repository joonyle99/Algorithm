#include <bits/stdc++.h>
using namespace std;

/// <summary>
/// 가장 기본적인 방법으로, 값이 조금만 커져도
/// 1. int로는 해결할 수 없다는 문제점과
/// 2. O(N)의 시간복잡도라는 문제점이 존재한다.
/// 
/// 10 10 7 이 input으로 들어오면 1번 문제점으로 인해 해결이 불가능
/// 
/// </summary>
/// <param name="A"></param>
/// <param name="B"></param>
/// <param name="C"></param>
/// <returns></returns>
int func_1629_1(int A, int B, int C)
{
	int result = 1;
	while (B--) result *= A;
	return result % C;
}

/// <summary>
/// 나머지만 남기며 연산하는 방법으로 인해
/// 1번 문제가 해결된 모습
/// 
/// 10 10 7 도 해결된다
/// 
/// </summary>
/// <param name="A"></param>
/// <param name="B"></param>
/// <param name="C"></param>
/// <returns></returns>
int func_1629_2(int A, int B, int C)
{
	int result = 1;
	while (B--) result = result * A % C;	// 나머지만 남긴다
	return result;
}

using ll = long long;
/// <summary>
/// 인줄 알았지만, 아직 1번 문제가 완벽하게 해결되지 않았다
/// A, B, C가 각각 INT_MAX를 넘어선다면 유효하지 않으므로 long long type을 사용한다
/// </summary>
/// <param name="A"></param>
/// <param name="B"></param>
/// <param name="C"></param>
/// <returns></returns>
ll func_1629_3(ll A, ll B, ll C)
{
	ll result = 1;
	while (B--) result = result * A % C;	// 나머지만 남긴다
	return result;
}

/// <summary>
/// 이제 2번 문제점을 해결해야 하는데,
/// 시간 제한 0.5초, N: 2147483647 (약 21억)인 경우,
/// 
/// 1초에 컴퓨터가 연산할 수 있는 횟수 약 1억번 (10^8)
/// 따라서 해당 문제는 O(N)으로 해결할 수 없으며,
/// 
/// O(logN)의 시간 복잡도로 해결해야 하는 문제이다.
/// 
/// </summary>
/// <param name="A"></param>
/// <param name="B"></param>
/// <param name="C"></param>
/// <returns>A^B % C를 계산한 결과값을 반환한다</returns>
ll func_1629_4(ll A, ll B, ll C)
{
	// 어떻게 하면 O(logN)의 시간 복잡도로 계산할 수 있을까?

	// 수학적 성질을 이용한다
	// 1. a^n + a^n = a^2n
	// 2. a^b % c = x^1 이라면 a^2b % c = x^2가 된다.

	// 2번 성질에 대한 증명
	// x % y = z라고 했을때,
	// x = z + ky
	// x^2 = (z + ky)^2
	// x^2 = z^2 + 2zky + (ky)^2
	// -> 2zky + (ky)^2 부분은 y로 나누어 떨어지므로
	// => x^2 % y = z^2가 된다.

	// 수학적 귀납법 사고방식 이용
	// A^1 % C = ?를 구할 수 있고,
	// A^k % C = ?를 구할 수 있고,
	// A^(2k) % C = ?를 구할 수 있다면,	// 짝수
	// A^(2k+1) % C = ?를 구할 수 있다.	// 홀수

	// base condition
	if (B == 0) return 1;
	// x^2 % y = z^2 => x % y = z
	ll result = func_1629_4(A, B / 2, C);
	result = result * result % C;
	if (B % 2 == 0) return result;			// A^B % C 의 계산된 값을 반환한다.
	return result * A % C;					// A^(B+1) % C 의 계산된 값을 반환한다.
}

void Solve_1629()
{
	int A, B, C; cin >> A >> B >> C;
	cout << func_1629_4(A, B, C);
}

int main()
{
	Solve_1629();


	return 0;
}