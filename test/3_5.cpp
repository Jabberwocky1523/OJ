#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v, ans;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    if (v[0] != v[1])
    {
        ans.push_back(0);
    }
    for (int i = 1; i < n - 1; i++)
    {
        if ((v[i] > v[i - 1] && v[i] > v[i + 1]) || (v[i] < v[i - 1] && v[i] < v[i + 1]))
        {
            ans.push_back(i);
        }
    }
    if (v[n - 2] != v[n - 1])
    {
        ans.push_back(n - 1);
    }
    for (int i : ans)
    {
        cout << i << " ";
    }
    return 0;
}