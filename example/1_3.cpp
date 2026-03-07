#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while (cin >> n)
    {
        /* code */
        int sum = 0;
        while (n != 1)
        {
            /* code */
            if (n % 2 == 0)
            {
                n = n / 2;
            }
            else
            {
                n = (3 * n + 1) / 2;
            }
            sum++;
        }
        cout << sum << endl;
    }

    return 0;
}