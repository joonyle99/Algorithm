#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Break the ios for C and C++
    std::ios::sync_with_stdio(false);

    // Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
    std::cin.tie(nullptr);

    // Title : 애너그램 만들기

    // 목표 : 두 단어가 서로 애너그램 관계에 있도록 만들기 위해서
    // 제거해야 하는 최소 개수의 문자 수를 구하는 프로그램

    string a, b;
    cin >> a >> b;

    int removeCount = 0;
    int alphabetCountArr[26] = {};
    // origin setting
    for (const auto c : a) {
        alphabetCountArr[c - 'a']++;
    }
    // substract from origin
    for (const auto c : b) {
        // removeCount ++ in 'b' string
        if (alphabetCountArr[c - 'a'] == 0)
            removeCount++;
        // matching
        else
            alphabetCountArr[c - 'a']--;
    }
    // removeCount ++ in 'a' string
    for (int i = 0; i < 26; i++) {
        removeCount += alphabetCountArr[i];
    }
    cout << removeCount;

    return 0;
}
