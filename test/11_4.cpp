#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int n;
    while (cin >> n)
    {
        /* code */
        vector<int> v(n), dp(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        dp[0] = v[0];
        for (int i = 1; i < n; i++)
        {
            int j = i - 1;
            vector<int> vi;
            for (; j >= 0; j--)
            {
                if (v[i] > v[j])
                {
                    vi.push_back(dp[j]);
                }
            }
            dp[i] = *max_element(vi.begin(), vi.end()) + v[i];
        }
        // for (int i = 0; i < n; i++)
        // {
        //     cout << dp[i] << " ";
        // }
        // cout << endl;
        cout << *max_element(dp.begin(), dp.end()) << endl;
    }
    return 0;
}