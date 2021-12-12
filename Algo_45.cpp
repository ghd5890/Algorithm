#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isPrime[1000000] = { false };
int solution(int n);

int main()
{
	int n;

	cin >> n;
	cout << solution(n) << '\n';
	
	return 0;
}

int solution(int n)
{
	int answer = 0;

	for (int i = 2; i <= n; i++) isPrime[i] = true;

 	for (int i = 2; i * i <= n; i++)
	{
		if (isPrime[i])
		{
			for (int j = i * i; j <= n; j += i) isPrime[j] = false;
		}
	}

	for (int i = 2; i <= n; i++) answer = isPrime[i] ? answer + 1 : answer;

	return answer;
}