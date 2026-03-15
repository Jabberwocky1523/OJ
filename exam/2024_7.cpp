#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// 计算最大公约数
ll gcd(ll a, ll b)
{
    return b ? gcd(b, a % b) : a;
}

// 计算最小公倍数
ll lcm(ll a, ll b)
{
    return a / gcd(a, b) * b;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
    {
        int n;
        ll l, r;
        cin >> n >> l >> r;

        vector<ll> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        ll ans = 0;

        // 枚举所有非空子集，使用位掩码
        for (int mask = 1; mask < (1 << n); mask++)
        {
            ll lcms = 1;
            int bits = 0;
            bool overflow = false;

            for (int i = 0; i < n; i++)
            {
                if (mask >> i & 1)
                {
                    bits++;
                    lcms = lcm(lcms, a[i]);
                    // 检查是否会发生溢出
                    if (lcms > r)
                    {
                        overflow = true;
                        break;
                    }
                }
            }

            if (overflow)
                continue;

            // 计算能被lcms整除的数的个数
            ll cnt = r / lcms - (l - 1) / lcms;

            // 容斥原理：奇数个元素加，偶数个元素减
            if (bits % 2 == 1)
            {
                ans += cnt;
            }
            else
            {
                ans -= cnt;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
