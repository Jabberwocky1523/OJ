#include <bits/stdc++.h>
using namespace std;
int n, m, k, max_num = INT_MIN;
int v[101][101];
int id[101];
void bfs(int sum, int depth)
{
    if (depth == k)
    {
        if (sum > max_num)
        {
            max_num = sum;
        }
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (id[i] != m)
        {
            bfs(sum + v[i][id[i]++], depth + 1);
            id[i]--;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        id[i] = 0;
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }
    bfs(0, 0);
    cout << max_num;
    return 0;
}