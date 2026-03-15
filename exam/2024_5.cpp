#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> v(n + 1), dp(n + 1);
    int max_num = INT_MIN, max_dp = INT_MIN;
    dp[0] = 0, v[0] = INT_MIN;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    for (int i = 1; i <= n; i++)
    {
        if (v[i] > v[i - 1])
        {
            dp[i] = dp[i - 1] + 1;
        }
        else
        {
            dp[i] = 1;
        }
        if (dp[i] > max_dp)
        {
            max_dp = dp[i];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        // vector<int> temp = v;
        // temp.erase(temp.begin() + i);
        // for (int i = 1; i < temp.size(); i++)
        // {
        //     if (temp[i] > temp[i - 1])
        //     {
        //         dp[i] = dp[i - 1] + 1;
        //     }
        //     else
        //     {
        //         dp[i] = 1;
        //     }
        // }
        // max_num = max(max_num, *max_element(dp.begin(), dp.end()));
        // vector<int> temp = dp;
        // temp[i] = 0;
        // if (i == 0)
        // {
        //     int j = i + 1;
        //     while (j < temp.size() && v[j] > v[j - 1])
        //     {
        //         temp[j]--;
        //         j++;
        //     }
        // }
        // else if (i == n - 1)
        // {
        // }
        // else
        // {
        //     if (v[i] > v[i + 1])
        //     {
        //         if (v[i + 1] > v[i - 1])
        //         {
        //             temp[i + 1] += temp[i - 1];
        //             int j = i + 2;
        //             while (j < temp.size() && v[j] > v[j - 1])
        //             {
        //                 temp[j] = temp[j - 1] + 1;
        //                 j++;
        //             }
        //         }
        //     }
        //     else
        //     {
        //         int j = i + 1;
        //         while (j < temp.size() && v[j] > v[j - 1])
        //         {
        //             temp[j]--;
        //             j++;
        //         }
        //     }
        // }
        // max_num = max(max_num, *max_element(temp.begin(), temp.end()));
        vector<int> temp1 = v, temp2 = dp;
        if (i == n)
        {
            if (temp2[n] == max_dp)
            {
                max_num = max(max_num, max_dp - 1);
            }
            else
            {
                max_num = max(max_num, max_dp);
            }
        }
        else
        {
            auto it1 = temp1.begin() + i, it2 = temp2.begin() + i;
            temp1.erase(temp1.begin() + i), temp2.erase(temp2.begin() + i);
            int max_n = INT_MIN, flag = 0;
            while (it1 != temp1.end() && *(it1) > *(it1 - 1))
            {
                if (*it2 == max_dp)
                {
                    flag = 1;
                }
                *it2 = *(it2 - 1) + 1;
                max_n = max(max_n, *it2);
                it1++, it2++;
            }
            if (flag)
                max_num = max(max_num, max_n);
            else
                max_num = max(max_num, max(max_n, max_dp));
        }

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