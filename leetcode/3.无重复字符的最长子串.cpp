#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    int l = 0, r = 1;
    int max_num = 1;
    unordered_map<char, int> um;
    um[s[0]] = 1;
    while (r <= s.length() - 1)
    {
        while (r <= s.length() - 1 && um[s[r]] == 0)
        {
            um[s[r]] = 1;
            r++;
        }
        max_num = max(max_num, r - l);
        if (r != s.length())
        {
            while (s[l] != s[r])
            {
                um[s[l]]--;
                l++;
            }
            um[s[l]]--;
            l++;
        }
    }
    cout << max_num;
    return 0;
}