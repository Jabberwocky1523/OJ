#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int n, m, k;
    while (cin >> n >> m >> k)
    {
        int a[n + 1];
        for (int i = 0; i <= n; i++)
        {
            a[i] = 0;
        }
        for (int i = 0; i < m; i++)
        {
            int temp;
            cin >> temp;
            for (int j = temp - k; j <= temp + k; j++)
            {
                if (j >= 1 && j <= n)
                    a[j] = 1;
            }
        }
        int sum = 0;
        for (int i = 1; i <= n;)
        {
            if (a[i] == 0)
            {
                sum++;
                i += 2 * k + 1;
            }
            else
            {
                i++;
            }
        }
        cout << sum << endl;
    }
    return 0;
}