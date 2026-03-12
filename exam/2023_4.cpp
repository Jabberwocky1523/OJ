#include <bits/stdc++.h>
using namespace std;
struct node
{
    int sum, id, max;
    node(int _sum, int _id, int _max)
    {
        sum = _sum, id = _id, max = _max;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    int n, m, min_num = INT_MAX;
    cin >> n >> m;
    int edge[n][n], visit[n];
    memset(edge, -1, sizeof(int) * n * n);
    memset(visit, 0, sizeof(int) * n);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        edge[u][v] = w;
    }
    queue<node> q;
    q.push(node(0, 0, -1));
    while (!q.empty())
    {
        node &nn = q.front();
        q.pop();
        if (nn.id == n - 1)
        {
            min_num = min(min_num, nn.sum - nn.max);
        }
        for (int j = 0; j < n; j++)
        {
            if (edge[nn.id][j] != -1)
            {
                q.push(node(nn.sum + edge[nn.id][j], j, max(nn.max, edge[nn.id][j])));
            }
        }
    }
    cout << min_num;
    return 0;
}