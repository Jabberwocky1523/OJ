#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<string> vs = {"1234567890-=",
                         "QWERTYUIOP[]", "ASDFGHJKL;'", "ZXCVBNM,./"};
    unordered_map<char, char> um;
    for (string s : vs)
    {
        for (int i = 1; i < s.length(); i++)
        {
            um.insert({s[i], s[i - 1]});
        }
    }
    string s;
    while (getline(cin, s))
    {
        /* code */
        for (char &c : s)
        {
            if (c != ' ')
            {
                c = um[c];
            }
        }
        cout << s << endl;
    }

    return 0;
}