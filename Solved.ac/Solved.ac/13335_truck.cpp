#include <bits/stdc++.h>
using namespace std;

int n, w, L;
queue<int> a;
deque<pair<int, int>> b;		// deque는 인덱스로 접근할 수 있다

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : 트럭

	cin >> n >> w >> L;
	for (int i = 0; i < n; ++i) {
		int weight; cin >> weight;
		a.push(weight);
	}

	int time = 0;
	int sum = 0;

	while (true) {

		if (a.empty() && b.empty())
			break;

		// 1초 경과
		time++;

		// 다리 위에 올라가 있는 트럭들을 한 칸씩 이동시킨다
		for (int i = 0; i < b.size(); ++i) {
			b[i].second++;
		}

		// 다리를 끝까지 지나간 트럭들을 다리에서 제거한다
		while (!b.empty() && b.front().second > w) {
			sum -= b.front().first;
			b.erase(b.begin());
		}

		if (a.empty()) continue;				// 더이상 트럭이 남아있지 않은 경우 스킵
		if (sum + a.front() > L) continue;		// 트럭이 남아있지만, 하중이 더이상 못 버티는 경우 스킵
		if (b.size() + 1 > w) continue;			// 트럭이 남아있지만, 다리가 꽉찬 경우 스킵

		// 다리 위에 입성한다
		sum += a.front();
		b.push_back({ a.front(), 1 });
		a.pop();
	}

	cout << time;

	return 0;
}
