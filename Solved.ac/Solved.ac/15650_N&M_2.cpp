#include <bits/stdc++.h>
using namespace std;

int N, M;
bool isUsed[10];
int answerArray[10];

void Func(int curCount)
{
	// 1부터 N까지 자연수 중에서 '중복 없이' M개를 고른 수열
	// 고른 수열은 오름차순이어야 한다.

	// M개의 배열을 출력한다
	if (curCount == M)
	{
		// 배열에 원하는 개수의 요소가 찬 후, 한번에 출력한다
		for (int i = 0; i < curCount; i++) {
			cout << answerArray[i] << ' ';
		}

		cout << '\n';

		return;
	}

	for (int number = 1; number <= N; number++) {

		// 이미 사용된 것이면 스킵
		if (isUsed[number]) continue;

		// 이미 1개가 존재하는 경우에 새로 추가하려는 값이 더 큰지 확인한다
		if (curCount > 0) {
			if (answerArray[curCount - 1] > number)
				continue;
		}

		answerArray[curCount] = number;

		isUsed[number] = true;
		Func(curCount + 1);
		isUsed[number] = false;
	}
}

void Func2(int curCount, int startNumber)
{
	if (curCount == M)
	{
		// 배열에 원하는 개수의 요소가 찬 후, 한번에 출력한다
		for (int i = 0; i < curCount; i++) {
			cout << answerArray[i] << ' ';
		}

		cout << '\n';

		return;
	}

	for (int number = startNumber; number <= N; number++) {
		answerArray[curCount] = number;
		Func2(curCount + 1, number + 1);        // 다음 수를 고를 때 현재 수보다 큰 수부터 시작하도록 했습니다. (오름차순 해결)
	}
}

bool isAlreadyUsed[10];
int resultArray[10];
void Func3(int curCount, int start)
{
	// M개를 모두 골랐다
	if (curCount == M) {
		for (int i = 0; i < curCount; i++) {
			cout << resultArray[i] << ' ';
		}
		cout << '\n';
		return;
	}

	// 백트래킹을 이용한 풀이
	for (int i = start; i <= N; i++) {
		if (isAlreadyUsed[i]) continue;
		resultArray[curCount] = i;
		isAlreadyUsed[i] = true;
		Func3(curCount + 1, i + 1);
		isAlreadyUsed[i] = false;
	}
}

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : N과 M (2)

	cin >> N >> M;

	Func2(0, 1);
	// Func3(0, 1);

	/*
	std::vector<int> arr(N, 1);
	for (int i = 0; i < M; i++) {
		arr[i] = 0;
	}

	do
	{
		for (int i = 0; i < N; i++) {
			if (arr[i] == 0) {
				cout << i + 1 << ' ';
			}
		}
		cout << '\n';
	} while (std::next_permutation(arr.begin(), arr.end()));
	*/

	return 0;
}
