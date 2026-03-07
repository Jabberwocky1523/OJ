#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    while (getline(cin, s))
    {
        map<string, int> um;
        for (int i = 0; i < s.length(); i++)
        {
            for (int j = i; j < s.length(); j++)
            {
                um[s.substr(i, j - i + 1)]++;
            }
        }
        for (auto it = um.begin(); it != um.end(); it++)
        {
            if (it->second > 1)
                cout << it->first << " " << it->second << endl;
        }
    }
    return 0;
}