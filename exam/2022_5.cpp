#include <bits/stdc++.h>
using namespace std;
int t(int a)
{
    int ans = 0;
    while (a != 0)
    {
        ans++;
        a /= 10;
    }
    return ans;
}
bool cmp(int a, int b)
{
    int a1 = t(abs(a)), b1 = t(abs(b));
    if (a1 == b1)
    {
        return a < b;
    }
    else
    {
        return a1 > b1;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    vector<int> v;
    int temp;
    while (cin >> temp)
    {
        v.push_back(temp);
    }
    sort(v.begin(), v.end(), cmp);
    for (int i : v)
    {
        cout << i << " ";
    }
    return 0;
}