#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// 팰린드롬수
	// 무의미한 0이 앞에 올 수 없다고 하자.

	while (true)
	{
		string integer; cin >> integer;

		if (integer == "0")
			break;

		string answer = "yes";

		for (int i = 0; i < integer.length(); ++i)
		{
			if (integer[i] != integer[integer.length() - 1 - i])
			{
				answer = "no";
				break;
			}
		}

		cout << answer << endl;
	}


	return 0;
}