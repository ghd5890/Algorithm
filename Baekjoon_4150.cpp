#include <iostream>
#include <vector>
#include <string>

using namespace std;

string add(string num1, string num2);

int main()
{
	string num1, num2, answer;
	int n;

	cin >> n;

	num1 = "1", num2 = "1";
	for (int i = 3; i <= n; i++)
	{
		answer = add(num1, num2);
		num1 = num2;
		num2 = answer;
	}

	if (n == 1 || n == 2) cout << '1' << '\n';
	else cout << answer << '\n';

	return 0;
}

string add(string num1, string num2)
{
	string answer = "", n1 = num1.length() > num2.length() ? num1 : num2, n2 = num1.length() > num2.length() ? num2 : num1;
	char add = ' ';
	int carry = 0, cal = 0,  n1_idx = n1.length() - 1, n2_idx = n2.length() - 1;
	
	while (n2_idx >= 0)
	{
		cal = (n1[n1_idx] - '0') + (n2[n2_idx] - '0') + carry;
		
		carry = cal >= 10 ? 1 : 0; // 자리 올림이 발생했는지 확인한다.
		add = (char)(cal % 10) + '0';
		answer = add + answer;

		n1_idx--;
		n2_idx--;
	}

	while (n1_idx >= 0)
	{
		cal = (n1[n1_idx] - '0') + carry;
		carry = cal >= 10 ? 1 : 0;
		add = (char)(cal % 10) + '0';
		answer = add + answer;

		n1_idx--;
	}

	answer = carry == 1 ? '1' + answer : answer;

	return answer;
}