#include <bits/stdc++.h>
using namespace std;
vector<int> a(int N)
{
    vector<int> res;
    res.push_back(1);
    for (int i = 2; i <= sqrt(N); i++)
    {
        if (N % i == 0 && i != sqrt(N))
        {
            res.push_back(i);
            res.push_back(N / i);
        }
        if (i == sqrt(N))
        {
            res.push_back(i);
        }
    }
    return res;
}
int main()
{
    vector<int> b, c;
    for (int i = 2; i <= 60; i++)
    {
        vector<int> temp = a(i);
        int sum = accumulate(temp.begin(), temp.end(), 0);
        if (sum == i)
        {
            b.push_back(i);
        }
        else if (sum > i)
        {
            c.push_back(i);
        }
    }
    // vector<int> temp = a(4);
    // int sum = reduce(temp.begin(), temp.end());
    // cout << sum;
    cout << "E: ";
    for (int i = 0; i < b.size() - 1; i++)
    {
        cout << b[i] << " ";
    }
    cout << b[b.size() - 1] << endl;
    cout << "G: ";
    for (int i = 0; i < c.size() - 1; i++)
    {
        cout << c[i] << " ";
    }
    cout << c[c.size() - 1] << endl;
    return 0;
}