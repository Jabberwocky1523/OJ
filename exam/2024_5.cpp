#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> v(n), dp(n);
    int max_num = INT_MIN;
    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    for (int i = 1; i < n; i++)
    {
        if (v[i] > v[i - 1])
        {
            dp[i] = dp[i - 1] + 1;
        }
        else
        {
            dp[i] = 1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        vector<int> temp = dp;
        temp[i] = 0;
        if (i == 0)
        {
            int j = i + 1;
            while (j < temp.size() && v[j] > v[j - 1])
            {
                temp[j]--;
                j++;
            }
        }
        else if (i == n - 1)
        {
        }
        else
        {
            if (v[i] > v[i + 1])
            {
                if (v[i + 1] > v[i - 1])
                {
                    temp[i + 1] += temp[i - 1];
                    int j = i + 2;
                    while (j < temp.size() && v[j] > v[j - 1])
                    {
                        temp[j] += temp[i - 1];
                        j++;
                    }
                }
            }
            else
            {
                int j = i + 1;
                while (j < temp.size() && v[j] > v[j - 1])
                {
                    temp[j]--;
                    j++;
                }
            }
        }
        max_num = max(max_num, *max_element(temp.begin(), temp.end()));
        // for (int i : temp)
        // {
        //     cout << i << " ";
        // }
        // cout << endl;
        // cout << max_num;
    }
    cout << max_num;
    return 0;
}