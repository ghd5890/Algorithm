#include <iostream>
#define VOLUME 3

using namespace std;

int numbers[3] = { 0 };

int main()
{
	int test = 0;
	bool sol = false;

	cin >> test;
	while (test--)
	{
		sol = sol ? false : sol;

		for (int i = 0; i < VOLUME; i++) cin >> numbers[i];

		for (int x = -100; x <= 100; x++)
		{
			for (int y = -100; y <= 100; y++)
			{
				for (int z = -100; z <= 100; z++)
				{
					if ((x != y && y != z && z != x) && x + y + z == numbers[0] && x * y * z == numbers[1] && (x * x) + (y * y) + (z * z) == numbers[2])
					{
						if (!sol) cout << x << ' ' << y << ' ' << z << '\n';
						sol = true;
					}
				}
			}
		}

		if (!sol) cout << "No solution\n";
 	}

	return 0;
}