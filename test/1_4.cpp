#include <bits/stdc++.h>
using namespace std;
int a(int i)
{
    string s = to_string(i);
    if (i == (pow(s[0] - '0', 3) + pow(s[1] - '0', 3) + pow(s[2] - '0', 3)))
    {
        return i;
    }
    return 0;
}
int main()
{
    int m, n;
    while (cin >> m >> n)
    {
        if (m == 0 && n == 0)
        {
            break;
        }
        int sum = 0;
        for (int i = m; i <= n; i++)
        {
            int temp = a(i);
            if (temp != 0)
            {
                sum++;
                cout << temp << " ";
            }
        }
        if (sum == 0)
        {
            cout << "no" << endl;
            continue;
        }
        cout << endl;
    }
    return 0;
}