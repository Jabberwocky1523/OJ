#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int n, m, sum = 0, nn = 0;
    cin >> n >> m;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {

        int a, b;
        cin >> a >> b;
        if (a >= b)
        {
            sum += a;
            nn++;
        }
        else
        {
            sum += b;
            v.push_back(b - a);
        }
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < m - nn; i++)
    {
        sum -= v[i];
    }
    cout << sum;
    return 0;
}