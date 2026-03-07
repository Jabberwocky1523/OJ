#include <bits/stdc++.h>
using namespace std;
struct node
{
    int depth;
    int i;
    node(int _i, int _depth)
    {
        i = _i;
        depth = _depth;
    }
};
int bfs(int a[26][2], int i, int g)
{
    queue<node> q;
    q.push(node(i, 0));
    while (!q.empty())
    {
        /* code */
        node t = q.front();
        q.pop();
        if (t.i == g)
        {
            return t.depth;
        }
        for (int j = 0; j < 2; j++)
        {
            if (a[t.i][j] != -1)
            {
                q.push(node(a[t.i][j], t.depth + 1));
            }
        }
    }
    return 0;
}
void print(int i, vector<string> vs)
{
    string ans;
    for (; i >= 2; i--)
    {
        ans += "great-";
    }
    cout << ans + vs[i] << endl;
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    int a[26][2];
    vector<string> vs1 = {"parent", "grandparent"},
                   vs2 = {"child", "grandchild"};
    memset(&a, -1, sizeof(int) * 26 * 2);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        a[s[0] - 'A'][0] = (s[1] != '-' ? s[1] - 'A' : -1);
        a[s[0] - 'A'][1] = (s[2] != '-' ? s[2] - 'A' : -1);
    }
    for (int i = 0; i < m; i++)
    {
        string s;
        cin >> s;
        int temp = bfs(a, s[1] - 'A', s[0] - 'A');
        if (temp == 0)
        {
            temp = -bfs(a, s[0] - 'A', s[1] - 'A') - 1;
        }
        if (temp == -1)
        {
            cout << "-" << endl;
        }
        else if (temp > 0)
        {
            print(temp - 1, vs1);
        }
        else
        {
            print(abs(temp) - 2, vs2);
        }
    }

    return 0;
}