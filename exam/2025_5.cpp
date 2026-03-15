#include <bits/stdc++.h>
using namespace std;
struct point
{
    int x, y, depth;
    point() {}
    point(int _x, int _y, int _depth)
    {
        x = _x, y = _y, depth = _depth;
    }
    point(int _x, int _y)
    {
        x = _x, y = _y, depth = 0;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    char map[n + 1][m + 1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> map[i][j];
        }
    }
    point start, end, d[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    cin >> start.x >> start.y >> end.x >> end.y;
    queue<point> q;
    q.push(start);
    while (q.size())
    {
        point &p = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            point cur(d[i].x + p.x, d[i].y + p.y, p.depth + 1);
            if (cur.x < 1 || cur.x > n || cur.y < 1 || cur.y > m || map[cur.x][cur.y] == '#')
            {
                continue;
            }
            else if (cur.x == end.x && cur.y == end.y)
            {
                cout << cur.depth;
                return 1;
            }
            else
            {
                q.push(cur);
                map[cur.x][cur.y] = '#';
            }
        }
    }
    cout << -1;
    return 0;
}