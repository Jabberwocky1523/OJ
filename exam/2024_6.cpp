#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n, l, r;
        cin >> n >> l >> r;
        vector<int> v(n);
        unordered_map<int, int> um;
        for (int j = 0; j < n; j++)
        {
            cin >> v[j];
        }
        int sum = 0;
        for (int j : v)
        {
            int p = l / j + !!(l % j);
            for (int k = p * j; k <= r; k += j)
            {
                if (um[k] == 0)
                {
                    um[k] = 1;
                    sum++;
                }
            }
        }
        cout << sum << endl;
    }
    return 0;
}