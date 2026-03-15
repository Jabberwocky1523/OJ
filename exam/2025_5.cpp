#include <bits/stdc++.h>
using namespace std;
int n, m;
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
bool check(point cur, vector<vector<char>> &map)
{
    if (cur.x < 1 || cur.x > n || cur.y < 1 || cur.y > m || map[cur.x][cur.y] == '#')
    {
        return false;
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    vector<vector<char>> map;
    map.resize(n + 1, vector<char>(m + 1));
    int distance[n + 1][m + 1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> map[i][j];
            distance[i][j] = -1;
            // cout << map[i][j];
        }
        // cout << endl;
    }
    point start, end, d[4] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    cin >> start.x >> start.y >> end.x >> end.y;
    start.depth = 0;
    distance[start.x][start.y] = 0;
    queue<point> q;
    q.push(start);
    while (q.size())
    {
        point &p = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            point cur(p.x, p.y, p.depth + 1);
            // while (check(point(cur.x + d[i].x, cur.y + d[i].y)) && map[cur.x + d[i].x][cur.y + d[i].y] != '#')
            // {
            //     cur.x += d[i].x;
            //     cur.y += d[i].y;
            // }
            while (check(cur, map))
            {
                cur.x += d[i].x, cur.y += d[i].y;
            }
            if (cur.x != p.x || cur.y != p.y)
                cur.x -= d[i].x, cur.y -= d[i].y;
            // cout << cur.x << " " << cur.y << endl;
            if (distance[cur.x][cur.y] == -1)
            {
                q.push(cur);
                distance[cur.x][cur.y] = distance[p.x][p.y] + 1;
            }
        }
    }
    cout << distance[end.x][end.y];
    return 0;
}