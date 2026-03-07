#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n1, n2;
    string str;
    while (cin >> str)
    {
        /* code */
        int N = str.length();
        if ((N + 2) % 3 == 0)
        {
            n1 = n2 = (N + 2) / 3;
        }
        else
        {
            n2 = (N + 2) / 3;
            for (int i = n2;; i++, n2++)
            {
                if (((N + 2 - i) % 2) == 0)
                {
                    n1 = ((N + 2 - i) / 2);
                    if (n1 > n2)
                    {
                        continue;
                    }
                    break;
                }
            }
        }
        for (int i = 0; i < n1 - 1; i++)
        {
            cout << str[i];
            for (int j = 0; j < n2 - 2; j++)
            {
                cout << " ";
            }
            cout << str[str.length() - 1 - i] << endl;
        }
        cout << str.substr(n1 - 1, n2) << endl;
    }

    return 0;
}