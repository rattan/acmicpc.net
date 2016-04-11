#include<iostream>
using namespace std;

int bus[101][101];
int main()
{
	int n, m;
	cin >> n >> m;
	int x, y, c;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)bus[i][j] = 200001;
	}

	for (int i = 0; i < m; ++i)
	{
		scanf("%d%d%d", &x, &y, &c);
		if (bus[x][y]>c) bus[x][y] = c;
	}

	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (bus[i][k] + bus[k][j] < bus[i][j] && i != j) bus[i][j] = bus[i][k] + bus[k][j];
			}
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (bus[i][j] == 200001) bus[i][j] = 0;
			printf("%d ", bus[i][j]);
		}
		printf("\n");
	}


	return 0;
}