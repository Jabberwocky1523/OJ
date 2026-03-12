#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct node
{
    ll diff, cur;
    node(ll _diff, ll _cur)
    {
        diff = _diff, cur = _cur;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    ll d[1001];
    vector<ll> v;
    memset(d, 0, sizeof(ll) * 1001);
    for (ll i = 2; i <= 1000; i++)
    {
        if (d[i] == 0)
        {
            v.push_back(i);
            for (ll j = i * 2; j <= 1000; j += i)
            {
                d[j] = 1;
            }
        }
    }
    ll n, sum = 0;
    cin >> n;
    queue<node> q;
    q.push(node(n, n));
    while (q.size())
    {
        node &nn = q.front();
        q.pop();
        if (nn.diff == 0)
        {
            sum++;
            continue;
        }
        else if (nn.diff == 1)
        {
            continue;
        }
        for (ll i = min(nn.diff, nn.cur); i >= 2; i--)
        {
            if (d[i] == 0)
            {
                q.push(node(nn.diff - i, i));
            }
        }
    }
    cout << sum;
    return 0;
}