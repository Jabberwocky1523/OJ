#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        m[temp]++;
    }
    auto it1 = m.rbegin();
    cout << it1->first << endl;
    if (m.size() == 1)
    {
        cout << -1;
        return 0;
    }
    for (auto it = m.begin(); it != --m.end(); it++)
    {
        for (int i = 0; i < it->second; i++)
        {
            cout << it->first << " ";
        }
    }
    for (int i = 0; i < (--m.end())->second - 1; i++)
    {
        cout << (--m.end())->first << " ";
    }
    return 0;
}