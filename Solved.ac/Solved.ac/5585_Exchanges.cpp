#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// 거스름돈

	// 500, 100, 50, 10, 5, 1원이 '충분히' 있다.
	// 거스름돈의 개수가 가장 적게 잔돈을 준다
	// 1000원을 냈을 때, 잔돈의 개수

	int payment; cin >> payment;
	int res = 0;

	int rest = 1000 - payment;

	// '가장 적게 잔돈을 준다' 라는 말은
	// 가치가 큰 화폐를 최대한 많이 주면 된다는 말과 같다.
	// 500원부터 1원까지 가치가 큰 순으로 준다.

	// 잔여액이 있는경우 계속해서 거스름돈을 계산한다
	while (rest > 0)
	{
		if (rest - 500 >= 0)
		{
			rest -= 500;
			res++;
		}
		else if (rest - 100 >= 0)
		{
			rest -= 100;
			res++;
		}
		else if (rest - 50 >= 0)
		{
			rest -= 50;
			res++;
		}
		else if (rest - 10 >= 0)
		{
			rest -= 10;
			res++;
		}
		else if (rest - 5 >= 0)
		{
			rest -= 5;
			res++;
		}
		else if (rest - 1 >= 0)
		{
			rest -= 1;
			res++;
		}
	}

	cout << res << endl;

	return 0;
}