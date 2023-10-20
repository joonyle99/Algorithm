#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	/// 문서 탐색

	// 어떤 단어가 총 몇 번 등장하는지

	// 중복되어 세는 것은 뺀다.
	// abababa = ababa x 2 -> X

	// iostream 안에 있는 입력 스트림 객체 cin은 공백을 무시하고 입력받는다.
	// string의 getline()을 사용한다.

	string str; getline(cin, str);
	string word; getline(cin, word);

	int cnt = 0;

	// 방법 1 : 브루트포스 방식으로 푸는 방법
	/*
	for (int i = 0; i < str.length(); ++i)
	{
		bool isContain = true;

		// 한 단어를 전부 돌아서 맞는지 확인한다.
		for (int j = 0; j < word.length(); ++j)
		{
			if (str[i + j] != word[j])
			{
				isContain = false;
				break;
			}
		}

		// 다 돌고나서 체크
		if (isContain)
		{
			cnt++;
			i += word.length() - 1;
		}
	}
	*/

	// 방법 2 : 그리디 알고리즘으로 푸는 방법..?
	// -> 이건 잘못 나온 문제인듯 하다

	// 방법 3 : string 클래스를 적극 활용하는 방법..?


	cout << cnt << endl;

	return 0;
}