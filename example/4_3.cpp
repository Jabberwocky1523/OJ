#include <bits/stdc++.h>
using namespace std;
int main()
{
    int k1, k2, k3;
    while (cin >> k1 >> k2 >> k3)
    {
        /* code */
        if (k1 == 0 && k2 == 0 && k3 == 0)
        {
            break;
        }
        string s, s1, s2, s3, ans;
        vector<int> v1, v2, v3;
        getchar();
        getline(cin, s);
        ans.resize(s.length());
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] >= 'a' && s[i] <= 'i')
            {
                v1.push_back(i);
                s1.push_back(s[i]);
            }
            else if (s[i] >= 'j' && s[i] <= 'r')
            {
                v2.push_back(i);
                s2.push_back(s[i]);
            }
            else
            {
                v3.push_back(i);
                s3.push_back(s[i]);
            }
        }
        if (s1.length() != 0)
        {
            k1 = k1 % s1.length();
        }
        if (s2.length() != 0)
        {
            k2 = k2 % s2.length();
        }
        if (s3.length() != 0)
        {
            k3 = k3 % s3.length();
        }
        for (int i = 0; i < v1.size(); i++)
        {
            int j = (i - k1) < 0 ? (i - k1 + s1.length()) : (i - k1);
            ans[v1[i]] = s1[j];
        }
        for (int i = 0; i < v2.size(); i++)
        {
            int j = (i - k2) < 0 ? (i - k2 + s2.length()) : (i - k2);
            ans[v2[i]] = s2[j];
        }
        for (int i = 0; i < v3.size(); i++)
        {
            int j = (i - k3) < 0 ? (i - k3 + s3.length()) : (i - k3);
            ans[v3[i]] = s3[j];
        }
        cout << ans << endl;
    }
    return 0;
}