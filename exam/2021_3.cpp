#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    long long n, s;
    cin >> n >> s;
    long long a, b, mod = 1e9 + 7;
    cin >> a >> b;
    vector<long long> x(n), y(n + 1);
    y[0] = 0, x[0] = a % mod, y[1] = a;
    for (int i = 1; i < n; i++)
    {
        x[i] = (x[i - 1] * b) % mod;
        y[i + 1] = y[i] + x[i];
    }
    long long min_len = INT64_MAX, left = 1, cur = y[1];
    for (int i = 1; i <= n; i++)
    {
        cur = y[i] - y[left - 1];
        while (cur >= s && left <= i)
        {
            min_len = min(i - left + 1, min_len);
            left++;
            cur = y[i] - y[left - 1];
        }
    }
    if (min_len == INT64_MAX)
    {
        cout << -1 << endl;
    }
    else
        cout << min_len << endl;
    return 0;
}