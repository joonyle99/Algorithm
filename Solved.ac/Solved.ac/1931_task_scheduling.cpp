#include <bits/stdc++.h>
using namespace std;

int N;

//int s[100005];  // 100000 * 4 byte = 0.4MB (이정도는 끄떡없다)
//int e[100005];

pair<int, int> task[100005];    // 100000 * 8 = 0.8MB

/// <summary>
/// compare 함수를 인자로 주지 않을 수 있는데
/// 그러려면 task의 first에 end time을 넣어주고
/// task의 second에 start time을 넣어주면
/// 자동으로 end time -> start time 우선순으로 '오름차순' 정렬을 진행할 것이다
/// </summary>
bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}
int main()
{
    // Break the ios for C and C++
    std::ios::sync_with_stdio(false);

    // Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
    std::cin.tie(nullptr);

    // Title : 회의실 배정

    // 그리디 알고리즘을 제대로 배웠다고 하면
    // 처음에 'Task Scheduling Problem'이라는 문제 유형으로 접해봤을 문제이다.

    // 내가 떠올린 그리디 알고리즘의 풀이가 당장의 손해는 있어도
    // 선택 안하고 '나중에 가서 더 이득인 경우'는 없는지 살펴본다

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> task[i].first >> task[i].second;
    }

    // 끝나는 시간을 기준으로 오름차순 정렬한다
    // 같다면 시작하는 시간을 기준으로 오름차순 정렬한다

    // 끝나는 시간이 같다면 시작하는 시간이 빠른 순서대로 정렬해야 하는 이유는
    // (1, 4) (5, 5) (4, 5)의 경우를 생각해 보면 알 수 있다.
    // 시작하자마자 끝나는 경우를 고려하려면 시작하는 시간을 기준으로도 정렬해야 한다

    sort(task, task + N, compare);  // 시간 복잡도: O(NlogN)

    // 기준 Task를 선택한다
    // 종료 시간 이후에 시작하는 회의를 찾는다
    // 그 회의를 다시 기준 Task로 설정한다
    // 회의가 더이상 없을 때까지 한다

    int res = 1;

    /*
    
    // 방법 1

    // 이중 for문으로 O(N^2)처럼 보이지만
    // 내부 for문에서 i를 j로 건너뛰도록 하기 때문에
    // 결국 모든 회의를 한번씩만 검사하게 된다.
    // 따라서 O(N)
    for (int i = 0; i < N; ++i) {   // origin
        for (int j = i + 1; j < N; ++j) {   // target
            if (task[i].second <= task[j].first) {
                res++;
                i = j - 1;
                break;
            }
        }
    }
    */

    // 방법 2

    int temp = task[0].second;

    // 시간 복잡도: O(N) - 직관적으로 O(N)이다
    for (int i = 1; i < N; ++i) {
        if (temp <= task[i].first) {
            temp = task[i].second;
            res++;
        }
    }

    // 방법 1에서는 마찬가지로 시간복잡도가 O(N)이지만 '상수 펙터'가 더 크다 i.e) O(100N)
    // 방법 2에서는 연산을 효율적으로 줄였기 때문에 같은 O(N)의 시간복잡도라도 효율적이다 i.e) O(50N)
    // 
    // 같은 알고리즘을 사용한다고 하더라도 코드를 어떻게 짜느냐에 따라
    /// '숨겨진 상수 펙터'가 달라져 엄격한 시간 복잡도 관리가 필요한 문제에서는 정답을 가를 수 있다

    cout << res;

    return 0;
}
