#include <bits/stdc++.h>
using namespace std;
void dfs(int &num, int sum, int idx, vector<int> v)
{
    if (sum == 40)
    {
        num++;
        return;
    }
    for (int i = idx; i < v.size(); i++)
    {
        if (sum + v[i] <= 40)
        {
            dfs(num, sum + v[i], i + 1, v);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int num = 0, sum = 0;
    dfs(num, sum, 0, a);
    cout << num;
    return 0;
}