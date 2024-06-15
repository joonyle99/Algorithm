#include <bits/stdc++.h>
using namespace std;

int N, M;
int answerArray[10];
int storageArray[10];
bool isUsed[10005];

void Func(int curCount) {

	if (curCount == M) {
		for (int i = 0; i < curCount; i++) {
			cout << answerArray[i] << ' ';
		}
		cout << '\n';
		return;
	}

	// DFS 방식으로 끝까지 들어간다
	// 그렇기 때문에 전역 변수로 myArray를 사용할 수 있다 (덮어쓰기 방식으로)

	// 오름차순 정렬되어있는 숫자들을 하나씩 꺼낸다
	for (int targetIndex = 0; targetIndex < N; targetIndex++) {
		int targetNumber = storageArray[targetIndex];
		if (isUsed[targetNumber]) continue;
		answerArray[curCount] = targetNumber;
		isUsed[targetNumber] = true;			// 백트래킹의 포인트
		Func(curCount + 1);
		isUsed[targetNumber] = false;			// 백트래킹의 포인트
	}
}

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : N과 M (5)

	// 1. 1부터 N까지 자연수 중에서 M개를 고른 수열

	// 2. N개의 자연수는 모두 다른 수이다.

	// 3. N개의 수가 주어진다.
	// => 입력으로 주어지는 수는 10,000보다 작거나 같은 자연수이다.

	// 4. 똑같은 수를 사용하면 안된다.

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> storageArray[i];
	}

	// 오름차순 정렬 (NlogN)
	std::sort(storageArray, storageArray + N);

	Func(0);

	return 0;
}
