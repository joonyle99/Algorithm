#include <bits/stdc++.h>
using namespace std;

vector<int> simulateQueries(int cacheSize, vector<string> queries) {
    list<int> order;
    unordered_map<int, pair<int, list<int>::iterator>> cachedMap;
    vector<int> result;

    for (string command : queries) {
        int firstSpace = command.find(' ');
        string type = command.substr(0, firstSpace);

        if (type == "GET") {
            int key = stoi(command.substr(firstSpace + 1));
            if (cachedMap.count(key)) {
                int value = cachedMap[key].first;
                // LRU 순서 갱신
                order.erase(cachedMap[key].second);
                order.push_front(key);
                cachedMap[key].second = order.begin();
                result.push_back(value);
            }
            else {
                result.push_back(-1);
            }
        }
        else { // PUT
            int secondSpace = command.find(' ', firstSpace + 1);
            int key = stoi(command.substr(firstSpace + 1, secondSpace - firstSpace - 1));
            int value = stoi(command.substr(secondSpace + 1));

            if (cachedMap.count(key)) {
                // 값 갱신 + 순서 갱신
                cachedMap[key].first = value;
                order.erase(cachedMap[key].second);
                order.push_front(key);
                cachedMap[key].second = order.begin();
            }
            else {
                if ((int)cachedMap.size() == cacheSize) {
                    int oldKey = order.back();
                    order.pop_back();
                    cachedMap.erase(oldKey);
                }
                order.push_front(key);
                cachedMap[key] = { value, order.begin() };
            }
        }
    }
    return result;
}

int main()
{
    // Break the ios for C and C++
    std::ios::sync_with_stdio(false);

    // Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
    std::cin.tie(nullptr);

    // Title : ISBN

    vector<string> queries = { "PUT 111 111", "PUT 999 999", "GET 1", "GET 111", "GET 999" };
    vector<int> result = simulateQueries(1, queries);
    
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << '\n';
    }

    return 0;
}
