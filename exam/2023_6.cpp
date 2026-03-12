#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int d[1001];
    memset(d, 0, sizeof(int) * 1001);
    for (int i = 2; i <= 1000; i++)
    {
        if (d[i] == 0)
        {
            for (int j = i * 2; j <= 1000; j += i)
            {
                d[j] = 1;
            }
        }
    }
    int n, sum = 0;
    cin >> n;
    queue<int> q;
    q.push(n);
    while (q.size())
    {
        int &diff = q.front();
        q.pop();
        if (diff == 0 || diff == 2 || diff == 4)
        {
            sum++;
            continue;
        }
        for (int i = diff; i > 2; i--)
        {
            if (d[i] == 0)
            {
                q.push(diff - i);
            }
        }
    }
    cout << sum;
    return 0;
}