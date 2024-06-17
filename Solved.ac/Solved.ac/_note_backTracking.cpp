#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// back tracking
// : '현재 상태'에서 '가능한 모든 후보군'을 따라 들어가며 탐색하는 알고리즘

// 미연시의 선택지를 고를때, '현재 상태에서 가능한 모든 선택지'를 다 플레이 해보는 방법..?
//
// 또는 오목을 두는 경우, '여기'에 둔다면 그에 해당하는 모든 경우의 수를 탐색하고 최적의 수를 두기 위해 '다시 돌아온다'
//

/// <summary>
/// 귀납적 사고방식으로 팩토리얼 해결하기
/// 
/// 1. factorial(0) = 1
/// 2. factorial(1) = 1 * factorial(0)
/// 3. factorial(2) = 2 * factorial(1)
/// 4. factorial(3) = 3 * factorial(2)
/// 5. factorial(4) = 4 * factorial(3)
/// ...
/// K. factorial(K) = K * factorial(K-1)
/// K+1. factorial(K+1) = (K+1) * factorial(K)
/// </summary>
/// <param name="n"></param>
/// <returns></returns>
int Factorial(int n) {
	// base condition
	if (n == 0) return 1;
	return n * Factorial(n - 1);
}

int Func_Test(int n, int m)
{
	// 1부터 N까지 '중복 없이' M개를 고른 수열의 모든 경우의 수 찾기
	// 
	// nPm = p(n,m) = n! / (n-m)!
	int numerator = Factorial(n);
	int denominator = Factorial(n - m);
	return numerator / denominator;
}

int N, M;
int arr[10];
bool visited[10];
void Recursive1(int count) {
	// base condition
	if (count == M) {
		for (int index = 0; index < count; index++) {
			cout << arr[index] << ' ';
		}
		cout << '\n';
		return;
	}
	// 1부터 N까지 순회
	for (int number = 1; number <= N; number++) {
		if (visited[number]) continue;
		visited[number] = true;
		arr[count] = number;
		Recursive1(count + 1);
		arr[count] = -1;
		visited[number] = false;
	}
}

void Solve_15649()
{
	cin >> N >> M;

	fill(arr, arr + 10, -1);
	Recursive1(0);

	// Func_Test(N, M);
}

int S;
int cnt = 0;
int arr2[21];
void Recursive2(int curIdx, int sum)
{
	// 모든 경우의 수를 순회했을 경우 (포함과 미포함의 과정을 거침)
	if (curIdx == N) {
		if (sum == S) {
			cnt++;
		}
		return;
	}

	// arr[curIdx]를 포함 할지 말지를 완전 탐색한다
	Recursive2(curIdx + 1, sum); // 포함하지 않고 그대로 넘겨준다
	Recursive2(curIdx + 1, sum + arr2[curIdx]); // 현재 보고있는 값을 더해준 값을 넘겨준다

	// 결국 2^N의 경우의 수를 모두 탐색한다.
}

/// <summary>
/// N개의 수를 넣을지 안 넣을지 경우의 수
/// 2^N
/// 공집합 제외 시 2^N - 1
/// 부분 수열의 합 문제와 같은 경우 사용된다
/// </summary>
void Solve_1182()
{
	cin >> N >> S;

	for (int i = 0; i < N; i++) {
		cin >> arr2[i];
	}

	Recursive2(0, 0);

	// S가 0인 경우에는 공집합의 경우에도 cnt++이 되기 때문에 예외 처리를 해줘야 한다.
	if (S == 0) cnt--;

	cout << cnt;
}

void myFunc(int curRow, int* myArray)
{
	// base condition
	if (curRow == N)
	{
		cnt++;
		return;
	}

	// (curRow, i)에 퀸을 놓는다
	for (int curCol = 0; curCol < N; curCol++)
	{
		// 놓을 수 없는 경우
		// 1. 같은 열에 있는 경우
		// 2. 같은 대각선에 있는 경우

		// (curRow, curCol)에 배치할 수 있는지 판단한다
		bool isAvailable = true;

		// 이전에 배치한 퀸과 비교한다
		for (int count = 0; count < curRow; count++)
		{
			int r = count;
			int c = myArray[count];

			if (curCol == c || curRow + curCol == r + c || curRow - curCol == r - c)
			{
				isAvailable = false;
				break;
			}
		}

		if (isAvailable)
		{
			myArray[curRow] = curCol;
			myFunc(curRow + 1, myArray);
		}
	}
}

void Solve_9663()
{
	cin >> N;
	int columnArray[25];
	myFunc(0, columnArray);
	cout << cnt;
}

int main()
{
	Solve_9663();


	return 0;
}