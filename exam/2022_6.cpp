#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    int dp[n + 1][k + 1];
    memset(dp, 0, sizeof(int) * (n + 1) * (k + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (j == 1)
            {
                dp[i][j] = 1;
            }
            else
            {
                for (int z = i - 1; z >= 1; z--)
                {
                    dp[i][j] += dp[i - z][j - 1];
                    if (i == n && j == k && dp[i - z][j - 1] != 0)
                    {
                        cout << i - z << " " << j - 1 << " " << dp[i - z][j - 1] << endl;
                    }
                }
            }
        }
    }
    cout << dp[n][k];
    return 0;
}