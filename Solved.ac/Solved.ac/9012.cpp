#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>

using namespace std;

string VPS_Cheack(string& input)
{
	// 무조건 짝수개여야 한다
	if (input.length() % 2 != 0)
		return "NO";

	// 스택을 이용해서 괄호 문자열을 검사한다
	std::stack<char> vpsStack;
	for (int i = 0; i < input.length(); ++i)
	{
		// '('인 경우에만 push 해준다
		if(input[i] == '\(')
		{
			vpsStack.push(input[i]);
		}
		// ')'인 경우에는 pop 해준다
		else if (input[i] == '\)')
		{
			// 스택 안에 '('가 있는 경우에만 pop 해준다
			if (!vpsStack.empty())
				vpsStack.pop();
			// 스택 안에 아무것도 없으면 유효하지 않으므로 NO
			else
				return "NO";
		}
	}

	// 스택이 비어있으면 적절히 쌍이 이루어졌다는 뜻
	if (vpsStack.empty())
		return "YES";

	return "NO";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// 괄호

	int T; cin >> T;

	while(T-- > 0)
	{
		string input; cin >> input;
		cout << VPS_Cheack(input) << endl;
	}

	return 0;
}