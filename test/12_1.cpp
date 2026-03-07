#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int m, n;
    cin >> m >> n;
    string x, ans;
    cin >> x;
    int64_t sum = 0, temp = 1;
    for (auto it = x.rbegin(); it != x.rend(); it++)
    {
        int num = 0;
        if (*it >= '0' && *it <= '9')
        {
            num = *it - '0';
        }
        else
        {
            num = *it - 'A' + 10;
        }
        sum += num * temp;
        temp *= m;
    }
    while (sum != 0)
    {
        /* code */
        int temp1 = sum % n;
        if (temp1 <= 9)
        {
            ans.push_back('0' + temp1);
        }
        else
        {
            ans.push_back('a' + temp1 - 10);
        }
        sum -= temp1;
        sum /= n;
    }
    reverse(ans.begin(), ans.end());
    cout << ans;
    return 0;
}