#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

struct Pos
{
	int x;
	int y;

	Pos(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
};

// x좌표가 증가하는 순서
// 같으면 y좌표가 증가하는 순서
bool compare(Pos a, Pos b)
{
	if (a.x < b.x)
		return true;
	else if (a.x == b.x)
	{
		if (a.y < b.y)
			return true;
	}

	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N; cin >> N;
	vector<Pos> arr;

	for (int i = 0; i < N; ++i)
	{
		int u; cin >> u;
		int v; cin >> v;

		arr.push_back(Pos(u, v));
	}

	std::sort(arr.begin(), arr.end(), compare);

	for (int i = 0; i < N; ++i)
	{
		cout << arr[i].x << " " << arr[i].y << '\n';
	}

	return 0;
}