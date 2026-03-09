#include <bits/stdc++.h>
using namespace std;
void bfs(int w[101], int n, int left, int right, int visit[101], unordered_map<int, int> &um)
{
    for (int i = 0; i < n; i++)
    {
        if (visit[i] == 0)
        {
            left += w[i];
            visit[i] = 1;
            um[abs(left - right)] = 1;
            bfs(w, n, left, right, visit, um);
            left -= w[i];
            right += w[i];
            um[abs(left - right)] = 1;
            bfs(w, n, left, right, visit, um);
            right -= w[i];
            visit[i] = 0;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    int t, w[101], visit[101], n, q;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        memset(visit, 0, 101 * sizeof(int));
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            cin >> w[j];
        }
        cin >> q;
        unordered_map<int, int> um;
        bfs(w, n, 0, 0, visit, um);
        for (int k = 0; k < q; k++)
        {
            int temp;
            cin >> temp;
            cout << um[temp];
        }
        cout << endl;
    }
    return 0;
}