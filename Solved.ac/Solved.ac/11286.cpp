#include <bits/stdc++.h>
using namespace std;

int n;

int main()
{
    // Break the ios for C and C++
    std::ios::sync_with_stdio(false);

    // Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
    std::cin.tie(nullptr);

    // Title : 절댓값 힙

    cin >> n;

    // x가 0이 아니라면 배열에 x라는 값을 넣는(추가하는) 연산
    // x가 0이라면 배열에서 절댓값이 가장 작은 값을 출력하고 그 값을 배열에서 제거

    // 방법 1: 그냥 하라는대로 하기 (시간 효율을 크게 신경쓰지 않음)
    //{
    //    vector<int> vec;

    //    while (n-- > 0)
    //    {
    //        int x; cin >> x;
    //        if (x != 0)
    //        {
    //            vec.push_back(x);
    //        }
    //        else
    //        {
    //            if (vec.empty())
    //            {
    //                cout << 0 << '\n';
    //                continue;
    //            }

    //            int min_abs = abs(vec[0]);
    //            int min_org = vec[0];
    //            int idx = 0;

    //            for (int i = 0; i < vec.size(); i++)
    //            {
    //                if (min_abs >= abs(vec[i]))
    //                {
    //                    if (min_abs == abs(vec[i]))
    //                    {
    //                        if (min_org > vec[i])
    //                        {
    //                            min_org = vec[i];
    //                            idx = i;
    //                        }
    //                    }
    //                    else
    //                    {
    //                        min_abs = abs(vec[i]);
    //                        min_org = vec[i];
    //                        idx = i;
    //                    }
    //                }
    //            }

    //            cout << min_org << '\n';
    //            vec.erase(vec.begin() + idx);
    //        }
    //    }
    //}

    /// priority queue는 '최대힙'이 기준이라는 사실을 인지하자..!
    /// 최소힙으로 만들어주기 위해서는 return을 반대로 해줘야함
    struct Compare
    {
        bool operator()(int a, int b)
        {
            int abs_a = abs(a);
            int abs_b = abs(b);

            if (abs_a == abs_b)
            {
                // 절댓값 같으면 더 큰 쪽이 "우선순위 낮음"

                return a > b;
                //return a > 0 && b < 0;
            }
            else
            {
                return abs_a > abs_b; // 절댓값이 더 큰 쪽이 "우선순위 낮음"
            }
        }
    };

    // 방법 2: 우선순위 큐 사용하기
    priority_queue<int, vector<int>, Compare> minAbsPq;
    while (n-- > 0)
    {
        int x; cin >> x;
        if (x != 0)
        {
            minAbsPq.push(x);
        }
        else
        {
            if (minAbsPq.empty())
            {
                cout << 0 << '\n';
                continue;
            }

            cout << minAbsPq.top() << '\n';
            minAbsPq.pop();
        }
    }

    return 0;
}
