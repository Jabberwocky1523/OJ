#include <bits/stdc++.h>
using namespace std;
int aa(int n)
{
    if (n == 1)
    {
        return 1;
    }
    int sum = 0;
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            if (i == sqrt(n))
            {
                sum += 1;
            }
            else
            {
                sum += 2;
            }
        }
    }
    return sum;
}
int main()
{
    int n;
    vector<int> a;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        a.push_back(t);
    }
    for (int i : a)
    {
        cout << aa(i) << endl;
    }
    return 0;
}