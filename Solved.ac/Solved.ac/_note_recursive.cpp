#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> memo(1000, -1);	// Memoization

// 절차 지향적 사고 vs 귀납적 사고
// 
// 재귀적이라는 뜻은 귀납적이라는 것이다.
// 
// '올바른 쌍의 괄호 구하기'와 같은 문제에서는
// 스택에 '{'를 넣고 '}'가 나오면 스택이 비어있는 지 확인하고,
// 스택의 top이 짝이 맞는 지 확인하고 하는 것과 같이 '순서에 따라 해야할 일이 정해져 있는' 코딩을 해왔다.
//
// 재귀와 같이 귀납적인 방식이 어떤 차이가 있을까?
// 도미노를 예로 들어보면,, 1 ~ N번 까지의 도미노가 있을 때,
// 어떻게 모든 도미노가 쓰러질 수 있는 지를 물어보면,
// 1 -> 2 -> 3 -> 4 -> 5 ... 각각 연쇄적으로 이전의 도미노가 쓰러뜨리기 때문에
// 모든 도미노는 쓰러진다.. 와 같이 앞에 여러 예시들이 나열되고, 이후에 결과가 오는 방식이 바로
// 귀납적 추론 방식이다.
// 
// 수학적 귀납법으로 설명하자면,
// 1번 도미노가 쓰러지면, 2번 도미노가 쓰러진다.
// 2번 도미노가 쓰러지면, 3번 도미노가 쓰러진다.
// K번 도미노가 쓰러지면, K + 1번 도미노가 쓰러진다.
// 이렇게 설명할 수 있는데, 이러한 성질처럼
// 재귀 함수의 귀납적 방식에서도,
// 1번 도미노가 쓰러지면 2번 도미노가 쓰러진다.
// 그러므로 K번 도미노가 쓰러지면 K + 1번 도미노가 쓰러진다
// => 로 바로 갈 수 있어야 한다.
// 즉, 그동안 해오면 절차지향적 사고를 완전히 갈아 엎어야 한다.
//
// 재귀 함수의 조건에는
// 특정 입력에 대해 자기 자신을 호출하지 않고 종료되어야 하는 Base Condition or Base Case가 존재해야 하며,
// 모든 입력은 Base Condition으로 '수렴'해야 한다.
// i.g) if (n == 0) return
//
// 재귀에 대한 정보 1
// 함수의 인자로 어떤 것을 받고, 어디까지 계산한 후 자기 자신에게 넘겨줄지 '명확하게 정의'해야 한다.
//
// 재귀에 대한 정보 2
// 모든 재귀 함수는 '반복문'만으로 동일한 동작을 하는 함수를 만들어낼 수 있다.
// => 이 경우, 코드는 간결하지만, 메모리 / 시간에서는 손해를 본다는 단점이 있다.
//
// 재귀에 대한 정보 3
// fibo(n) = fibo(n-1) + fibo(n-2)
// 이와 같이 재귀 함수가 자기 자신을 여러 번 호출하게 되면,
// 반복되는 연산 과정으로 인해 굉장히 비효율적임
// Dynamic Programming, Memoization이 필요
//
// 재귀에 대한 정보 4
// 재귀 함수가 자기 자신을 부를 때,
// 스택 영역에 계속 return address가 누적되는데,
// 이렇게 되면 스택 메모리 1MB 제한 기준으로,
// 10만번의 재귀함수 호출로 인해 런타임 에러가 발생하고 만다. (그 사이에 지역변수도 들어가니까 더 적을수도 ..)
// 따라서 재귀를 깊게 들어가야 하는 경우, 반복문으로 해결해야 한다.

/// <summary>
/// 1부터 N까지의 수를 출력하는 함수
/// 
/// 절차지향적 사고방식
/// => 함수가 '동작하는 흐름'을 그대로 따라간다
///	=> 그동안 일반적으로 생각해 왔던 것
/// -> 3 입력
/// -> func1(2) 호출
/// -> func1(1) 호출
/// -> func1(0) 호출
/// -> 1 출력
/// -> 2 출력
/// -> 3 출력
/// 
/// 귀납적 사고방식
/// => 과정을 하나 하나 따라가는 대신, 귀납적인 사고를 통해서 이해해야 한다.
/// -> func1(1)이 1을 출력한다
/// -> func1(k)가 k, k-1, k-2 ... 1을 출력하면 (가정을 했다)
/// -> func1(k+1)은 k+1, k, k-1 ... 1을 출력한다
/// 
/// </summary>
/// <param name="N"></param>
void func1(int N) {
	if (N == 0) return;
	func1(N - 1);
	cout << N << ' ';
}

int func2(int a, int b, int m)
{
	int val = 1;
	while (b--) val *= a;
	return val % m;
}
int func3(int base, int exponent, int modular)
{
	// O(N)의 시간 복잡도
	// N: exponent / While(exponent--)
	// 만약에 exponent가 20억이라서 O(N)으로도 해결할 수 없을때는 어떻게 해야하나요?
	// cf O(N)의 경우 N이 1000만까지 커버가 가능하다

	int value = 1;
	while(exponent--) value = value * base % modular;		// 매 연산 시 modular operation의 결과값을 저장한다.
	return value;
}
ll func4(ll A, ll B, ll C)
{
	// A를 B번 곱한 수를 C로 나눈 나머지를 출력한다.

	// A^1 % C = X^1
	// A^2 % C = X^2
	// A^B % C = X^B

	// base condition
	if (B == 1) return A % C;
	// recursive
	ll res = func4(A, B / 2, C);
	// only keep modular value
	res = res * res % C;
	// exception (b is odd or even)
	if (B % 2 == 0) return res;
	// odd case
	return res * A % C;
}

//  1부터 N까지의 합을 구하는 함수
//
int Sum(int N)	// 인자를 활용해야 한다
{
	// N부터 1까지 줄여가며 합을 구한다
	if (N > 0) {
		N += Sum(N - 1);
	}

	return N;
}

// 팩토리얼 계산하기
// 
// 정수 n이 주어질 때, n! (팩토리얼)을 재귀 함수를 사용하여 계산하는 프로그램을 작성하시오.
// 예시 입력 : n = 5
// 예시 출력 : 120
// 0! = 1
// 1! = 1
int Factorial(int n)
{
	if (n == 0) return 1;
	n *= Factorial(n - 1);
	return n;
}

// 피보나치 수열
// 
// 정수 n이 주어질 때, 피보나치 수열의 n번째 항을 재귀 함수를 사용하여 구하는 프로그램을 작성하시오.
// 예시 입력 : n = 7
// 예시 출력 : 13
// 첫째 및 둘째항은 무조건 1
// Fibonacci (1) = 1
// Fibonacci (2) = 1
// Fibonacci (3) = Fibonacci (2) + Fibonacci (1)
// Fibonacci (k) = Fibonacci (k-1) + Fibonacci (k-2)
int Fibonacci(int n)
{
	if (n <= 2) return 1;

	if (memo[n] != -1) return memo[n]; // Memoization

	cout << "fibonacci(" << n << ")이 호출됨" << '\n';
	memo[n] = Fibonacci(n - 1) + Fibonacci(n - 2);

	return memo[n];
}

int main()
{

	return 0;
}