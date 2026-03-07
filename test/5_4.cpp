#include <bits/stdc++.h>
using namespace std;
int cmp(char a, char b)
{
    if (((a == '+' || a == '-') && (b == '+' || b == '-')) || ((a == '*' || a == '/')) && ((b == '*' || b == '/')))
    {
        return 0;
    }
    else if ((a == '+' || a == '-') && (b == '*' || b == '/'))
    {
        /* code */
        return -1;
    }
    else
    {
        return 1;
    }
}
double cal(double a, double b, char de)
{
    switch (de)
    {
    case '+':
        /* code */
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    default:
        return 2;
        break;
    }
}
void p(stack<int> s)
{
    int size = s.size();
    for (int i = 0; i < size; i++)
    {
        cout << s.top() << " ";
        s.pop();
    }
}
void p(stack<char> s)
{
    int size = s.size();
    for (int i = 0; i < size; i++)
    {
        cout << s.top() << " ";
        s.pop();
    }
}
void erase(string &s)
{
    while (s.find(" ") != string::npos)
    {
        /* code */
        s.erase(s.find(" "), 1);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    string s;
    while (getline(cin, s))
    {
        if (s == "0")
        {
            break;
        }
        /* code */
        erase(s);
        stack<double> a;
        stack<char> b;
        string temp;
        for (char c : s)
        {
            if (!isalnum(c))
            {
                a.push(stod(temp));
                temp.clear();
                if (b.empty())
                {
                    b.push(c);
                    continue;
                }
                char de = b.top();
                int ans = cmp(c, de);
                if (ans == 1)
                {
                    b.push(c);
                }
                else
                {
                    while (ans <= 0)
                    {
                        /* code */
                        double a1 = a.top();
                        a.pop();
                        double a2 = a.top();
                        a.pop();
                        char de = b.top();
                        b.pop();
                        double a3 = cal(a2, a1, de);
                        a.push(a3);
                        if (b.empty())
                        {
                            break;
                        }
                        ans = cmp(c, b.top());
                    }
                    b.push(c);
                }
            }
            else
            {
                temp.push_back(c);
            }
        }
        a.push(atoi(temp.c_str()));
        while (!b.empty())
        {
            /* code */
            double a1 = a.top();
            a.pop();
            double a2 = a.top();
            a.pop();
            char de = b.top();
            b.pop();
            double a3 = cal(a2, a1, de);
            a.push(a3);
        }
        printf("%.2f\n", a.top());
    }
    return 0;
}
