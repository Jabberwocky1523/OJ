#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    string s, res, ans;
    getline(cin, s);
    res.push_back(s[0]);
    for (int i = 1; i < s.length(); i++)
    {
        if (s[i] == s[i - 1])
        {
            res.push_back(s[i]);
        }
        else if (s[i] > s[i - 1])
        {
            for (char c : res)
            {
                ans.push_back(c);
                ans.push_back(c);
            }
            res.clear();
            res.push_back(s[i]);
        }
        else
        {
            ans += res;
            res.clear();
            res.push_back(s[i]);
        }
    }
    ans += res;
    cout << ans;
    return 0;
}