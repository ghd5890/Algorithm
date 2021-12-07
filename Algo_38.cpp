#include <iostream>
#include <string>
#include <vector>

using namespace std;

int count_one(int n);
int solution(int n);

int main()
{
	int n;

	cin >> n;

	cout << solution(n) << '\n';

	return 0;
}

int count_one(int n)
{
	int cnt = 0;

	while (n != 0)
	{
		cnt = (n % 2 == 1) ? cnt + 1 : cnt;
		n /= 2;
	}

	return cnt;
}

int solution(int n)
{
	int answer = 0, number = n, cnt = count_one(n);
	bool isOk = false;

	do
	{
		number++;
		isOk = cnt == count_one(number) ? true : false;
	} while (!isOk);

	answer = number;

	return answer;
}