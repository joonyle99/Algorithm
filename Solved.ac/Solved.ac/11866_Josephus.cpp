#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N; cin >> N;
	int K; cin >> K;

	// 요세푸스의 문제
	// (N, K) - 요세푸스 순열
	queue<int> queue;

	// 초기화
	for (int i = 0; i < N; ++i)
		queue.push(i + 1);

	cout << "<";

	while (!queue.empty())
	{
		for (int i = 0; i < K; ++i)
		{
			if (i == K - 1)
			{
				if (queue.size() == 1)
					cout << queue.front();
				else
					cout << queue.front() << ", ";

				queue.pop();
			}
			else
			{
				queue.push(queue.front());
				queue.pop();
			}
		}
	}

	cout << ">" << '\n';

	return 0;
}