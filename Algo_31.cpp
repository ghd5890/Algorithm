#include <iostream>
#include <vector>
#include <string>
#include <map>
#define MAX 26

using namespace std;

int solution(string skill, vector<string> skill_trees);

int main()
{
	vector<string> skill_trees;
	string skill;
	int n;

	cin >> skill;

	cin >> n;
	skill_trees = vector<string>(n);
	for (int i = 0; i < n; i++) cin >> skill_trees[i];

	cout << solution(skill, skill_trees) << endl;

	return 0;
}

int solution(string skill, vector<string> skill_trees)
{
	int answer = 0, skill_idx = 1;
	map<char, int> skill_map;
	map<char, int>::iterator iter;
	bool check = true;

	for (unsigned int i = 0; i < skill.length(); i++) skill_map.insert(pair<char, int>(skill[i], i + 1));

	for (unsigned int user = 0; user < skill_trees.size(); user++)
	{
		for (unsigned int search = 0; search < skill_trees[user].length(); search++)
		{
			iter = skill_map.find(skill_trees[user][search]);
			if (iter != skill_map.end())
			{
				if (skill_idx == iter->second)
				{
					skill_idx++;
					continue;
				}
				else
				{
					check = false;
					break;
				}
			}
		}

		answer = check ? answer + 1 : answer;
		check = check ? check : !check;
		skill_idx = 1;
	}

	return answer;
}