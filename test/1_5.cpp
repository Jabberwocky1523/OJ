#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, sum = 0;
    cin >> a >> b;
    string sa = to_string(a), sb = to_string(b);
    for (int i = 0; i < sa.length(); i++)
    {
        for (int j = 0; j < sb.length(); j++)
        {
            sum += (sa[i] - '0') * (sb[j] - '0');
        }
    }
    cout << sum;
    return 0;
}