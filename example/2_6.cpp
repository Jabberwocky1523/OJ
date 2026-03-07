#include <bits/stdc++.h>
using namespace std;
bool a(vector<int> v)
{
    int ans = 0;
    while (1)
    {
        /* code */
        if (max_element(v.begin(), v.end()) == min_element(v.begin(), v.end()))
        {
            cout << ans << " " << *max_element(v.begin(), v.end()) << endl;
            return true;
        }
        for_each(v.begin(), v.end(), [](int &x)
                 { x /= 2; });
        int temp = v[v.size() - 1];
        for (int i = v.size() - 1; i > 0; i--)
        {
            v[i] += v[i - 1];
        }
        v[0] += temp;
        for_each(v.begin(), v.end(), [](int &x)
                 {if(x % 2 != 0){x +=1;} });
        ans++;
    }
}
int main()
{
    int N;
    cin >> N;
    while (N != 0)
    {
        /* code */
        vector<int> res;
        for (int i = 0; i < N; i++)
        {
            int temp;
            cin >> temp;
            res.push_back(temp);
        }
        a(res);
        cin >> N;
    }
    return 0;
}