#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> v;
    unordered_map<int, int> um;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
        um[temp]++;
    }
    for (int i : v)
    {
        if (um[i] == 1)
        {
            cout << "BeiJu" << endl;
        }
        else
        {
            cout << um[i] - 1 << endl;
        }
    }
    return 0;
}