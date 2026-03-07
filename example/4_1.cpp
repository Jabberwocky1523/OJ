#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<string> vs;
    string s;
    unordered_map<char, int> um;
    vector<char> vc;
    int sum = 0;
    int max = INT_MIN;
    while (cin >> s)
    {
        /* code */
        vs.push_back(s);
        sum += s.length();
    }
    for (string s1 : vs)
    {
        for (char c : s1)
        {
            if (c >= 'A' && c <= 'Z')
            {
                c = c - 'A' + 'a';
            }
            if (um[c] == 0)
            {
                vc.push_back(c);
            }
            um[c]++;
            if (um[c] > max)
            {
                max = um[c];
            }
        }
    }
    cout << sum << endl
         << vs.size() << endl;
    sort(vc.begin(), vc.end());
    for (char c : vc)
    {
        if (um[c] == max)
        {
            cout << c << " ";
        }
    }
    cout << endl
         << max;
    return 0;
}