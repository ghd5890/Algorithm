#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion);

int main()
{
    int n, m;
    vector<string> participant, completion;

    cin >> n >> m;

    participant = vector<string>(n); completion = vector<string>(m);
    for (int i = 0; i < n; i++) cin >> participant[i];
    for (int i = 0; i < m; i++) cin >> completion[i];

    cout << solution(participant, completion) << '\n';

	return 0;
}

string solution(vector<string> participant, vector<string> completion) 
{
    map<string, int> complete;
    string answer = "";

    for (unsigned int i = 0; i < completion.size(); i++)
    {
        if (complete.find(completion[i]) != complete.end()) complete[completion[i]] += 1;
        else complete.insert(pair<string, int>(completion[i], 1));
    }

    for (unsigned int i = 0; i < participant.size(); i++)
    {
        if (complete.find(participant[i]) == complete.end() || (complete.find(participant[i]) != complete.end() && complete[participant[i]] == 0)) answer += participant[i];
        else complete[participant[i]] -= 1;
    }

    return answer;
}