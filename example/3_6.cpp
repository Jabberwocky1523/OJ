#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    getline(cin, s);
    unordered_map<char, vector<int>> um;
    vector<char> sc;
    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];
        if (um[c].size() == 0)
            sc.push_back(c);
        um[c].push_back(i);
    }
    for (char c : sc)
    {
        if (um[c].size() > 1)
        {
            int i;
            for (i = 0; i < um[c].size() - 1; i++)
            {
                cout << c << ":" << um[c][i] << ",";
            }
            cout << c << ":" << um[c][i] << endl;
        }
    }
    return 0;
}