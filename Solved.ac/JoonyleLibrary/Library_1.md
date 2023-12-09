===========================================================
Input char variable, ignoring ' ' until '\n'
===========================================================

std::string str;
std::getline(cin, str);

std::string inputString; char ch;
while (std::cin.get(ch) && ch != '\n')
	inputString.push_back(ch);

===========================================================
BFS
===========================================================

int BFS(int number)
{
    int result = 0;

    std::queue<int> myQueue;
    myQueue.push(number);

    while(!myQueue.empty())
    {
        int front = myQueue.front();
        myQueue.pop();

        // myQueue에 push를 하는 경우
    }

    return result;
}


===========================================================
BFS
===========================================================