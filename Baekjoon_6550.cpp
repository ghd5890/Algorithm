#include <iostream>
#include <string>

using namespace std;

typedef unsigned int UNS_INT;

int main()
{
	string s, t, answer = "";
	UNS_INT idx = 0;

	while (cin >> s >> t)
	{
		idx = 0;
		for (UNS_INT i = 0; i < t.length(); i++) idx = s[idx] == t[i] ? idx + 1 : idx;
		answer = idx == s.length() ? "Yes\n" : "No\n";
		cout << answer;
	}

	return 0;
}