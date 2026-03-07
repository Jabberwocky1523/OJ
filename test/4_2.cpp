#include <bits/stdc++.h>
using namespace std;
bool cmp(string s1, string s2)
{
    if (s1.length() < s2.length())
    {
        return true;
    }
    else if (s1.length() == s2.length())
    {
        if (s1 == s2)
        {
            return false;
        }   
        int i = 0;
        while (i < s1.length() && s1[i] == s2[i])
            /* code */
            i++;
        return s1[i] < s2[i];
    }
    else
    {
        return false;
    }
}
int main()
{
    vector<string> vs;
    int n;
    cin >> n;
    getchar();
    for (int i = 0; i < n; i++)
    {
        string t;
        getline(cin, t);
        vs.push_back(t);
    }
    sort(vs.begin(), vs.end(), cmp);
    for (string s : vs)
    {
        cout << s << endl;
    }
    return 0;
}