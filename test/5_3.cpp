#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    string res = "abcdefghijklmnopqrstuvwxyz";
    string n;
    while (getline(cin, n))
    {
        /* code */
        stack<char> sc;
        int last = 0;
        int i = 0;
        for (; i < n.length();)
        {
            char c = n[i];
            if (sc.empty() || c > sc.top())
            {
                for (int j = last; j <= c - 'a'; j++)
                {
                    sc.push(res[j]);
                }
                last = c - 'a' + 1;
            }
            else if (c == sc.top())
            {
                sc.pop();
                i++;
            }
            else
            {
                break;
            }
        }
        if (i == n.length())
        {
            cout << "yes" << endl;
        }
        else
        {
            cout << "no" << endl;
        }
    }
    return 0;
}