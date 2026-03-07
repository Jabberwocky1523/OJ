#include <bits/stdc++.h>
using namespace std;
long long reg[4];
void In(int num1, int num2)
{
    reg[num1] = num2;
}
void Mov(int num1, int num2)
{
    reg[num1] = reg[num2];
}
void Add(int num1, int num2)
{
    reg[num1] += reg[num2];
}
void Sub(int num1, int num2)
{
    reg[num1] -= reg[num2];
}
void Mul(int num1, int num2)
{
    reg[num1] *= reg[num2];
}
void Div(int num1, int num2)
{
    reg[num1] /= reg[num2];
}
void Out(int num)
{
    cout << reg[num] << endl;
}
void execute(string s)
{
    string op = s.substr(0, s.find(" "));
    s = s.substr(s.find(" ") + 1, -1);
    if (op == "OUT")
    {
        Out(s[0] - 'A');
        return;
    }
    string r1 = s.substr(0, s.find(",")), r2 = s.substr(s.find(",") + 1, -1);
    int num1 = r1[0] - 'A', num2 = r2[0] - 'A';
    // cout << op << " " + r1 << " " + r2 << endl;
    if (op == "IN")
    {
        In(num1, atoi(r2.c_str()));
    }
    else if (op == "MOV")
    {
        Mov(num1, num2);
    }
    else if (op == "ADD")
    {
        Add(num1, num2);
    }
    else if (op == "SUB")
    {
        Sub(num1, num2);
    }
    else if (op == "MUL")
    {
        Mul(num1, num2);
    }
    else
    {
        Div(num1, num2);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    string s;
    while (getline(cin, s))
    {
        execute(s);
    }
    return 0;
}