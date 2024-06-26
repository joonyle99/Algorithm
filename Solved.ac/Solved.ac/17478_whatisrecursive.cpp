#include <bits/stdc++.h>
using namespace std;

int N;  // 출력을 원하는 재귀 횟수

string prefix = "____";

string str1 = "\"재귀함수가 뭔가요?\"";
string str2 = "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.";
string str3 = "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.";
string str4 = "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"";
string str5 = "\"재귀함수는 자기 자신을 호출하는 함수라네\"";
string str6 = "라고 답변하였지.";

void _Bar(int n, string str) {
    for (int i = 0; i < n; i++) {
        cout << prefix;
    }
    cout << str << '\n';
}

void ChatBot(int n)
{
    // start
    _Bar(N - n, str1);

    if (n == 0) {
        _Bar(N - n, str5);
        _Bar(N - n, str6);
        return;
    }

    _Bar(N - n, str2);
    _Bar(N - n, str3);
    _Bar(N - n, str4);

    ChatBot(n - 1);

    // end
    _Bar(N - n, str6);

    return;
}

int main()
{
    // Break the ios for C and C++
    std::ios::sync_with_stdio(false);

    // Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
    std::cin.tie(nullptr);

    // Title : 재귀함수가 뭔가요?

    cin >> N;

    cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다." << '\n';

    ChatBot(N);

    return 0;
}
