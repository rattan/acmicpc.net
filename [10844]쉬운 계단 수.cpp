#include<iostream>
using namespace std;

long long int map[11][100];

int main()
{
	int n;
	cin >> n;

	for (int i = 1; i < 100; ++i)
	{
		map[0][i] = i;
	}
	for (int i = 0; i < 10; ++i)map[i][0] = 1;

	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			if (j == 0) map[j][i] = (map[j + 1][i - 1]);
			else map[j][i] = (map[j - 1][i - 1] + map[j + 1][i - 1]) % 1000000000;
		}
	}

	int result = 0;
	for (int i = 1; i < 10; ++i) result = (result + map[i][n - 1]) % 1000000000;

	cout << result;
	return 0;
}