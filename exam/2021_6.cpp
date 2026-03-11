#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int n;
    while (cin >> n)
    {
        vector<int> v(n), dp(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        dp[0] = 0;
        for (int i = 1; i < n; i++)
        {
            if (v[i] >= v[i - 1])
            {
                dp[i] = v[i] - v[i - 1] + dp[i - 1];
            }
            else
            {
                dp[i] = 0;
            }
        }
        cout << *max_element(dp.begin(), dp.end()) << endl;
    }
    return 0;
}