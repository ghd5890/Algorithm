/*
	프로그래머스 LEVEL 2 (괄호 회전하기)
*/
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#define PARENTHESIS "()"
#define BRACE "{}"
#define BRACKET "[]"

typedef unsigned int ui;

using namespace std;

ui solution(string s);

int main()
{
	string s;

	cin >> s;

	cout << solution(s) << '\n';

	return 0;
}

/*
	올바른 문자열을 찾는 알고리즘 함수
*/
ui solution(string s)
{
	ui ans = 0;
	bool isComplete = true;
	stack<char> stk;

	for (int i = 0; i < s.length(); i++)
	{
		char front = s[0];
		isComplete = true;
		for (int j = 0; j < s.length(); j++)
		{
			if (s[j] == PARENTHESIS[0] || s[j] == BRACE[0] || s[j] == BRACKET[0]) stk.push(s[j]);
			else
			{
				if (stk.empty())
				{
					isComplete = false;
					break;
				}

				if ((s[j] == PARENTHESIS[1] && stk.top() != PARENTHESIS[0]) || (s[j] == BRACE[1] && stk.top() != BRACE[0]) || (s[j] == BRACKET[1] && stk.top() != BRACKET[0]))
				{
					isComplete = false;
					break;
				}
				else stk.pop();

				if (!isComplete) break; // 완변한 괄호가 아닌 경우
			}
		} // 내부 for문의 끝

		if (isComplete && stk.empty()) ans++;
		else while (!stk.empty()) stk.pop();
		s = s.substr(1); s += front;
	}
	
	return ans;
}