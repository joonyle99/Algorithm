===========================================================
Input char variable, ignoring ' ' until '\n'
===========================================================

std::string str;
std::getline(cin, str);

std::string inputString; char ch;
while (std::cin.get(ch) && ch != '\n')
	inputString.push_back(ch);

===========================================================
~
===========================================================

