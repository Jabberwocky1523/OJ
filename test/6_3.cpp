#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> cal(vector<vector<int>> v, int k, int n)
{
    if (k == 1)
    {
        return v;
    }
    vector<vector<int>> res, ans;
    res.resize(v.size(), vector<int>(v.size()));
    ans.resize(v.size(), vector<int>(v.size()));
    res = cal(v, k - 1, n);
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v.size(); j++)
        {
            int temp = 0;
            for (int k = 0; k < v.size(); k++)
            {
                temp += res[i][k] * v[k][j];
            }
            ans[i][j] = temp;
        }
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    vector<vector<int>> v;
    v.resize(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> v[i][j];
        }
    }
    v = cal(v, k, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            cout << v[i][j] << " ";
        }
        cout << v[i][n - 1] << endl;
    }
    return 0;
}