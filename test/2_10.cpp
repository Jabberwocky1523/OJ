#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    vector<vector<string>> vs = {
        {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
        {"X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
        {"C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
        {"M"}};
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        string ans, res = to_string(n);
        vector<int> temp;
        for (char c : res)
        {
            temp.push_back(c - '0');
        }
        int c = 0;
        for (int i = temp.size() - 1; i >= 0; i--)
        {
            if (temp[i] == 0)
            {
                c++;
                continue;
            }
            ans = (vs[c][temp[i] - 1]) + ans;
            c++;
        }
        cout << ans << endl;
    }
    return 0;
}