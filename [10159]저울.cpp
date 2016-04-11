#include<iostream>
using namespace std;
#define wH 1
#define Hw 2

int computer[101][101];
int main()
{
	int n, m;
	cin >> n >> m;
	int x, y;
	for (int i = 0; i < m; ++i)
	{
		scanf("%d%d", &x, &y);
		computer[x][y] = wH;
		computer[y][x] = Hw;
	}

	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (computer[i][k] == computer[k][j] && computer[i][k] != 0) computer[i][j] = computer[k][j];
				if (computer[j][k] == computer[k][i] && computer[j][k] != 0) computer[j][i] = computer[k][i];
			}
		}
	}

	int result = 0;
	for (int j = 1; j <= n; ++j) {
		for (int i = 1; i <= n; ++i)
		{
			if (computer[j][i] == 0 && i != j) ++result;
		}
		cout << result << '\n';
		result = 0;
	}
	return 0;
}