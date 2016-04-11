#include<iostream>
using namespace std;

bool computer[101][101];
int main()
{
	int n, m;
	cin >> n >> m;
	int x, y;
	for (int i = 0; i < m; ++i)
	{
		scanf("%d%d", &x, &y);
		computer[x][y] = computer[y][x] = true;
	}

	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (computer[j][k] && computer[k][i] || computer[i][k] && computer[k][j]) computer[i][j] = computer[j][i] = true;
			}
		}
	}
	int result = 0;
	for (int i = 2; i <= n; ++i) if (computer[i][1]) ++result;
	cout << result;
	return 0;
}