#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    vector<int> v;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    cin >> m;
    auto f = find(v.begin(), v.end(), m);
    if (f == v.end())
    {
        cout << -1;
    }
    else
    {
        cout << f - v.begin();
    }
    return 0;
}