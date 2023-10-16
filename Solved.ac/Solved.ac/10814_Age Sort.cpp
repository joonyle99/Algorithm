#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// 리스트로 만들기
	list<pair<int, string>> players;

	int N; cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int age; string name;
		cin >> age >> name;

		players.push_back({ age, name });
	}

	stable_sort(players.begin(), players.end(), [](const pair<int, string>& a, const pair<int, string>& b)
		{
			return a.first < b.first;
		});

	// map과 unordered_map은 key값을 기준으로 정렬되어 저장된다.
	for (auto player : players)
		cout << player.first << ' ' << player.second << '\n';

	return 0;
}