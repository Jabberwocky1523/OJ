#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> a, b, ans;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        a.push_back(temp);
    }
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        b.push_back(temp);
    }
    auto ita = a.begin(), itb = b.begin();
    while (ita != a.end() && itb != b.end())
    {
        if (*ita > *itb)
        {
            ans.push_back(*itb);
            itb++;
        }
        else
        {
            ans.push_back(*ita);
            ita++;
        }
    }
    if (ita != a.end())
    {
        while (ita != a.end())
        {
            /* code */
            ans.push_back(*ita);
            ita++;
        }
    }
    if (itb != a.end())
    {
        while (itb != b.end())
        {
            /* code */
            ans.push_back(*itb);
            itb++;
        }
    }
    for (int i : ans)
    {
        cout << i << " ";
    }
    return 0;
}