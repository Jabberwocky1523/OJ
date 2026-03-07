#include <bits/stdc++.h>
using namespace std;
struct num
{
    /* data */
    string a, b;
};
int main()
{
    num n1, n2;
    string temp1, temp2;
    while (getline(cin, temp1), getline(cin, temp2))
    {
        /* code */
        n1.a = temp1.substr(0, temp1.find('.'));
        n1.b = temp1.substr(temp1.find('.') + 1, -1);
        n2.a = temp2.substr(0, temp2.find('.'));
        n2.b = temp2.substr(temp2.find('.') + 1, -1);
        string s1, s2;
        int c = 0, size = n1.b.length() < n2.b.length() ? n1.b.length() : n2.b.length();
        for (int i = size - 1; i >= 0; i--)
        {
            int b1 = n1.b[i] - '0', b2 = n2.b[i] - '0';
            int b3 = b1 + b2 + c;
            c = b3 / 10;
            int t = b3 % 10;
            s2 = (char)(t + '0') + s2;
        }
        if (n1.b.length() > n2.b.length())
        {
            s2 = s2 + n1.b.substr(size, -1);
        }
        else
        {
            s2 = s2 + n2.b.substr(size, -1);
        }
        reverse(n1.a.begin(), n1.a.end()), reverse(n2.a.begin(), n2.a.end());
        size = n1.a.length() < n2.a.length() ? n1.a.length() : n2.a.length();
        for (int i = 0; i < size; i++)
        {
            int a1 = n1.a[i] - '0', a2 = n2.a[i] - '0';
            int a3 = a1 + a2 + c;
            c = a3 / 10;
            int t = a3 % 10;
            s1 = (char)(t + '0') + s1;
        }
        if (n1.a.length() > n2.a.length())
        {
            while (size < n1.a.length())
            {
                /* code */
                int a = n1.a[size] - '0' + c;
                c = a / 10;
                s1 = (char)((a % 10) + '0') + s1;
                size++;
            }
        }
        else
        {
            while (size < n2.a.length())
            {
                /* code */
                int a = n2.a[size] - '0' + c;
                c = a / 10;
                s1 = (char)((a % 10) + '0') + s1;
                size++;
            }
        }
        if (c == 1)
        {
            s1 = '1' + s1;
        }
        cout << s1 << "." << s2;
    }

    return 0;
}