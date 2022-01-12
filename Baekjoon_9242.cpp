#include <iostream>
#include <string>
#include <vector>
#define JUMP 4
#define WIDTH 3
#define HEIGHT 5

using namespace std;

typedef unsigned int UNS_INT;

char numbers[10][HEIGHT][WIDTH + 1] = {
	// 0
	{
		"***",		
		"* *", 
		"* *", 
		"* *", 
		"***"
	},
	// 1
	{	"  *",
		"  *",
		"  *",
		"  *",
		"  *"
	},
	 // 2
	{
		"***",
		"  *",
		"***",
		"*  ",
		 "***"
	},
	 // 3
	{	
		"***",
		 "  *",
		"***",
		"  *",
		"***"
	},
	// 4
	{
		"* *",
		"* *",
		"***",
		"  *",
		"  *"
	},
	// 5
	{
		"***",
		"*  ",
		"***",
		"  *",
		"***"
	},
	// 6
	{
		"***",
		"*  ",
		"***",
		"* *",
		"***"
	},
	// 7
	{
		"***",
		"  *",
		"  *",
		"  *",
		"  *"
	},
	// 8
	{
		"***",
		"* *",
		"***",
		"* *",
		"***"
	},
	// 9
	{
		"***",
		"* *",
		"***",
		"  *",
		"***"
	}
};

int main()
{
	vector<string> code;
	vector<bool> num_check;
	string answer = "BEER!!\n";
	bool check = false;
	int start = 0, sum = 0;

	code = vector<string>(HEIGHT);
	for (UNS_INT i = 0; i < HEIGHT; i++) getline(cin, code[i]);

	// 코드를 확인한다.
	while (start < code[0].length())
	{
		num_check = vector<bool>(10, true);
		check = false;
		// 각 자리의 숫자를 확인한다.
		for (int num = 0; num < 10; num++)
		{
			for (int row = 0; row < HEIGHT; row++)
			{
				for (int col = 0; col < WIDTH; col++)
				{
					if (numbers[num][row][col] != code[row][start + col]) // 쓰여있는 코드가 숫자가 아닌 경우
					{
						num_check[num] = false;
						break;
					}
				}
				if (!num_check[num]) break;
			}
		}

		// 일치하는 숫자가 있는 지 확인한다.
		for (int num = 0; num < 10; num++)
		{
			if (num_check[num])
			{
				check = true;
				sum += num;
				sum *= 10;
			}
		}

		// 일치하는 숫자가 없으면 while 문을 탈출한다.
		if (!check) break;

		start += JUMP;
	}

	sum /= 10;

	if (check && sum % 6 == 0) answer = "BEER!!\n";
	else answer = "BOOM!!\n";

	cout << answer;

	return 0;
}