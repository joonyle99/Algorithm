#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// 카약과 강풍

	// TODO : 문제를 해결했지만, 좀 더 쉽게 푸는 방법을 모색하자 -> vector<bool>을 3개나 사용했다. 하나의 vector<int>을 사용하고 그 안에 '카누의 개수'를 넣는다

	// 다행히 일부 팀은 혹시 모를 사태에 대비해서 카약을 하나 더 경기장에 들고 왔다
	// 자신의 바로 다음이나 전에 경기하는 팀에게만 카약을 빌려주려고 한다
	// 팀 4는 여분의 카약을 3이나 5에게만 빌려줄 수 있다
	// 다른 팀에게서 받은 카약은 또 다른 팀에게 빌려줄 수 없다.
	// 카약을 하나 더 가져온 팀의 카약이 손상되었다면, 여분의 카약으로 경기에 출전하게되고, 이 카약은 다른 팀에게 빌려줄 수 없다.
	// 카약이 부서진 팀과 하나 더 가져온 팀이 주어진다. 카약을 적절히 빌렸을 때 출발하지 못하는 팀의 최솟값은 몇 팀인지 구하는 프로그램

	// 시간 제한 1초
	// 입력 횟수 N :

	int n; cin >> n;
	int s; cin >> s;
	int r; cin >> r;

	int ableTeam = 0;

	vector<bool> damagedTeam(n + 1);
	vector<bool> additionalTeam(n + 1);
	vector<bool> remainTeam(n + 1, true);

	// 손상된 팀의 번호
	for (int i = 0; i < s; ++i)
	{
		int teamNum; cin >> teamNum;
		damagedTeam[teamNum] = true;
	}

	// 카약을 더 가져온 팀의 번호
	for (int i = 0; i < r; ++i)
	{
		int teamNum; cin >> teamNum;
		additionalTeam[teamNum] = true;
	}

	/// 출전 가능한 팀을 찾는게 빠를지
	///	출전 불가능한 팀을 찾는게 빠를지

	// 모든 팀을 순회하면서 카약을 보유한 팀은 그냥 먼저 출전해
	for (int i = 1; i <= n; ++i)
	{
		// 카약이 손상되지 않았다면 그냥 먼저 출전
		if (!damagedTeam[i])
		{
			remainTeam[i] = false;
			ableTeam++;
		}
		// 카약이 손상됐지만 추가 여분이 있다면 먼저 출전
		else if (additionalTeam[i])
		{
			additionalTeam[i] = false;
			remainTeam[i] = false;
			ableTeam++;
		}

		/// 이렇게 하면 팀의 카약이 손상이 없어서 이미 출발했지만 추가 카약이 있는 경우가 존재한다
	}

	for (int i = 1; i <= n; ++i)
	{
		// 남아있는 팀을 순회 (카약이 손상되었고, 추가 카약도 없는 경우)
		if (remainTeam[i])
		{
			// 앞이나 뒤의 팀이
			if (i == 1)
			{
				// 출전 가능한 경우
				if (!remainTeam[i + 1] && additionalTeam[i + 1])
				{
					ableTeam++;
					additionalTeam[i + 1] = false;
				}
			}
			else if (i == n)
			{

				// 출전 가능한 경우
				if (!remainTeam[i - 1] && additionalTeam[i - 1])
				{
					ableTeam++;
					additionalTeam[i - 1] = false;
				}
			}
			else
			{
				// 출전 가능한 경우
				if (!remainTeam[i - 1] && additionalTeam[i - 1])
				{
					ableTeam++;
					additionalTeam[i - 1] = false;
				}
				else if (!remainTeam[i + 1] && additionalTeam[i + 1])
				{
					ableTeam++;
					additionalTeam[i + 1] = false;
				}
			}
		}
	}

	cout << n - ableTeam << '\n';

	return 0;
}