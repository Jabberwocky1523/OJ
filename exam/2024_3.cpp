#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int n, k;
    double min_num = INT_MAX;
    cin >> n >> k;
    long long dp[n][3], v[n];
    cin >> v[0];
    dp[0][1] = v[0], dp[0][2] = pow(v[0], 2);
    for (int i = 1; i < n; i++)
    {
        cin >> v[i];
        dp[i][1] = dp[i - 1][1] + v[i];
        dp[i][2] = dp[i - 1][2] + pow(v[i], 2);
    }
    for (int i = k - 1; i < n; i++)
    {
        for (int j = 0; i - j + 1 >= k; j++)
        {
            double x1, x2, m = i - j + 1;
            if (j == 0)
            {
                x1 = dp[i][2], x2 = dp[i][1];
            }
            else
            {
                x1 = dp[i][2] - dp[j - 1][2], x2 = dp[i][1] - dp[j - 1][1];
            }
            double cur = x1 / m - pow(x2 / m, 2);
            if (cur < min_num)
            {
                min_num = cur;
            }
        }
    }
    printf("%.4f", sqrt(min_num));
    return 0;
}