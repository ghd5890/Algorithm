#include <iostream>

using namespace std;

int main()
{
	int n, a, b, sum, answer;

	cin >> n;
	
	// ��꿡 �ʿ��� ���� �ʱ�ȭ�Ѵ�.
	a = n - 1; b = n;
	sum = n;
	answer = 0;

	// �˰����� ����
	while (a > 0)
	{
		if (sum == n || sum > n)
		{
			answer = sum == n ? answer + 1 : answer;
			sum -= b;
			b--;
			sum = a == b ? a : sum;
		}
		else
		{
			a--;
			sum += a;
		}
	}

	cout << answer << '\n';

	return 0;
}