#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, X;
	cin >> N >> X;

	vector<int> vector(N);
	for (int i = 0; i < N; ++i)
		cin >> vector[i];

	for (const auto v : vector)
	{
		if (v < X)
			cout << v << ' ';
	}

	return 0;
}