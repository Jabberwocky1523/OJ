#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    stack<char> sc;
    string s;
    getline(cin, s);
    for (char c : s)
    {
        if (c == '<' || c == '(' || c == '{' || c == '[')
        {
            sc.push(c);
        }
        else
        {
            if (sc.empty())
            {
                cout << "no";
                return 0;
            }
            if (c == '>')
            {
                if (sc.top() == '<')
                {
                    sc.pop();
                }
                else
                {
                    cout << "no";
                    return 0;
                }
            }
            else if (c == ')')
            {
                if (sc.top() == '(')
                {
                    sc.pop();
                }
                else
                {
                    cout << "no";
                    return 0;
                }
            }
            else if (c == '}')
            {
                if (sc.top() == '{')
                {
                    sc.pop();
                }
                else
                {
                    cout << "no";
                    return 0;
                }
            }
            else
            {
                if (sc.top() == '[')
                {
                    sc.pop();
                }
                else
                {
                    cout << "no";
                    return 0;
                }
            }
        }
    }
    if (sc.empty())
    {
        cout << "yes";
    }
    else
    {
        cout << "no";
    }
    return 0;
}