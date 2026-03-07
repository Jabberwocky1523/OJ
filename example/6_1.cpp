#include <bits/stdc++.h>
using namespace std;
void cal(int pre, int &sum, int n)
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
    cal(pre + 1, sum, n);
    cal(pre + 2, sum, n);
}
int main()
{
    ios::sync_with_stdio(false);
    int n, sum = 0;
    cin >> n;
    cal(0, sum, n);
    cout << sum;
    return 0;
}