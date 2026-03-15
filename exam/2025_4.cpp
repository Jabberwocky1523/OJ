#include <bits/stdc++.h>
using namespace std;
struct edge
{
    int u, v, w;
    edge(int _u, int _v, int _w)
    {
        u = _u, v = _v, w = _w;
    }
};
int find(vector<int> s, int f)
{
    while (s[f] != -1)
    {
        f = s[f];
    }
    return f;
}
bool unionSet(vector<int> &s, int f1, int f2)
{
    int i1 = find(s, f1), i2 = find(s, f2);
    if (i1 == i2)
    {
        return false;
    }
    else
    {
        s[i2] = i1;
        return true;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    int n, m, c, sum = 0;
    cin >> n >> m >> c;
    vector<edge> e;
    for (int i = 0; i < n; i++)
    {
        int w;
        cin >> w;
        e.push_back(edge(0, i + 1, w));
    }
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        e.push_back(edge(u, v, w * c));
    }
    sort(e.begin(), e.end(), [](edge e1, edge e2)
         { return e1.w < e2.w; });
    vector<int> s(n + 1, -1);
    for (edge i : e)
    {
        if (unionSet(s, i.u, i.v))
        {
            sum += i.w;
            n--;
        }
        if (n == 0)
        {
            break;
        }
    }
    cout << sum;
    return 0;
}