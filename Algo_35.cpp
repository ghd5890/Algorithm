#include <iostream>
#include <vector>
#include <string>
#define INF 1000000000

using namespace std;

int solution(int n);

int main()
{
	int n; // 이동하려는 거리
	
	cin >> n;

	cout << solution(n) << '\n';

	return 0;
}

int solution(int n)
{
	int answer = 0;

	while (n != 0)
	{
		if (n % 2) // 남은 거리가 홀수일 경우
		{
			answer += 1;
			n -= 1;
		}
		else n /= 2; // 남은 거리가 짝수일 경우
	}

	return answer;
}