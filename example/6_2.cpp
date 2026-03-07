#include <bits/stdc++.h>
using namespace std;
void cal(int last, int &sum, int pre, int n)
{
    if (pre > n)
    {
        return;
    }
    else if (pre == n)
    {
        sum += 1;
        return;
    }
    if (last == 0)
    {
        cal(0, sum, pre + 1, n);
        cal(1, sum, pre + 1, n);
    }
    else
    {
        cal(0, sum, pre + 1, n);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    int n, sum = 0;
    cin >> n;
    cal(0, sum, 1, n);
    cal(1, sum, 1, n);
    cout << sum;
    return 0;
}