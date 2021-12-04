#include <iostream>
#include <vector>
#include <string>

using namespace std;

int solution(vector<int> arr);
int gcd(int a, int b);

int main()
{
	int n;
	vector<int> arr;

	cin >> n;
	arr = vector<int>(n);
	for (int i = 0; i < n; i++) cin >> arr[i];

	cout << solution(arr) << '\n';

	return 0;
}

int solution(vector<int> arr)
{
	int answer = 0;
	int cur = 0, lcm = 0, g = 0, div = 1;

	lcm = arr[cur];
	while (cur != arr.size() - 1)
	{
		g = gcd(lcm, arr[cur + 1]);
		lcm = (lcm / g) * (arr[cur + 1] / g) * g;
		cur++;
	}

	return answer = lcm;
}

int gcd(int a, int b) // 최대 공약수 구하는 알고리즘
{
	int result = 0;
	int big_num = a > b ? a : b; int small_num = a < b ? a : b; int tmp = 0;

	while (small_num != 0)
	{
		tmp = small_num;
		small_num = big_num % tmp;
		big_num = tmp;
	}

	result = big_num;

	return result;
}