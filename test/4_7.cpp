#include <bits/stdc++.h>
using namespace std;
int main()
{
    string res;
    while (getline(cin, res))
    {
        /* code */
        int flag = 1;
        for (char c : res)
        {
            if (flag == 1)
            {
                if (c >= 'a' && c <= 'z')
                {
                    cout << (char)(c - 'a' + 'A');
                    flag = 0;
                }
                else if (c >= 'A' && c <= 'Z')
                {
                    cout << c;
                    flag = 0;
                }
                else if (isalnum(c))
                {
                    flag = 0;
                    cout << c;
                }
                else
                {
                    cout << c;
                }
            }
            else
            {
                if (c == ' ' || c == '\t' || c == '\r' || c == '\n')
                {
                    cout << c;
                    flag = 1;
                }
                else
                {
                    cout << c;
                }
            }
        }
        cout << endl;
    }
    return 0;
}