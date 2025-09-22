#include <bits/stdc++.h>
using namespace std;

string FizzBuzz(int n)
{
    if (n % 3 == 0 && n % 5 == 0) {
        return "FizzBuzz";
    }
    else if (n % 3 == 0 && n % 5 != 0) {
        return "Fizz";
    }
    else if (n % 3 != 0 && n % 5 == 0) {
        return "Buzz";
    }
    else {
        return to_string(n);
    }
}

int main()
{
    // Break the ios for C and C++
    std::ios::sync_with_stdio(false);

    // Untie the streams that bind cin and cout (Output cout before cin's buffer is empty)
    std::cin.tie(nullptr);

    // Title : FizzBuzz

    string s1; cin >> s1;
    string s2; cin >> s2;
    string s3; cin >> s3;

    if (s1 != "FizzBuzz" && s1 != "Fizz" && s1 != "Buzz") {
        cout << FizzBuzz(stoi(s1) + 3);
    }
    else if (s2 != "FizzBuzz" && s2 != "Fizz" && s2 != "Buzz") {
        cout << FizzBuzz(stoi(s2) + 2);
    }
    else if (s3 != "FizzBuzz" && s3 != "Fizz" && s3 != "Buzz") {
        cout << FizzBuzz(stoi(s3) + 1);
    }

    return 0;
}
