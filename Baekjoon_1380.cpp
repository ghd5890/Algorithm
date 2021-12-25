#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef unsigned int UNS_INT;

int main()
{
	vector<string> names;
	vector<char> impound;
	vector<bool> returned;
	string result;
	int n, test, std_num;
	char back;

	test = 0;

	while (1)
	{
		test++;

		cin >> n;
		if (n == 0) break;

		// 여학생들의 이름을 입력
		cin.ignore();
		names = vector<string>(n);
		impound = vector<char>(n, ' ');
		returned = vector<bool>(n, false);

		for (UNS_INT i = 0; i < names.size(); i++) getline(cin, names[i]);

		for (UNS_INT i = 0; i < 2 * names.size() - 1; i++)
		{
			cin >> std_num >> back;
			if (impound[std_num - 1] == ' ') impound[std_num - 1] = back;
			else returned[std_num - 1] = true;
		}

		for (UNS_INT i = 0; i < returned.size(); i++) result = returned[i] ? result : names[i];
		cout << test << ' ' << result << '\n';
	}

	return 0;
}