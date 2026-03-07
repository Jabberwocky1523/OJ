#include <bits/stdc++.h>
using namespace std;
bool cmp(int a, int b)
{
    return a > b;
}
int main()
{
    vector<int> v1, v2;
    for (int i = 0; i < 10; i++)
    {
        int temp;
        cin >> temp;
        if (temp % 2 == 0)
        {
            v2.push_back(temp);
        }
        else
        {
            v1.push_back(temp);
        }
    }
    sort(v1.begin(), v1.end(), [](int a, int b)
         { return a > b; });
    sort(v2.begin(), v2.end());
    for (int i : v1)
    {
        cout << i << " ";
    }
    for (int i : v2)
    {
        cout << i << " ";
    }
    return 0;
}