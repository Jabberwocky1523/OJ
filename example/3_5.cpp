#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> a;
    int n, m;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        a.push_back(temp);
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int temp;
        cin >> temp;
        auto it = find(a.begin(), a.end(), temp);
        if (it == a.end())
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }

    return 0;
}