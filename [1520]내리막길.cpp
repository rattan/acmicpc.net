#include<iostream>
#include<stack>
using namespace std;

int map[500][500];
int cnt[500][500];
const int ax[] = { 0,0,1,-1 };
const int ay[] = { 1,-1,0,0 };
int dy, dx;

int sol(int x, int y)
{
	if (x == dx - 1 && y == dy - 1) return 1;
	if (cnt[y][x]) return cnt[y][x];

	int &ans = cnt[y][x];

	for (int i = 0; i < 4; ++i)
	{
		int nx = x + ax[i];
		int ny = y + ay[i];
		if (0 <= nx && nx < dx && 0 <= ny && ny < dy) {
			if (map[y][x] > map[ny][nx])
			{
				ans += sol(nx, ny);
			}
		}
	}
		return ans;
}

int main()
{
	cin >> dy >> dx;



	for (int i = 0; i < dy; ++i)
	{
		for (int j = 0; j < dx; ++j)
		{
			scanf("%d", &map[i][j]);
		}
	}

	cout << sol(0, 0);
	return 0;

}
