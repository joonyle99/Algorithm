#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 반복 처리를 위한 벡터
std::vector<int> visitedVec(1000000, 0);

int SquareFunc(int v, int e)
{
	int res = 1;

	for (int i = 0; i < e; ++i)
	{
		res *= v;
	}

	return res;
}

void DFS(int inputNumber, int p)
{
	visitedVec[inputNumber]++;

	// 3이 되는 순간, 반복되는 수는 값이 2로 정해졌기 때문에 Stop
	if (visitedVec[inputNumber] > 2)
		return;

	int res = 0;

	while (inputNumber > 0)
	{
		res += SquareFunc(inputNumber % 10, p);
		inputNumber /= 10;
	}

	DFS(res, p);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	/// 깊이 우선 탐색 (DFS) 문제
	// 반복 수열

	int A; cin >> A;
	int P; cin >> P;

	// 57, 74, 65, 61, 37, 58, 89, 145, 42 ..
	// 5^2 + 7^2 = 74

	// 반복되는 부분을 제외했을 때, 수열에 남게 되는 수들의 개수를 구하는 프로그램을 작성

	// D[n] = D[n-1]의 각 자리의 숫자를 P번 곱한 수들의 합을 구하는 함수
	DFS(A, P);

	int cnt = 0;
	for(const auto v : visitedVec)
	{
		// 반복되지 않은 수를 선별해 카운트한다.
		if (v == 1)
			cnt++;
	}

	cout << cnt << endl;

	return 0;
}