#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
	set<int> num_set;
	set<int>::iterator iter;
	int n, m, num;

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		num_set.insert(num);
	}

	for (int i = 0; i < m; i++)
	{
		cin >> num;
		iter = num_set.find(num);
		if (iter != num_set.end()) num_set.erase(iter);
	}

	cout << num_set.size() << '\n';
	for (iter = num_set.begin(); iter != num_set.end(); iter++) cout << *iter << ' ';
	cout << '\n';
	
	return 0;
}