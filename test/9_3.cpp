#include <bits/stdc++.h>
using namespace std;
void dfs(int &num, vector<long long> &v, int idx, int n, int sum)
{
    // if (sum == n)
    // {
    //     num++;
    //     return;
    // }
    for (int i = idx; i <= v.size() - 1; i++)
    {
        if (sum + v[i] == n)
        {
            num++;
            break;
        }
        else if (sum + v[i] > n || v[i] > n / 2)
        {
            break;
        }
        dfs(num, v, i + 1, n, sum + v[i]);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    long long n;
    cin >> n;
    vector<long long> v;
    v.push_back(1), v.push_back(2);
    for (int i = 0;; i++)
    {
        long long temp = v[i] + v[i + 1];
        if (temp > n)
        {
            break;
        }
        v.push_back(temp);
    }
    int num = 0, sum = 0;
    dfs(num, v, 0, n, sum);
    cout << num;
    return 0;
}