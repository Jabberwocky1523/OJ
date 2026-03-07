#include <bits/stdc++.h>
using namespace std;
string print(int n)
{
    if (n == 0 || n == 2)
    {
        return to_string(n);
    }
    int i = 0;
    vector<int> v;
    while (n != 0)
    {
        /* code */
        int j = n % 2;
        if (j == 1)
        {
            v.push_back(i);
        }
        i++;
        n /= 2;
    }
    string ans;
    for (auto it = v.rbegin(); it != v.rend(); it++)
    {
        if (*it == 1)
        {
            ans = ans + "2+";
        }
        else
            ans = ans + "2(" + print(*it) + ")" + "+";
    }
    ans.erase(ans.length() - 1, 1);
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    int n;
    while (cin >> n)
    {
        /* code */
        cout << print(n) << endl;
    }
    return 0;
}