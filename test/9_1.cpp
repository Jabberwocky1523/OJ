#include <bits/stdc++.h>
using namespace std;
struct node
{
    int x, y, depth, direction;
    node() {}
    node(int _x, int _y, int _depth, int _direction)
    {
        x = _x;
        y = _y;
        depth = _depth;
        direction = _direction;
    }
    node(int _x, int _y, int _depth)
    {
        x = _x;
        y = _y;
        depth = _depth;
    }
};
int bb[101][101][4];
char v[101][101];
int m, n, k;
bool operator==(node n1, node n2)
{
    return n1.x == n2.x && n1.y == n2.y;
}
void push(queue<node> &q, int x, int y, int depth, int lastdirection, int direction)
{
    if (x < 0 || y < 0 || x > m - 1 || y > n - 1 || v[x][y] == '*' || depth > k)
    {
        return;
    }
    else
    {
        if (lastdirection != direction)
        {
            depth++;
        }
        if (depth > k)
        {
            return;
        }
        if (depth < bb[x][y][direction - 1])
        {
            q.push(node{x, y, depth, direction});
            bb[x][y][direction - 1] = depth;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> m >> n;
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < n; k++)
            {
                cin >> v[j][k];
                for (int z = 0; z < 4; z++)
                    bb[j][k][z] = INT_MAX;
            }
        }
        int x1, y1, x2, y2;
        cin >> k >> y1 >> x1 >> y2 >> x2;
        queue<node> q;
        node n1(x1 - 1, y1 - 1, -1, 0), n2(x2 - 1, y2 - 1, -1, 0);
        q.push(n1);
        for (int z = 0; z < 4; z++)
            bb[n1.x][n1.y][z] = 0;
        int flag = false;
        while (!q.empty())
        {
            /* code */
            node &nn = q.front();
            q.pop();
            if (nn.depth > k)
            {
                continue;
            }
            else if (nn == n2)
            {
                flag = true;
                break;
            }
            int x = nn.x, y = nn.y, depth = nn.depth, direction = nn.direction;
            push(q, x, y + 1, depth, direction, 1);
            push(q, x, y - 1, depth, direction, 2);
            push(q, x + 1, y, depth, direction, 3);
            push(q, x - 1, y, depth, direction, 4);
        }
        if (flag)
        {
            cout << "yes" << endl;
        }
        else
        {
            cout << "no" << endl;
        }
    }
    return 0;
}