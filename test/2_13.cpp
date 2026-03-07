#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<string> vs;
    for (int i = 0; i < 3; i++)
    {
        string temp;
        getline(cin, temp);
        vs.push_back(temp);
    }
    int a[12] = {0};
    vector<vector<int>> um;
    um.resize(12, vector<int>(0));
    vector<int> flag;
    for (int i = 0; i < vs.size(); i++)
    {
        string s = vs[i];
        string s1 = s.substr(0, s.find(" ")),
               s2 = s.substr(s.find(" ") + 1, s.find(" ")),
               s3 = s.substr(s.find_last_of(" ") + 1, -1);
        if (s3 == "even")
        {
            for (char c : s1)
            {
                a[c - 'A'] = 1;
            }
            for (char c : s2)
            {
                a[c - 'A'] = 1;
            }
        }
        else
        {
            for (char c : s1)
            {
                um[c - 'A'].push_back(i);
            }
            for (char c : s2)
            {
                um[c - 'A'].push_back(i);
            }
            flag.push_back(i);
        }
    }
    for (int i = 0; i < 12; i++)
    {
        int h_or_l = 0;
        if (a[i] == 0)
        {
            if (um[i].empty())
            {
                continue;
            }
            string s = vs[um[i][0]];
            string s1 = s.substr(0, s.find(" ")),
                   s2 = s.substr(s.find(" ") + 1, s.find(" ")),
                   s3 = s.substr(s.find_last_of(" ") + 1, -1);
            auto f1 = s1.find('A' + i), f2 = s2.find('A' + i);
            if (f1 != string::npos)
            {
                if (s3 == "up")
                {
                    h_or_l = 1;
                }
                else
                {
                    h_or_l = 0;
                }
            }
            else if (f2 != string::npos)
            {
                if (s3 == "up")
                {
                    h_or_l = 0;
                }
                else
                {
                    h_or_l = 1;
                }
            }
            int j = 0;
            for (; j < flag.size(); j++)
            {
                s = vs[flag[j]];
                s1 = s.substr(0, s.find(" ")),
                s2 = s.substr(s.find(" ") + 1, s.find(" ")),
                s3 = s.substr(s.find_last_of(" ") + 1, -1);
                f1 = s1.find('A' + i), f2 = s2.find('A' + i);
                if (f1 == string::npos && f2 == string::npos)
                {
                    break;
                }
                if (f1 != string::npos)
                {
                    if (s3 == "up")
                    {
                        if (h_or_l)
                            continue;
                        else
                            break;
                    }
                    else
                    {
                        if (h_or_l)
                            break;
                        else
                            continue;
                    }
                }
                else
                {
                    if (s3 == "up")
                    {
                        if (h_or_l)
                            break;
                        else
                            continue;
                    }
                    else
                    {
                        if (h_or_l)
                            continue;
                        else
                            break;
                    }
                }
            }
            if (j == flag.size())
            {
                char ans = 'A' + i;
                if (h_or_l)
                {
                    cout << ans << " is the counterfeit coin and it is heavy.";
                }
                else
                {
                    cout << ans << " is the counterfeit coin and it is light.";
                }
                return 0;
            }
        }
    }
    return 0;
}