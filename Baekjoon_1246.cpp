#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef unsigned int UNS_INT;

int main()
{
	vector<int> price; // 고객이 원하는 최대 가격
	int n, m, egg_price = 0, total = 0, tmp = 0, pick = 0; //  n : 달걀의 개수, m : 고객의 수, egg_price : 최대 수익을 낼 수 있는 달걀의 가격, total : 최대 수익

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