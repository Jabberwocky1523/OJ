#include <bits/stdc++.h>
using namespace std;
struct edge
{
    int u, v, w;
    edge(int _u, int _v, int _w)
    {
        u = _u;
        v = _v;
        w = _w;
    }
};
int setFind(vector<int> a, int i)
{
    while (a[i] != -1)
    {
        /* code */
        i = a[i];
    }
    return i;
}
bool setUnion(vector<int> &a, int u, int v)
{
    int b = setFind(a, u), c = setFind(a, v);
    if (b != c)
    {
        a[b] = c;
        return true;
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    int n;
    while (cin >> n)
    {
        /* code */
        if (n == 0)
        {
            break;
        }
        int sum = 0;
        int empty = n;
        vector<int> a(n);
        vector<edge> ve;
        for (int i = 0; i < n; i++)
        {
            a[i] = -1;
        }
        int nn = n;
        for (int i = 0; i < (nn * (nn - 1)) / 2; i++)
        {
            int u, v, w, d;
            cin >> u >> v >> w >> d;
            u--, v--;
            if (d == 1)
            {
                if (setUnion(a, u, v))
                {
                    n--;
                }
            }
            else
            {
                ve.push_back(edge(u, v, w));
            }
        }
        sort(ve.begin(), ve.end(), [](edge e1, edge e2)
             { return e1.w < e2.w; });
        // for (int i : a)
        // {
        //     cout << i << " ";
        // }
        // cout << endl;
        for (edge e : ve)
        {
            if (n == 1)
            {
                cout << sum << endl;
                break;
            }
            if (setFind(a, e.u) != setFind(a, e.v))
            {
                setUnion(a, e.u, e.v);
                n--;
                sum += e.w;
            }
        }
    }
    return 0;
}