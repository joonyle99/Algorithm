#include <bits/stdc++.h>
using namespace std;

int N;
string input;
vector<string> words;

vector<int> f;      // KMP 알고리즘 실패 함수

/// <summary>
/// 부분 문자열에 대한 '실패 함수'를 계산한다
/// </summary>
void CalcFailureFunc(string& subStr) {

    // f(k) : S[0:k+1)에서 S[0:x]와 S[x:|S|]가 일치하는 최대 길이
    // subStr: 0 1 2 ...| ... k-1 |						=> 접미사 부분
    // subStr: 			|0 1 2 ...| ... k-1				=> 접두사 부분
    //
    // 논리적으로 f(k) <= f(k-1) + 1임을 알 수 있다
    // 따라서 f(k)는 최대 길이를 f(k-1) + 1부터 감소하며 체크한다
    // 
    // 위의 설명을 근거로, 만약 S[f(K-1)] == S[K]라면
    // f(k) = f(k-1) + 1이다
    //
    // 그렇지 않다면 이미 구해놓은 실패함수의 값을 이용해
    // 오른쪽으로 얼마나 이동할지(j의 값 할당) 정하는 게 키포인트

    f.clear();
    f.resize(subStr.size());
    f[0] = 0;				    // S[0:1]에서는 자기 자신만 존재

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

    // Title : 욕설필터

    // [KMP 알고리즘]
    // 
    // 일반적인 문자열 검색(패턴 매칭)은 O(|S1| x |S2|)에 이루어진다
    // 문자열의 길이가 길거나, 최악의 경우 (문자열 S1의 각 위치마다 O(|S2|로 비교를 하는 경우) 시간이 초과될 수 있다.
    //
    // KMP는 패턴 매칭을 O(|S1| + |S2|)에 해결할 수 있다
    // 부분 문자열에서 자기 자신을 제외하고 접두사와 접미사가 일치하는 최대 길이를
    // 계산해 저장하는 '실패 함수'가 핵심이다.

    cin >> N;
    words.reserve(N);

    while (N--) {
        cin >> input;
        for (auto& word : words) {
            CalcFailureFunc(word);
            int i, j = 0;
            for (i = 0; i < input.size(); ++i) {
                while (j > 0) {
                    if (input[i] == word[j]) break;
                    j = f[j - 1];
                }
                if (input[i] == word[j]) {
                    ++j;
                }
                if (j == word.size()) {
                    cout << input << '\n';
                    goto next_input;
                }
            }
        }

        next_input:;

        words.push_back(input);
    }

    return 0;
}
