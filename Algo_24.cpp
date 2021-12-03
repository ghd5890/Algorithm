/*
	프로그래머스 LEVEL 2 (최댓값과 최솟값)
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string s);
bool comp(string tmp, string cur);

int main()
{
	string s;

	getline(cin, s);

	cout << solution(s) << '\n';

	return 0;
}

string solution(string s)
{
	string answer = "", cur = "", max = "", min = "";

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] != ' ') cur += s[i];
		else // 수를 비교하는 과정
		{
			if (max.length() == 0 && min.length() == 0) 
			{
				max = cur;
				min = cur;
			}
			else
			{
				max = comp(max, cur) ? max : cur;
				min = comp(min, cur) ? cur : min;
			}
			cur = "";
		}
	}

	max = comp(max, cur) ? max : cur;
	min = comp(min, cur) ? cur : min;

	answer = min + " " + max;

	return answer;
}

// tmp > cur이면 true, tmp < cur이면 false
bool comp(string tmp, string cur)
{
	bool tmpIsNeg = tmp[0] == '-' ? true : false; 
	bool curIsNeg = cur[0] == '-' ? true : false; 
	bool res = false;

	if (tmpIsNeg != curIsNeg) // 부호가 다를 경우
	{
		res = tmpIsNeg ? false : true;
	}
	else // 부호가 같을 경우
	{
		tmp = tmpIsNeg ? tmp.substr(1) : tmp; cur = curIsNeg ? cur.substr(1) : cur;

		if (tmp.length() > cur.length()) res = tmpIsNeg && curIsNeg ? false : true;
		else if (tmp.length() == cur.length())
		{
			for (int i = 0; i < tmp.length(); i++)
			{
				if ((tmp[i] - '0') > (cur[i] - '0'))
				{
					res = tmpIsNeg && curIsNeg ? false : true;
					break;
				}
				else if ((tmp[i] - '0') < (cur[i] - '0'))
				{
					res = tmpIsNeg && curIsNeg ? true : false;
					break;
				}
				else continue;
			}
		}
		else res = (tmpIsNeg && curIsNeg) ? true : false;
	}

	return res;
}