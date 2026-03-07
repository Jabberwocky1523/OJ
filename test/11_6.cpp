#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int m = 40, n;
    cin >> n;
    vector<int> v(n);
    int dp[n + 1][m + 1];
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            dp[i][j] = 0;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        if (i == v[0])
        {
            dp[1][i] = 1;
        }
        else
        {
            dp[1][i] = 0;
        }
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (j - v[i - 1] == 0)
            {
                dp[i][j] = 1 + dp[i - 1][j];
            }
            else if (j - v[i - 1] > 0)
            {
                int a = dp[i - 1][j], b = dp[i - 1][j - v[i - 1]];
                if (a == 0 && b == 0)
                {
                    dp[i][j] = 0;
                }
                else if (a != 0 && b != 0)
                {
                    dp[i][j] = a + b;
                }
                else if (a != 0 && b == 0)
                {
                    dp[i][j] = a;
                }
                else
                {
                    dp[i][j] = b;
                }
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= m; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << dp[n][m];
    return 0;
}