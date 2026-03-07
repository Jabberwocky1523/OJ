#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> matrixmul(vector<vector<int>> v1, vector<vector<int>> v2)
{
    vector<vector<int>> ans;
    ans.resize(v1.size(), vector<int>(v1.size()));
    for (int i = 0; i < v1.size(); i++)
    {
        for (int j = 0; j < v1.size(); j++)
        {
            int temp = 0;
            for (int z = 0; z < v1.size(); z++)
            {
                temp += v1[i][z] * v2[z][j];
            }
            ans[i][j] = temp;
        }
    }
    return ans;
}
vector<vector<int>> matrix(vector<vector<int>> v, int k)
{
    if (k == 0)
    {
        vector<vector<int>> temp;
        temp.resize(v.size(), vector<int>(v.size()));
        for (int i = 0; i < v.size(); i++)
        {
            for (int j = 0; j < v.size(); j++)
            {
                if (j == i)
                {
                    temp[i][j] = 1;
                }
                else
                    temp[i][j] = 0;
            }
        }
        return temp;
    }
    else if (k == 1)
    {
        return v;
    }
    else
    {
        vector<vector<int>> temp = matrix(v, k / 2), ans;
        if (k % 2 == 0)
        {
            ans = matrixmul(temp, temp);
        }
        else
        {
            ans = matrixmul(matrixmul(temp, temp), v);
        }
        return ans;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    int n, k;
    while (cin >> n >> k)
    { /* code */
        vector<vector<int>> v;
        v.resize(n, vector<int>(n));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> v[i][j];
            }
        }
        v = matrix(v, k);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << v[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}