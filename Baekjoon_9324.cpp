#include <iostream>
#include <string>
#include <cstring>
#define DIV 3

using namespace std;

typedef unsigned int UNS_INT;

int freq[26] = { 0 };

int main()
{
	string str;
	int n;
	bool isOk = true;

	cin >> n;
	while (n--)
	{
		cin >> str;
		
		isOk = true;
		for (UNS_INT idx = 0; idx < str.length(); idx++)
		{
			freq[str[idx] - 'A']++;
			if (freq[str[idx] - 'A'] >= 3)
			{
				if (idx == str.length() - 1) isOk = false;
				if (idx < str.length() - 1) isOk = str[idx] == str[idx + 1] ? true : false;
				freq[str[idx] - 'A'] = freq[str[idx] - 'A'] % 3;
				idx = isOk ? idx + 1 : idx;
				if (!isOk) break;
			}
		}

		if (isOk) cout << "OK\n";
		else cout << "FAKE\n";
		memset(freq, 0, sizeof(freq));
	}

	return 0;
}