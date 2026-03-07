#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int dp[21];
    dp[1] = 1, dp[2] = 2;
    for (int i = 3; i < 20; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    int n;
    cin >> n;
    cout << dp[n];
    return 0;
}