#include <bits/stdc++.h>
using namespace std;
void cal(int h, int w, int &sum)
{
    if (w == 0)
    {
        sum += 1;
        sum = sum % 999983;
        return;
    }
    else if (w < 0)
    {
        return;
    }
    cal(h, w - 2, sum);
    cal(h, w - 1, sum);
}
int main()
{
    ios::sync_with_stdio(false);
    int n, sum = 0;
    cin >> n;
    int dp[n];
    dp[0] = 1, dp[1] = 2;
    for (int i = 2; i < n; i++)
    {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 999983;
    }
    cout << dp[n - 1];
    return 0;
}