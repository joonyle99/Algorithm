#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N; cin >> N;
	int K; cin >> K;

	// 요세푸스의 문제
	// (N, K) - 요세푸스 순열

	vector<int> arr(N, 0);
	int cnt = N;

	// 초기화
	for (int i = 0; i < N; ++i)
		arr[i] = i + 1;

	int index = 0;

	// 사람이 다 없어질 때까지 계속 삭제
	while (cnt > 0)
	{
		if (K > cnt)
			K %= cnt;

		index += K;

		cout << arr.at(index - 1) << endl;
		arr.erase(arr.begin() + index - 1);

		cnt--;
	}

	return 0;
}