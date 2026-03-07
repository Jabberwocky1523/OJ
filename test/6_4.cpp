#include <bits/stdc++.h>
using namespace std;
void print(string s, int depth, int n, string ans, vector<int> v)
{
    if (depth == n)
    {
        cout << ans << endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (v[i] == 0)
        {
            ans += s[i];
            v[i] = 1;
            print(s, depth + 1, n, ans, v);
            ans.erase(ans.end() - 1);
            v[i] = 0;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    string s, ans;
    ans.clear();
    getline(cin, s);
    vector<int> v;
    for (int i = 0; i < s.length(); i++)
    {
        v.push_back(0);
    }
    print(s, 0, s.length(), ans, v);
    return 0;
}