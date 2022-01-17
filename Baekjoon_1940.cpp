#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef unsigned int UNS_INT;

int main()
{
	vector<int> material;
	int n, m, answer = 0;

	cin >> n;
	cin >> m;

	material = vector<int>(n);
	for (UNS_INT i = 0; i < material.size(); i++) cin >> material[i];
	
	sort(material.begin(), material.end());

	for (UNS_INT i = 0; i < material.size(); i++)
	{
		for (UNS_INT j = i + 1; j < material.size(); j++)
		{
			if (material[i] + material[j] == m)
			{
				answer++;
				break;
			}
		}
	}

	cout << answer << '\n';

	return 0;
}