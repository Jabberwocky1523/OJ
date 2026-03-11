#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    vector<int> a(s.length());
    a[0] = 1;
    for (int i = 1; i < s.length(); i++)
    {
        if (s[i] != s[i - 1])
        {
            a[i] = a[i - 1] + 1;
        }
        else
        {
            a[i] = 1;
        }
    }
    cout << *max_element(a.begin(), a.end());
    return 0;
}