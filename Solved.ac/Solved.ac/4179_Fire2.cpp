#include <bits/stdc++.h>
using namespace std;

int R, C;

string maze[1005];		// 공백을 사용하지 않고 문자열이 붙어있기 때문에, 자체적으로 char[] 문자열인 string 자료형을 사용한다
int dist1[1005][1005];	// 불의 전파 시간
int dist2[1005][1005];	// 지훈이의 이동 시간

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : 불!

	// #: 벽
	// .: 지나갈 수 있는 공간
	// J: 지훈이의 초기 위치
	// F: 불의 위치 (여러 개 가능)

	// 지훈이가 불이 도달하기 전에 미로를 탈출 할 수 없는 경우 IMPOSSIBLE 을 출력한다.
	// 지훈이가 미로를 탈출할 수 있는 경우에는 가장 빠른 탈출시간을 출력한다.

	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		// R행에 C개의 열을 -1로 채운다
		fill(dist1[i], dist1[i] + C, -1);
		fill(dist2[i], dist2[i] + C, -1);
	}
	for (int i = 0; i < R; i++) {
		cin >> maze[i];
	}
	queue<pair<int, int>> q1;
	queue<pair<int, int>> q2;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (maze[i][j] == 'F') {
				q1.push({ j, i });
				dist1[i][j] = 0;
			}
			if (maze[i][j] == 'J') {
				q2.push({ j, i });
				dist2[i][j] = 0;
			}
		}
	}
	// 불에 대한 BFS (불이 모든 경로에 대한 이동을 마친다. 이 과정에서 시간을 기록하고 지훈이의 이동 시간과 비교한다)
	while (!q1.empty()) {
		auto now = q1.front(); q1.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nextX = now.first + dx[dir];
			int nextY = now.second + dy[dir];
			if (nextX < 0 || nextX >= C || nextY < 0 || nextY >= R) continue;
			if (maze[nextY][nextX] == '#' || dist1[nextY][nextX] >= 0) continue;
			dist1[nextY][nextX] = dist1[now.second][now.first] + 1;
			q1.push({ nextX, nextY });
		}
	}
	// 지훈이에 대한 BFS
	while (!q2.empty()) {
		auto now = q2.front(); q2.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nextX = now.first + dx[dir];
			int nextY = now.second + dy[dir];
			if (nextX < 0 || nextX >= C || nextY < 0 || nextY >= R) {
				cout << dist2[now.second][now.first] + 1;
				return 0;
			}
			if (dist2[nextY][nextX] >= 0 || maze[nextY][nextX] == '#') continue;
			if (dist1[nextY][nextX] != -1 && dist1[nextY][nextX] <= dist2[now.second][now.first] + 1) continue; // 불의 전파 시간을 고려한다 (이미 지나갔으면 갈 수 없음)
			dist2[nextY][nextX] = dist2[now.second][now.first] + 1;
			q2.push({ nextX, nextY });
		}
	}

	cout << "IMPOSSIBLE"; // 여기에 도달했다는 것은 탈출에 실패했음을 의미.

	return 0;
}
