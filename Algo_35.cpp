#include <iostream>
#include <vector>
#include <string>
#define INF 1000000000

using namespace std;

int solution(int n);

int main()
{
	int n; // �̵��Ϸ��� �Ÿ�
	
	cin >> n;

	cout << solution(n) << '\n';

	return 0;
}

int solution(int n)
{
	int answer = 0;

	while (n != 0)
	{
		if (n % 2) // ���� �Ÿ��� Ȧ���� ���
		{
			answer += 1;
			n -= 1;
		}
		else n /= 2; // ���� �Ÿ��� ¦���� ���
	}

	return answer;
}