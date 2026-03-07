#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        vector<int> v;
        unordered_map<int, int> um;
        for (int j = 0; j < m; j++)
        {
            int temp;
            cin >> temp;
            v.push_back(temp);
            um[v[j]]++;
        }
        int sum = 0;
        for (int aj : v)
        {
            for (int ak : v)
            {
                int ai = um[ak - aj];
                sum += ai;
            }
        }
        cout << sum << endl;
    }
    return 0;
}