#include <bits/stdc++.h>
using namespace std;
bool read(vector<vector<int>> &v, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> v[i][j];
        }
    }
    return true;
}
bool rotate(vector<vector<int>> &v, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            swap(v[i][j], v[j][i]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        int j = 0;
        while (j < n / 2)
        {
            /* code */
            swap(v[i][j], v[i][n - 1 - j]);
            j++;
        }
    }
    return true;
}
void printvertex(vector<vector<int>> &v, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << v[i][j];
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> a1, a2;
    a1.resize(n, vector<int>(n));
    a2.resize(n, vector<int>(n));
    read(a1, n);
    read(a2, n);
    int flag = 0;
    for (flag = 0; flag < 4; flag++)
    {
        if (a2 == a1)
        {
            break;
        }
        rotate(a1, n);
    }
    if (flag == 4)
    {
        cout << -1;
        return 0;
    }
    cout << flag * 90;
    return 0;
}