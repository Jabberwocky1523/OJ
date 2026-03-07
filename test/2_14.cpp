#include <bits/stdc++.h>
using namespace std;
struct s
{
    vector<int> s1;
    vector<int> s2;
    string s3;
};
int main()
{
    int n, k, n1;
    cin >> n >> k;
    vector<s> vs;
    for (int i = 0; i < k; i++)
    {
        cin >> n1;
        s tt;
        for (int j = 0; j < n1; j++)
        {
            int t;
            cin >> t;
            tt.s1.push_back(t);
        }
        for (int j = 0; j < n1; j++)
        {
            int t;
            cin >> t;
            tt.s2.push_back(t);
        }
        char c;
        cin >> c;
        tt.s3 += c;
        vs.push_back(tt);
    }
    int a[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = 0;
    }
    vector<int> flag1(n), flag2(n);
    int flag = 0;
    for (s ss : vs)
    {
        if (ss.s3 == "=")
        {
            for (int i : ss.s1)
            {
                a[i - 1] = 1;
            }
            for (int i : ss.s2)
            {
                a[i - 1] = 1;
            }
        }
        else
        {
            flag++;
            if (ss.s3 == "<")
            {
                for (int i : ss.s1)
                {
                    flag1[i - 1]++;
                }
                for (int i : ss.s2)
                {
                    flag2[i - 1]++;
                }
            }
            else
            {
                for (int i : ss.s1)
                {
                    flag2[i - 1]++;
                }
                for (int i : ss.s2)
                {
                    flag1[i - 1]++;
                }
            }
        }
    }
    int sum1 = 0, sum2 = 0, index1 = 0, index2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            if (flag1[i] > 0 && flag2[i] > 0)
            {
                a[i] = 1;
                continue;
            }
            else if (flag1[i] == 0 && flag2[i] > 0)
            {
                if (flag2[i] == flag)
                {
                    index2 = i;
                    sum2++;
                }
            }
            else if (flag1[i] > 0 && flag2[i] == 0)
            {
                if (flag1[i] == flag)
                {
                    index2 = i;
                    sum2++;
                }
            }
            else
            {
                sum1++;
                index1 = i;
            }
        }
    }
    if (sum2 == 1)
    {
        cout << index2 + 1;
    }
    else if (sum1 == 1)
    {
        cout << index1 + 1;
    }
    else
    {
        cout << 0;
    }
    // vector<vector<int>> um;
    // um.resize(n, vector<int>(0));
    // vector<int> flag;
    // for (int i = 0; i < vs.size(); i++)
    // {
    //     s ss = vs[i];
    //     if (ss.s3 == "=")
    //     {
    //         for (int c : ss.s1)
    //         {
    //             a[c - 1] = 1;
    //         }
    //         for (char c : ss.s2)
    //         {
    //             a[c - 1] = 1;
    //         }
    //     }
    //     else
    //     {
    //         for (int c : ss.s1)
    //         {
    //             um[c - 1].push_back(i);
    //         }
    //         for (int c : ss.s2)
    //         {
    //             um[c - 1].push_back(i);
    //         }
    //         flag.push_back(i);
    //     }
    // }
    // int sum = 0, last1 = 0, last2 = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     int h_or_l = 0;
    //     if (a[i] == 0)
    //     {
    //         if (um[i].empty())
    //         {
    //             sum++;
    //             last1 = i + 1;
    //             continue;
    //         }
    //         s ss = vs[um[i][0]];
    //         auto f1 = find(ss.s1.begin(), ss.s2.end(), i), f2 = find(ss.s1.begin(), ss.s2.end(), i);
    //         string s3 = ss.s3;
    //         if (f1 != ss.s1.end())
    //         {
    //             if (s3 == "<")
    //             {
    //                 h_or_l = 1;
    //             }
    //             else
    //             {
    //                 h_or_l = 0;
    //             }
    //         }
    //         else if (f2 != ss.s2.end())
    //         {
    //             if (s3 == "<")
    //             {
    //                 h_or_l = 0;
    //             }
    //             else
    //             {
    //                 h_or_l = 1;
    //             }
    //         }
    //         int j = 0;
    //         for (; j < flag.size(); j++)
    //         {
    //             ss = vs[flag[j]];
    //             auto f1 = find(ss.s1.begin(), ss.s2.end(), i), f2 = find(ss.s1.begin(), ss.s2.end(), i);
    //             string s3 = ss.s3;
    //             if (f1 == ss.s1.end() && f2 == ss.s2.end())
    //             {
    //                 break;
    //             }
    //             if (f1 != ss.s1.end())
    //             {
    //                 if (s3 == "<")
    //                 {
    //                     if (h_or_l)
    //                         continue;
    //                     else
    //                         break;
    //                 }
    //                 else
    //                 {
    //                     if (h_or_l)
    //                         break;
    //                     else
    //                         continue;
    //                 }
    //             }
    //             else
    //             {
    //                 if (s3 == "<")
    //                 {
    //                     if (h_or_l)
    //                         break;
    //                     else
    //                         continue;
    //                 }
    //                 else
    //                 {
    //                     if (h_or_l)
    //                         continue;
    //                     else
    //                         break;
    //                 }
    //             }
    //         }
    //         if (j == flag.size())
    //         {
    //             a[i] = -1;
    //             last2 = i + 1;
    //         }
    //     }
    // }
    // int sum2 = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     if (a[i] == -1)
    //     {
    //         sum2++;
    //     }
    // }
    // if (sum2 > 1)
    // {
    //     cout << 0;
    //     return 0;
    // }
    // else if (sum2 == 1)
    // {
    //     cout << last2;
    //     return 0;
    // }
    // if (sum > 0)
    // {
    //     if (sum == 1)
    //     {
    //         cout << last1;
    //     }
    //     else
    //     {
    //         cout << 0;
    //     }
    // }
    return 0;
}