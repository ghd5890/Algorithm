#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool solution(string s);

int main()
{
	string s;

	cin >> s;
	cout << solution(s) << '\n';

	return 0;
}

bool solution(string s)
{
	bool answer = true;
	int p_cnt = 0, y_cnt = 0;

	for (unsigned int i = 0; i < s.length(); i++)
	{
		p_cnt = s[i] == 'p' || s[i] == 'P' ? p_cnt + 1 : p_cnt;
		y_cnt = s[i] == 'y' || s[i] == 'Y' ? y_cnt + 1 : y_cnt;
	}

	return answer = p_cnt == y_cnt ? true : false;
}