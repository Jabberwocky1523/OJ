#include <bits/stdc++.h>
using namespace std;
int main()
{
    string res, a, b, temp;
    getline(cin, res);
    getline(cin, a);
    getline(cin, b);
    istringstream iss(res);
    vector<string> vs;
    while (getline(iss, temp, ' '))
    {
        /* code */
        vs.push_back(temp);
    }
    for (string s : vs)
    {
        if (s == a)
        {
            cout << b << " ";
        }
        else
        {
            cout << s << " ";
        }
    }

    return 0;
}