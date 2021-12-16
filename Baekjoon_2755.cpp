#include <iostream>
#include <cstdio>
#include <string>
#include <iomanip>
#include <map>
#include <cmath>
#include <cstring>
#define CREDIT 0
#define GRADE 1

using namespace std;

typedef unsigned int UNS_INT;

int main()
{
	/*
		subject : 강의 
		credit : 학점
		grade : 성적
	*/
	string subject, credit, grade;
	map<char, double> plus_minus;
	double result = 0, total = 0, tmp = 0, mul = 0, sum = 0;
	double match[3] = { 1.0, 2.0, 3.0 };
	int n;

	plus_minus.insert(pair<char, double>('+', 0.3));
	plus_minus.insert(pair<char, double>('0', 0.0));
	plus_minus.insert(pair<char, double>('-', -0.3));

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> subject >> credit >> grade;
		
		// 연산 알고리즘
		tmp = match[credit[0] - '1'];
		for (UNS_INT g = 0; g < grade.length(); g++)
		{
			if ('A' <= grade[g] && grade[g] <= 'D') mul += (double)((double)4 - (double)grade[g] + (double)'A');
			else mul += plus_minus[grade[g]];
		}

		sum += (tmp * mul);
		total += match[credit[0] - '1'];
		tmp = 0; mul = 0;
	}

	result = sum / total;
	result += 0.000000000001;
	cout << fixed << setprecision(2) << result << '\n';

	return 0;
}