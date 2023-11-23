#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <chrono>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// 카드 2

	int N; cin >> N;

	std::queue<int> myQueue;
	bool isTrash = true;

	// 코드 성능 측정 시작
	auto start = std::chrono::high_resolution_clock::now();

	// 카드 세팅
	for (int i = 1; i <= N; ++i)
	{
		myQueue.push(i);
	}

	// 로직 시작
	while (myQueue.size() != 1)
	{
		// 1. 버리고 넣고 하는 작업을 반복
		myQueue.pop();
		myQueue.push(myQueue.front());
		myQueue.pop();

		/*
		// 방법 2. 부울값에 맞춰 버리고 넣고를 작업한다
		// 버리는 경우
		if (isTrash)
		{
			myQueue.pop();
			isTrash = false;
		}
		// 아래로 넣는 경우
		else
		{
			myQueue.push(myQueue.front());
			myQueue.pop();
			isTrash = true;
		}
		*/
	}

	cout << myQueue.front() << '\n';

	// 코드 성능 측정 끝
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> duration = end - start;

	std::cout << "실행 시간: " << duration.count() << " 초" << std::endl;

	return 0;
}