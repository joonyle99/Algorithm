#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 잃어버린 괄호
    // + - ()
    // 이 식의 값을 '최소'로 만들려고 한다.

    // 55-50+40

    // 5자리보다 많이 연속되는 숫자는 없다
    // 수는 0으로 시작할 수 있다
    // 입력으로 주어지는 식의 길이는 50보다 작거나 같다

    // * `최소`를 만들기 위해서는 -가 커져야한다. *
    // -에 괄호를 적절히 쳐서 -를 값을 크게 만든다

    // ** '-' 뒤에 오는 식을 전부 뺄셈 처리하면 식의 값이 최소가 된다. **

    // 문제점 1
    // 문자열을 어떻게 정수로 처리할 것인가?

    // 문제점 2
    // 괄호를 어느 타이밍에 넣을 것이고, 어떻게 넣어야 하는걸까?

    string input;
    cin >> input;

    string partialNum;
    const int inputSize = static_cast<int>(input.size());
    int res = 0;
    bool isMinus = false;

    for (int i = 0; i < inputSize; i++)
    {
        // 연산 기호가 나오면 계산한다.
        if (input[i] == '-' || input[i] == '+')
        {
            res += (isMinus ? -1 : 1) * stoi(partialNum);
            partialNum = "";
        }
        // 나머지 경우에는 부분 문자열에 수를 누적
        else
            partialNum += input[i];

        // '-'가 한 번 나오면 그 뒤는 쭉 - 기호
        if (input[i] == '-' && !isMinus)
            isMinus = true;
    }

    // Input Data가 끝나면
    res += (isMinus ? -1 : 1) * stoi(partialNum);
    cout << res;

    return 0;
}