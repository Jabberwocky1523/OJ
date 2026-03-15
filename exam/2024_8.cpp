#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int x, y;
        cin >> x >> y;
        if (x < y)
        {
            cout << "Yes" << endl;
            break;
        }
        int j = x - 1;
        for (; j >= y; j--)
        {
            if (v[j] > v[x])
            {
                break;
            }
        }
        if (j < y)
        {
            cout << "No" << endl;
        }
        else
        {
            cout << "Yes" << endl;
        }
    }
    return 0;
}