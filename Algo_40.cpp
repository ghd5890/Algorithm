#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string s, int n);

int main()
{
	string s;
	int n;

	getline(cin, s);
	cin >> n;
	cout << solution(s, n) << '\n';

	return 0;
}

string solution(string s, int n)
{
	string answer = "";
	int char_to_num = 0; int mod = 0;
	char add = ' ', pivot = ' ';

	for (unsigned int i = 0; i < s.length(); i++)
	{
		
		if (s[i] >= 'A' && s[i] <= 'Z')
		{
			pivot = 'A';
			mod = (int)'Z';
			char_to_num = (int)(s[i] + n);
			add = char_to_num > mod ? (char)(char_to_num % mod) + (pivot - 1) : (char)char_to_num;
		}
		else if (s[i] >= 'a' && s[i] <= 'z')
		{
			pivot = 'a';
			mod = (int)'z';
			char_to_num = (int)(s[i] + n);
			add = char_to_num > mod ? (char)(char_to_num % mod) + (pivot - 1) : (char)char_to_num;
		}
		else add = s[i];
		answer = answer + add;
	}

	return answer;
}