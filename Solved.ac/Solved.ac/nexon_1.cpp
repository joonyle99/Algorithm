#include <bits/stdc++.h>
using namespace std;

int N, Q;
string M;
int S, E;
vector<int> preSum;

int Solution(string m, int s, int e) {

	int left = s;
	int right = e;

	// 왼쪽에서부터 첫번째 '*'를 찾는다
	while (left <= e && M[left] != '*') {
		left++;
	}

	// 오른쪽에서부터 첫번째 '*'를 찾는다
	while (right >= s && M[right] != '*') {
		right--;
	}

	// 교차했다는 것은 매듭이 존재하지 않는다는 뜻임
	if (left > right) return 0;

	// 미리 계산해둔 합을 이용해 구슬의 합을 계산
	return preSum[right + 1] - preSum[left];
}

/// <summary>
/// 전체 문자열에 대한 preSum을 계산하는 함수
/// </summary>
void PreSumProcess() {
	preSum.resize(N + 1, 0);			// 계산의 편의성을 위해 0번 인덱스는 비워둔다
	for (int i = 0; i < N; ++i) {
		preSum[i + 1] = preSum[i];		// 이전 값을 가져온다
		if (M[i] == '*') continue;		// '*'는 이전 값을 가지고 있는 상태에서 머문다
		preSum[i + 1] += M[i] - '0';	// 이전 값에 누적시킨다
	}
}

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : 구슬이 서말이라도

	cin >> N;       // 문자열 개수
	cin >> M;       // 문자열
	cin >> Q;       // 자르기 횟수

	PreSumProcess();

	while (Q--) {
		cin >> S >> E;
		cout << Solution(M, S, E) << '\n';
	}

	return 0;
}