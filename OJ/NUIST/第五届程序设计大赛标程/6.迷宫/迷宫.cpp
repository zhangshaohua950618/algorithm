#include <iostream>
#include <queue>
using namespace std;

class coor
{
	public:
		int x, y, dist;
};

const int dx[5] = {0, -1, 0, 1, 0}, dy[5] = {0, 0, 1, 0, -1};
int maze[101][101], m, n;
bool visited[101][101];

void bfs()
{
	bool get_terminate = false;
	queue <class coor> q;
	visited[1][1] = true;
	class coor temp = {1, 1, 0}, u;
	q.push(temp);
	while (!q.empty())
	{
		u = q.front();
		q.pop();
		if (u.x == m && u.y == n)
		{
			get_terminate = true;
			break;
		}
		for (int i = 1;i <= 4;i++)
		{
			int x = u.x+dx[i], y = u.y+dy[i];
			if (maze[x][y] != 1 && x > 0 && x <= m && y > 0 && y <= n &&
				!visited[x][y])
			{
				class coor v = {x, y, u.dist+1};
				visited[x][y] = true;
				q.push(v);
			}
		}
	}
	if (!get_terminate)
		cout << -1 << endl;
	else
		cout << u.dist << endl;
}

int main()
{
	while (cin >> m >> n)
	{
		for (int i = 1;i <= m;i++)
			for (int j = 1;j <= n;cin >> maze[i][j], visited[i][j] = false, j++);
		bfs();
	}
	return 0;
}
