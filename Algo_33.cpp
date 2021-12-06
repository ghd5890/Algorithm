#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> solution(long long n);

int main()
{
	long long n;
	vector<int> result;

	cin >> n;

	result = solution(n);
	
	for (int i = 0; i < result.size(); i++) cout << result[i] << ' ';
	cout << '\n';

	return 0;
}

vector<int> solution(long long n)
{
	vector<int> answer;

	while (n != 0)
	{
		answer.push_back(n % 10);
		n /= 10;
	}

	return answer;
}