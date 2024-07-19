// 코딩 테스트에서는 무엇보다 시간이 중요하다
// 따라서 알고리즘을 제외한 효율은 신경쓰지 않는다
// 공백, 줄바꿈, 등등 제발 그만좀 신경써라

#include <bits/stdc++.h>						// 1. 헤더파일 라이브러리
using namespace std;							// 2. 네임스페이스 std 사용
int length, target, answer[10005], duration;				// 3. 전역변수로 선언 (+ 배열 크기 넉넉하게 잡기)
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> length >> target;

	// 배열 사용하는 방식
	for (int i = 0; i < length; ++i) cin >> answer[i];
	for (int i = 0; i < length; ++i)
		if (answer[i] < target) cout << answer[i] << ' ';

	// 배열 사용하지 않는 방식
	while (length--) {							// 4. 단순히 횟수 반복이라면 while을 사용하자
		cin >> duration;
		if (duration < target) cout << duration << ' ';
	}

	return 0;
}