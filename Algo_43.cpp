#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long solution(long long n);

int main()
{
	long long n;

	cin >> n;

	cout << solution(n) << '\n';

	return 0;
}

long long solution(long long n)
{
	long long answer = 1;

	while (answer * answer <= n) answer++;

	answer = (answer * answer) > n ? answer - 1 : answer;
	answer = (answer * answer) == n ? (answer + 1) * (answer + 1) : -1;

	return answer;
}