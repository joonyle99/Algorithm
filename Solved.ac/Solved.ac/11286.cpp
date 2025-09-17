#include <bits/stdc++.h>
using namespace std;

int n;

int main()
{
    // Break the ios for C and C++
    std::ios::sync_with_stdio(false);

    // Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
    std::cin.tie(nullptr);

    // Title : ���� ��

    cin >> n;

    // x�� 0�� �ƴ϶�� �迭�� x��� ���� �ִ�(�߰��ϴ�) ����
    // x�� 0�̶�� �迭���� ������ ���� ���� ���� ����ϰ� �� ���� �迭���� ����

    // ��� 1: �׳� �϶�´�� �ϱ� (�ð� ȿ���� ũ�� �Ű澲�� ����)
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

    /// priority queue�� '�ִ���'�� �����̶�� ����� ��������..!
    /// �ּ������� ������ֱ� ���ؼ��� return�� �ݴ�� �������
    struct Compare
    {
        bool operator()(int a, int b)
        {
            int abs_a = abs(a);
            int abs_b = abs(b);

            if (abs_a == abs_b)
            {
                // ���� ������ �� ū ���� "�켱���� ����"

                return a > b;
                //return a > 0 && b < 0;
            }
            else
            {
                return abs_a > abs_b; // ������ �� ū ���� "�켱���� ����"
            }
        }
    };

    // ��� 2: �켱���� ť ����ϱ�
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
