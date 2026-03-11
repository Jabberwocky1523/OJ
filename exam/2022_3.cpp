#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int x, i, j;
    cin >> x >> i >> j;
    bitset<32> bs(x);
    string s = bs.to_string();
    // cout << s << endl;
    swap(s[s.length() - 1 - i], s[s.length() - 1 - j]);
    // cout << s << endl;
    int sum = 0, temp = 1;
    for (auto it = s.rbegin(); it != s.rend(); it++)
    {
        sum += (*it - '0') * temp;
        temp *= 2;
    }
    cout << sum;
    return 0;
}