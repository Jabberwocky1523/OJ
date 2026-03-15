#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}
ll lcm(ll a, ll b)
{
    return a / gcd(a, b) * b;
}
int main()
{
    ios::sync_with_stdio(false);
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll l = 0, r = k * *min_element(a.begin(), a.end()), ans = INT64_MAX;
    while (l <= r)
    {
        ll mid = l + (r - l) / 2, sum = 0;
        for (ll li : a)
        {
            sum += mid / li;
            if (sum >= k)
            {
                break;
            }
        }
        if (sum >= k)
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << ans;
    return 0;
}