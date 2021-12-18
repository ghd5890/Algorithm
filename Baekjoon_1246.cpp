#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef unsigned int UNS_INT;

int main()
{
	vector<int> price; // ���� ���ϴ� �ִ� ����
	int n, m, egg_price = 0, total = 0, tmp = 0, pick = 0; //  n : �ް��� ����, m : ���� ��, egg_price : �ִ� ������ �� �� �ִ� �ް��� ����, total : �ִ� ����

	cin >> n >> m;
	price = vector<int>(m);

	for (UNS_INT i = 0; i < m; i++) cin >> price[i];
	sort(price.begin(), price.end());

	for (int i = 0; i < price.size(); i++)
	{
		if (m - i < n) tmp = price[i] * (m - i);
		else tmp = price[i] * n;

		if (tmp > total)
		{
			egg_price = price[i];
			total = tmp;
		}
	}

	cout << egg_price << ' ' << total << '\n';

	return 0;
}