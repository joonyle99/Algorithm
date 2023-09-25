#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Player
{
	int number;
	int position;
	int worth;

	friend ostream& operator << (const ostream& os, const Player& player);
};


ostream& operator << (ostream& os, const Player& player)
{
	os << "number / position / worth : " << player.number << " / " << player.position << " / " << player.worth << '\n';

	return os;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// N : 선수의 수
	// K : after year
	int N, K;
	cin >> N >> K;

	vector<Player> players(N);

	// 초기화 : 팀은 총 11명, 포지션 번호는 1 ~ 11
	for (int i = 0; i < N; ++i)
	{
		int p, w;
		cin >> p >> w;

		players[i].number = i + 1;
		players[i].position = p;
		players[i].worth = w;
	}

	while (K > 0)
	{
		for (int i = 0; i < N; ++i)
		{
			if (players[i].position == 1)
			{

			}
		}









		K--;
	}

	/*
	for (int i = 0; i < N; ++i)
	{
		cout << players[i] << endl;
	}
	*/

	return 0;
}