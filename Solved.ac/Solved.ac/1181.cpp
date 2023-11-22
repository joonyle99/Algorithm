#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using std::ios;
using std::cin;
using std::cout;
using std::string;

bool Compare(string a, string b)
{
	// 길이가 짧은 것부터
	// 길이가 같으면 사전 순으로

	if (a.length() == b.length())
	{
		for (int i = 0; i < a.length(); ++i)
		{
			if (a[i] == b[i])
				continue;

			return a[i] < b[i];
		}
	}

	return a.length() < b.length();
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// 단어 정렬

	int N; cin >> N;

	string wordsArr[20000];

	for (int i = 0; i < N; ++i)
	{
		string word; cin >> word;
		wordsArr[i] = word;
	}

	std::sort(wordsArr, wordsArr + N, Compare);

	for (int i = 0; i < N; ++i)
	{
		// 다음 요소가 현재 요소랑 같은 값이면 넘어간다
		if (wordsArr[i] == wordsArr[i + 1])
			continue;

		if (!wordsArr[i].empty())
			cout << wordsArr[i] << '\n';
	}

	return 0;
}