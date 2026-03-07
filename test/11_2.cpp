#include <bits/stdc++.h>
using namespace std;
int v[101][101];
int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> v[i][j];
        }
    }
    int maxSum = INT_MIN;
    for (int k1 = 0; k1 < n; k1++)
    {
        for (int k2 = k1; k2 < n; k2++)
        {
            vector<int> vi;
            for (int j = 0; j < n; j++)
            {
                int sum = 0;
                for (int i = k1; i <= k2; i++)
                {
                    sum += v[i][j];
                }
                vi.push_back(sum);
            }
            vector<int> dp(n);
            dp[0] = vi[0];
            for (int i = 1; i < n; i++)
            {
                dp[i] = max(dp[i - 1] + vi[i], vi[i]);
            }
            int temp = *max_element(dp.begin(), dp.end());
            if (temp > maxSum)
            {
                maxSum = temp;
            }
        }
    }
    cout << maxSum;
    return 0;
}