#include<iostream>
using namespace std;

bool mz[52][52];
char arr[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
int main()
{
	int n;
	cin >> n;
	char inp[7];
	char x, y, t;
	for (int i = 0; i < n; ++i)
	{
		cin >> x >> inp >> y;
		if (x > 96) x -= (97 - 26);
		if (y > 96) y -= (97 - 26);

		if (x > 64) x -= 65;
		if (y > 64) y -= 65;

		mz[x][y] = true;
	}

	for (int k = 0; k < 52; ++k) {
		for (int i = 0; i < 52; ++i) {
			for (int j = 0; j < 52; ++j) {
				if (mz[j][k] && mz[k][i]) mz[j][i] = true;
			}
		}
	}
	int result = 0;
	for (int i = 0; i < 52; ++i)
	{
		for (int j = 0; j < 52 ; ++j)
		{
			if (mz[i][j] && i!=j) ++result;
		}
	}
	cout << result << endl;
	for (int i = 0; i < 52; ++i)
	{
		for (int j = 0; j < 52; ++j)
		{
			if (mz[i][j] && i!=j) printf("%c => %c\n", arr[i], arr[j]);
		}
	}
	return 0;
}