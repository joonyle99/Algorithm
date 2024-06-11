#include <bits/stdc++.h>
using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : 불

	// '.' : 빈 공간
	// '#' : 벽
	// '@' : 상근이의 시작 위치 (only one)
	// '*' : 불

	// 빌딩을 탈출하는데 가장 빠른 시간을 출력
	// 빌딩을 탈출할 수 없는 경우에는 "IMPOSSIBLE"을 출력

	int T; cin >> T;
	while (T--)
	{
		int w, h; cin >> w >> h;

		string board[1005];
		for (int row = 0; row < h; row++)
			cin >> board[row];

		vector<vector<int>> dist1(h); // 불이 지나가는 시간
		vector<vector<int>> dist2(h); // 상근이가 지나가는 시간

		// int dist[1005][1005] -> 4 * 1000 * 1000 byte == 4MB -> 1MB 초과

		for (int i = 0; i < h; i++)
		{
			dist1[i].resize(w, -1);
			dist2[i].resize(w, -1);
		}

		queue<pair<int, int>> q1;
		queue<pair<int, int>> q2;

		for (int row = 0; row < h; row++)
		{
			for (int col = 0; col < w; col++)
			{
				// fire start
				if (board[row][col] == '*')
				{
					// push to queue: first in first out
					q1.push({ col, row });
					// distance = 0
					dist1[row][col] = 0;
				}

				// sang-geun start
				if (board[row][col] == '@')
				{
					// push to queue: first in first out
					q2.push({ col, row });
					// distance = 0
					dist2[row][col] = 0;
				}
			}
		}

		// fire bfs
		while (!q1.empty())
		{
			auto now = q1.front(); q1.pop();
			for (int i = 0; i < 4; i++)
			{
				auto next = make_pair(now.first + dx[i], now.second + dy[i]);
				if (next.first < 0 || next.first >= w || next.second < 0 || next.second >= h) continue;
				if (board[next.second][next.first] == '#') continue;
				if (dist1[next.second][next.first] != -1) continue;
				dist1[next.second][next.first] = dist1[now.second][now.first] + 1;
				q1.push(next);
			}
		}

		string res = "IMPOSSIBLE";

		// sang-geun bfs
		while (!q2.empty())
		{
			auto now = q2.front(); q2.pop();
			for (int i = 0; i < 4; i++)
			{
				auto next = make_pair(now.first + dx[i], now.second + dy[i]);
				if (next.first < 0 || next.first >= w || next.second < 0 || next.second >= h)		// 건물 밖으로 나갔다는 것은 탈출했다는 뜻이다
				{
					res = to_string(dist2[now.second][now.first] + 1);
					goto end;
				}
				if (board[next.second][next.first] == '#') continue;								// 벽이 아니어야 한다
				if (dist2[next.second][next.first] != -1) continue;									// 내가 방문한 곳이 아니어야 한다
				if (dist1[next.second][next.first] != -1 && dist1[next.second][next.first] <= dist2[now.second][now.first] + 1) continue;	// 불이 지나갔으면 안된다, 그리고 내가 가는 시간보다 느리다면 가능하다.
				dist2[next.second][next.first] = dist2[now.second][now.first] + 1;
				q2.push(next);
			}
		}

		end:
		cout << res << '\n';
	}

	return 0;
}
