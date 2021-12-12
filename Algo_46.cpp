#include <iostream>
#include <string>
#include <vector>

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
	unsigned int idx = 0;

	for (unsigned int i = 0; i < s.length(); i++)
	{
		if (s[i] == ' ')
		{
			idx = 0;
			continue;
		}

		if (s[i] >= 'A' && s[i] <= 'Z') s[i] = idx % 2 == 0 ? s[i] : s[i] + 32;
		else s[i] = idx % 2 == 0 ? s[i] - 32 : s[i];

		idx++;
	}

	answer = s;

	return answer;
}