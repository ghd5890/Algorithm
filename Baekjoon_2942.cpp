#include <iostream>

using namespace std;

int gcd(int a, int b);

int main()
{
	int r, g, max = 0;

	cin >> r >> g;

	max = gcd(r, g);
	for (int i = 1; i <= max; i++)
	{
		if (max % i == 0) cout << i << ' ' << r / i << ' ' << g / i << '\n';
	}

	return 0;
}

int gcd(int a, int b)
{
	if (b == 0) return a;
	
	if (a < b)
	{
		int tmp = b;
		b = a;
		a = tmp;
	}

	return gcd(b, a % b);
}