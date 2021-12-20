#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	vector<int> temp;
	int n, k;

	cin >> n >> k;
	temp = vector<int>(n + 1, 0);

	for (int i = 1; i <= n; i++)
	{
		cin >> temp[i];
		temp[i] = i != 0 ? temp[i] + temp[i - 1] : temp[i];
	}

	int tmp = 0, max = -1000000;
	for (int i = k; i <= n; i++)
	{
		tmp = temp[i] - temp[i - k];
		max = tmp > max ? tmp : max;
	}

	cout << max << '\n';
	
	return 0;
}