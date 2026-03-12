#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    map<int, int> um;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        um[v[i] + x]++;
    }
    int sum = 0;
    for (int i : v)
    {
        sum += um[i];
    }
    cout << sum;
    return 0;
}