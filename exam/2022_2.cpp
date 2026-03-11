#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int n, m, k;
    while (cin >> n >> m >> k)
    {
        vector<int> a(n), b(m), c;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int j = 0; j < m; j++)
        {
            cin >> b[j];
        }
        unordered_map<int, int> um;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (um[a[i] * b[j]] == 0)
                {
                    c.push_back(a[i] * b[j]);
                    um[a[i] * b[j]] = 1;
                }
            }
        }
        sort(c.begin(), c.end());
        cout << c[c.size() - k] << endl;
    }
    return 0;
}