#include <bits/stdc++.h>
using namespace std;
struct node
{
    /* data */
    int i, time;
    node(int _i, int _time)
    {
        i = _i, time = _time;
    }
};
int n, k;
int a[100001];
inline void push(queue<node> &q, int i, int time)
{
    // if (i < 0 || i > k + 1 || a[i] == 1)
    // {
    // }
    // else
    // {
    //     a[i] = 1;
    //     q.push(node(i, time));
    // }
    if (i >= 0 && i <= k + 1 && a[i] == 0)
    {
        a[i] = 1;
        q.push(node(i, time));
    }
}
int main()
{
    ios::sync_with_stdio(false);
    while (cin >> n >> k)
    {
        /* code */
        if (n >= k)
        {
            cout << n - k << endl;
            continue;
        }
        queue<node> q;
        for (int i = 0; i <= 100000; i++)
        {
            a[i] = 0;
        }
        q.push(node(n, 0));
        a[n] = 1;
        while (!q.empty())
        {
            /* code */
            node cur = q.front();
            q.pop();
            int i = cur.i, time = cur.time;
            if (cur.i == k)
            {
                cout << cur.time << endl;
                continue;
            }
            // if (cur.i > k)
            // {
            //     push(q, i - 1, time + 1);
            // }
            // elsea
            // {
            push(q, i * 2, time + 1);
            push(q, i - 1, time + 1);
            push(q, i + 1, time + 1);
            // }
        }
    }
    return 0;
}