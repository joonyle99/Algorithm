#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <algorithm>

using std::cin;
using std::cout;

int N, M;

std::vector<int> inputArray;

void DFS(int number, std::vector<int> numVector)
{
    numVector.push_back(number);

    const auto arrayCount = numVector.size();

    if (arrayCount == M)
    {
        for (int i = 0; i < arrayCount; ++i)
        {
            if (i == arrayCount - 1)
                cout << numVector[i] << '\n';
            else
                cout << numVector[i] << " ";
        }

        // Recursive¸¦ ¸ØÃß°í return
        return;
    }

    for (int i = 1; i <= N; ++i)
    {
        DFS(i, numVector);
    }
}

int main()
{
    // Break the ios for C and C++
    std::ios::sync_with_stdio(false);

    // Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
    std::cin.tie(nullptr);

    // Title : N°ú M (3)

    cin >> N >> M;

    inputArray.resize(N + 1);

    for (int i = 1; i <= N; ++i)
        inputArray[i] = i;

    for (int i = 1; i <= N; ++i)
    {
        std::vector<int> numVector;
        DFS(i, numVector);
    }

    return 0;
}
