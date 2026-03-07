#include <bits/stdc++.h>
using namespace std;
#define i64 long long
int main()
{
    i64 n;
    cin >> n;
    vector<i64> v;
    int temp = 1;
    int sum = temp;
    v.push_back(1);
    while (sum < 1e6)
    {
        /* code */
        v.push_back(sum);
        temp++;
        sum *= temp;
    }
    vector<i64> s;
    s.push_back(0);
    for (i64 i : v)
    {
        temp = s.size();
        for (int j = 0; j < temp; j++)
        {
            s.push_back(s[j] + i);
        }
    }
    s.erase(s.begin());
    while (1)
    {
        /* code */
        if (n < 0)
        {
            break;
        }
        auto it = find(s.begin(), s.end(), n);
        if (it == s.end())
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
        cin >> n;
    }

    return 0;
}