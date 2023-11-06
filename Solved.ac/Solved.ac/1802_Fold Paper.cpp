#include <iostream>
#include <string>

using namespace std;

/// <summary>
/// 종이 접기 가능할지 판단하는 함수
/// </summary>
/// <param name="_foldInfo"></param>
/// <returns></returns>
bool Check(string _foldInfo)
{
	size_t vertexCnt = _foldInfo.length();
	size_t middleIndex = vertexCnt / 2;

	// 더이상 접을 수 없을때까지 접는 것을 반복
	while (middleIndex != 0)
	{
		// 2. 중간을 기점으로 왼쪽 오른쪽 대칭을 같은지 확인한다
		for (size_t i = 0; i < middleIndex; ++i)
		{
			// 하나라도 대칭이 아니라면 접히지 않는다
			if (_foldInfo[i] + _foldInfo[vertexCnt - 1 - i] != 97)
				return false;
		}

		// 총 길이의 중간지점을 접는다.
		vertexCnt /= 2;
		middleIndex /= 2;
	}

	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// 종이 접기

	/// 이 문제가 그리디 알고리즘 분류였던 이유..?
	///	왼쪽으로 접는 경우와 오른쪽으로 접는 경우가 있는데 그 방향을 고려하지 않고 대칭 비교로만 가능해서..?
	///	음.. 아닌거같은데,,, 그냥 분할정복 문제라고 하는게 맞는 것 같다. -> 그리디 알고리즘 문항 X
	///	다음에는 재귀함수를 이용해서 이 문제를 풀어보자..

	/*
	 * T : 테스트 케이스 수
	 */

	int T; cin >> T;

	for (int i = 0; i < T; ++i)
	{
		string foldInfo; cin >> foldInfo;

		// 무조건 통과 조건
		if (foldInfo.length() == 1)
		{
			cout << "YES" << endl;
			continue;
		}

		/// 문자열을 YES / NO 가 아니라 Yes / No라고 했다고 틀렸댄다.. 거 시팔..
		string str = (Check(foldInfo) == true) ? "YES" : "NO";
		cout << str << endl;
	}

	return 0;
}