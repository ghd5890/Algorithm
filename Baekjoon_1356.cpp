#include <iostream>

using namespace std;

typedef unsigned int UNS_INT;

int main()
{
	string n;
	int mul1 = 0, mul2 = 0, div = 10;
	bool result = false;

	cin >> n;
	for (UNS_INT i = 0; i < n.length() - 1; i++)
	{
		mul1 = 1; mul2 = 1;

		for (UNS_INT n1 = 0; n1 <= i; n1++) mul1 *= (n[n1] - '0');
		for (UNS_INT n2 = i + 1; n2 < n.length(); n2++) mul2 *= (n[n2] - '0');

		result = mul1 == mul2 ? true : false;
		if (result) break;
	}

	if (result) cout << "YES\n";
	else cout << "NO\n";

	return 0;
}