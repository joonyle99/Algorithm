#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int arr[3] = { 0, };

	while (true)
	{
		int max = -9999;

		for (int i = 0; i < 3; ++i)
		{
			cin >> arr[i];

			if (arr[i] >= max)
				max = arr[i];
		}

		if ((arr[0] == 0) && (arr[1] == 0) && (arr[2] == 0))
			break;

		if (max == arr[0]) {
			if (arr[0] * arr[0] == arr[1] * arr[1] + arr[2] * arr[2])
				cout << "right" << '\n';
			else
				cout << "wrong" << '\n';
		}
		else if (max == arr[1]) {
			if (arr[1] * arr[1] == arr[0] * arr[0] + arr[2] * arr[2])
				cout << "right" << '\n';
			else
				cout << "wrong" << '\n';
		}
		else if (max == arr[2]) {
			if (arr[2] * arr[2] == arr[1] * arr[1] + arr[0] * arr[0])
				cout << "right" << '\n';
			else
				cout << "wrong" << '\n';
		}
	}

	return 0;
}