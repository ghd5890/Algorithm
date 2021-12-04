#include <iostream>
#include <vector>
#include <string>

using namespace std;

string solution(string s);

int main()
{
	string s;

	getline(cin, s);

	cout << solution(s) << '\n';

	return 0;
}

string solution(string s)
{
	string answer = "";

	for (unsigned int idx = 0; idx < s.length(); idx++)
	{
		if ((idx == 0 || (idx > 0 && s[idx - 1] == ' ')) && (s[idx] >= 'a' && s[idx] <= 'z')) answer += (char)(s[idx] - 32);
		else if ((idx > 0 && s[idx - 1] != ' ') && (s[idx] >= 'A' && s[idx] <= 'Z')) answer += (char)(s[idx] + 32);
		else answer += s[idx];
	}

	return answer;
}