#include <bits/stdc++.h>
using namespace std;

string S;
string P;

vector<int> f;

/// <summary>
/// 부분 문자열에 대한 '실패 함수'를 계산한다
/// </summary>
void CalcFailureFunc(string& subStr) {

	// f(k) : S[0:k+1)에서 S[0:x]와 S[x:|S|]가 일치하는 최대 길이
	// subStr: 0 1 2 ...| ... k-1 |						=> 접미사 부분
	// subStr: 			|0 1 2 ...| ... k-1				=> 접두사 부분
	//
	// 논리적으로 f(k) <= f(k-1) + 1임을 알 수 있다
	// 따라서 f(k)는 f(k-1) + 1부터 감소하며 최대 길이를 체크한다
	// 
	// 위의 설명을 근거로, 만약 S[f(K-1)] == S[K]라면
	// f(k) = f(k-1) + 1이다
	//
	// 그렇지 않다면 DP와 비슷한 방식으로
	// 이미 구해놓은 값을 이용하는 게 실패 함수의 키포인트

	int i, j = 0;
	for (i = 1; i < subStr.size(); ++i) {
		while (j > 0) {
			if (subStr[i] == subStr[j]) break;
			j = f[j - 1];
		}
		if (subStr[i] == subStr[j]) {
			f[i] = ++j;
		}
	}
}

int main()
{
	// Break the ios for C and C++
	std::ios::sync_with_stdio(false);

	// Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
	std::cin.tie(nullptr);

	// Title : 부분 문자열

	cin >> S;	// 전체 문자열
	cin >> P;	// 부분 문자열

	// 1
	// size_t findPos = S.find(P);
	// if (findPos == string::npos)cout << 0;
	// else cout << 1;

	// 2
	// const char* result = strstr(S.c_str(), P.c_str());
	// if (result == nullptr) cout << 0;
	// else cout << 1;

	// 3
	// 일반적인 문자열 검색(패턴 매칭)은 O(|S1| x |S2|)에 이루어진다 (대부분의 경우 효율적임)
	// 문자열의 길이가 길거나, 최악의 경우 (문자열 S1의 각 위치마다 O(|S2|로 비교를 하는 경우) 해결할 수 없다
	//
	// 따라서 KMT 알고리즘을 사용한다
	// 패턴 매칭 문제를 O(|S1| + |S2|)에 해결할 수 있다
	// KMT 알고리즘에서는 '실패 함수'가 핵심이다
	// 실패 함수는 '부분 문자열에서 자기 자신을 제외하고 접두사와 접미사가 일치하는 최대 길이'를 계산해 저장한다

	f.resize(P.size());
	f[0] = 0;				// S[0:1]에서는 자기 자신만 존재
	CalcFailureFunc(P);

	int j = 0;
	for (int i = 0; i < S.size(); ++i) {
		while (j > 0 && S[i] != P[j]) j = f[j - 1];
		if (S[i] == P[j]) ++j;
		if (j == P.size()) {
			cout << 1;
			return 0;
		}
	}

	cout << 0;
	return 0;
}
