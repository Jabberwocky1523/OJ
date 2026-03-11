#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    long long n, s;
    cin >> n >> s;
    vector<long long> v(n);
    for (long long i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    long long middle = (v.size() - 1) / 2;
    long long sum = 0;
    if (s >= v[middle])
    {
        for (long long i = middle; v[i] <= s; i++)
        {
            sum += abs(s - v[i]);
        }
    }
    else
    {
        for (long long i = middle; v[i] > s; i--)
        {
            sum += abs(s - v[i]);
        }
    }
    cout << sum;
    return 0;
}