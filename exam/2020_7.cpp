#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    string s;
    int q;
    cin >> s >> q;
    int prefix[26][s.length() + 1], f = 1;
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < s.length() + 1; j++)
        {
            prefix[i][j] = 0;
        }
    }
    for (int i = 0; i < s.length(); i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (s[i] - 'a' == j)
            {
                prefix[j][i + 1] = prefix[j][i] + 1;
            }
            else
            {
                prefix[j][i + 1] = prefix[j][i];
            }
        }
    }
    for (int i = 0; i < q; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (b - a != d - c)
        {
            printf("NE\n");
            continue;
        }
        int flag = 1;
        for (int i = 0; i < 26; i++)
        {
            int t1 = prefix[i][b] - prefix[i][a - 1],
                t2 = prefix[i][d] - prefix[i][c - 1];
            if (t1 != t2)
            {
                printf("NE\n");
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            printf("DA\n");
        }
    }
    return 0;
}