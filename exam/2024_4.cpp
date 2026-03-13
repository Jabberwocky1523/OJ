#include <bits/stdc++.h>
using namespace std;
void func(string s, int &num)
{
    if (s.length() < 2)
    {
        return;
    }
    string rs = s;
    reverse(s.begin(), s.end());
    if (s == rs)
    {
        num++;
    }
    rs = s.substr(0, floor(s.length() / 2));
    rs = rs.substr(lower_bound(rs.begin(), rs.end(), '1') - rs.begin(), -1);
    func(rs, num);
}
int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    bitset<32> bs(n);
    string s = bs.to_string();
    s = s.substr(lower_bound(s.begin(), s.end(), '1') - s.begin(), -1);
    int num = 0;
    func(s, num);
    cout << num;
    return 0;
}