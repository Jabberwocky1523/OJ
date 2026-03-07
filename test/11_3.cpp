#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int n;
    while (cin >> n)
    {
        /* code */
        if (n == 0)
        {
            break;
        }
        vector<int> v(n);
        int flag = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            if (v[i] >= 0)
            {
                flag = 1;
            }
        }
        if (flag == 0)
        {
            cout << 0 << " " << *v.begin() << " " << *v.rbegin() << endl;
            continue;
        }
        int dp[n], dpindex[n], last = 0, index = 0;
        dp[0] = v[0], dpindex[0] = 0;
        int max = dp[0];
        for (int i = 1; i < n; i++)
        {
            if (dp[i - 1] < 0)
            {
                dp[i] = v[i];
                dpindex[i] = i;
                last = i;
            }
            else
            {
                dp[i] = dp[i - 1] + v[i];
                dpindex[i] = dpindex[i - 1];
            }
            if (max < dp[i])
            {
                max = dp[i];
                index = i;
            }
        }
        // for (int i = 0; i < n; i++)
        // {
        //     cout << dp[i];
        // }
        // cout << index << endl;
        cout << dp[index] << " " << v[dpindex[index]] << " " << v[index] << endl;
    }
    return 0;
}