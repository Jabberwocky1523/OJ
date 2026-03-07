#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    long long door = 1, j = 0, sum = 0;
    vector<int> v(n), sum1(n), sum2(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    while (door - 1 != n)
    {
        /* code */
        if (v[j] == door)
        {
            sum1[door - 1] = sum;
            door++;
            sum = 0;
        }
        else
        {
            j = (j + 1) % n;
            sum++;
        }
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << sum1[i];
    // }
    door = 1;
    while (door - 1 != n)
    {
        /* code */
        if (v[j] == door)
        {
            sum2[door - 1] = sum;
            door++;
            sum = 0;
        }
        else
        {
            j = (j + 1) % n;
            sum++;
        }
    }
    long long s2 = accumulate(sum2.begin(), sum2.end(), 0);
    if (k <= n)
    {
        cout << accumulate(sum1.begin(), sum1.end() - (n - k), 0);
    }
    else
    {
        cout << accumulate(sum1.begin(), sum1.end(), 0) + ((k - n) / n) * s2 + accumulate(sum2.begin(), sum2.end() - (n - ((k - n) % n)), 0);
    }
    return 0;
}