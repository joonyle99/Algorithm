#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N; cin >> N;

	std::vector<int> dp(N + 1);

	// bottom-up
	dp[1] = 0;
	for (int i = 2; i <= N; ++i)
	{
		dp[i] = dp[i - 1] + 1;
		if (!(i % 3)) dp[i] = std::min(dp[i], dp[i / 3] + 1);
		if (!(i % 2)) dp[i] = std::min(dp[i], dp[i / 2] + 1);
	}

	std::cout << dp[N] << std::endl;

	return 0;
}