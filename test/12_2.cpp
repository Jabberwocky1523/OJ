#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    long long n;
    while (cin >> n)
    {
        /* code */
        long long sum = 0;
        while (n != 1)
        {
            /* code */
            int temp = n;
            for (long long ll = 2; ll <= temp; ll++)
            {
                while (n % ll == 0)
                {
                    /* code */
                    sum++;
                    n /= ll;
                }
                if (n <= 1)
                {
                    break;
                }
            }
        }
        cout << sum << endl;
    }
    return 0;
}