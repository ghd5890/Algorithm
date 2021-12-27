#include <iostream>
#include <vector>

using namespace std;

typedef unsigned int UNS_INT;

int main()
{
	/*
		n : 참가자의 수
		t : 문제의 개수
		p : 필립의 ID
		p_score = 필립의 점수
		p_grade = 필립의 등수
	*/
	int n = 0, t = 0, p = 0, p_score = 0, p_grade = 1;
	/*
		record : 학생들이 입력한 답안을 저장
		score : 각 문제의 점수
		correct : 학생들이 맞춘 문제의 개수
		total : 학생들의 총점
	*/
	vector<vector<int>> record;
	vector<int> score, correct, total;

	cin >> n >> t >> p;

	score = vector<int>(t, 0);
	total = vector<int>(n, 0);
	correct = vector<int>(n, 0);
	// 기록을 입력한다.
	record = vector<vector<int>>(n);
	for (UNS_INT i = 0; i < record.size(); i++)
	{
		record[i] = vector<int>(t);
		for (UNS_INT j = 0; j < record[i].size(); j++) cin >> record[i][j];
	}

	// 맞춘 문제의 개수를 계산한다.
	for (UNS_INT i = 0; i < record.size(); i++)
	{
		for (UNS_INT j = 0; j < record[i].size(); j++) correct[i] = record[i][j] == 1 ? correct[i] + 1 : correct[i];
	}

	// 각 문제의 점수 계산
	for (UNS_INT i = 0; i < score.size(); i++)
	{
		for (UNS_INT j = 0; j < record.size(); j++) score[i] = record[j][i] == 0 ? score[i] + 1 : score[i];
	}

	// 학생들의 점수 계산
	for (UNS_INT i = 0; i < total.size(); i++)
	{
		for (UNS_INT j = 0; j < score.size(); j++) total[i] = record[i][j] == 1 ? total[i] + score[j] : total[i];
	}

	// 등수 계산
	p_score = total[p - 1];
	for (UNS_INT i = 0; i < total.size(); i++)
	{
		p_grade = total[i] > p_score ? p_grade + 1 : p_grade;
		p_grade = total[i] == p_score && i != (p - 1) && correct[i] > correct[p - 1] ? p_grade + 1 : p_grade;
		p_grade = total[i] == p_score && i != (p - 1) && correct[i] == correct[p - 1] && i < (p - 1) ? p_grade + 1 : p_grade;
	}

	cout << p_score << ' ' << p_grade << '\n';

	return 0;
}