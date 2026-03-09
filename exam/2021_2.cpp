#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int r, c, n, k;
    cin >> r >> c >> n >> k;
    int prefix[c + 1][r + 1];
    memset(prefix, 0, sizeof(int) * (c + 1) * (r + 1));
    for (int i = 0; i < n; i++)
    {
        int rr, cc;
        cin >> rr >> cc;
        for (int j = rr; j <= r; j++)
        {
            prefix[cc][j]++;
        }
    }
    int sum = 0;
    for (int i1 = 1; i1 <= r; i1++)
    {
        for (int j1 = 1; j1 <= c; j1++)
        {
            for (int i2 = i1; i2 <= r; i2++)
            {
                for (int j2 = j1; j2 <= c; j2++)
                {
                    int temp = 0;
                    for (int k = j1; k <= j2; k++)
                    {
                        temp += prefix[k][i2] - prefix[k][i1 - 1];
                    }
                    if (temp >= k)
                    {
                        sum++;
                    }
                }
            }
        }
    }
    cout << sum;
    return 0;
}