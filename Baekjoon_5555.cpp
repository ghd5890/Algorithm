#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef unsigned int UNS_INT;

int main()
{
	vector<string> arr;
	vector<bool> result;
	string search;
	UNS_INT s_idx;
	int n, answer;

	cin >> search;

	cin >> n;
	arr = vector<string>(n);
	result = vector<bool>(n, false);
	for (UNS_INT i = 0; i < arr.size(); i++) cin >> arr[i];

	answer = 0;
	for (UNS_INT i = 0; i < arr.size(); i++)
	{
		for (UNS_INT j = 0; j < arr[i].length(); j++)
		{
			s_idx = 0;
			if (arr[i][j] == search[0] && !result[i])
			{
				for (UNS_INT k = 0; k < search.length(); k++)
				{
					s_idx = (search[k] == arr[i][(j + k) % arr[i].length()]) ? s_idx + 1 : s_idx;
				}

				result[i] = s_idx == search.length() ? true : result[i];
			}
		}
	}

	for (UNS_INT i = 0; i < result.size(); i++) answer = result[i] ? answer + 1 : answer;

	cout << answer << '\n';

	return 0;
}