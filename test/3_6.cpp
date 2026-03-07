#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n, x;
    cin >> n >> x;
    vector<long long> v;
    unordered_map<long long, long long> m;
    for (long long i = 0; i < n; i++)
    {
        long long temp;
        cin >> temp;
        v.push_back(temp);
        m[temp]++;
    }
    long long sum = 0;
    for (long long i : v)
    {
        sum += m[i + x];
    }
    cout << sum;
    return 0;
}