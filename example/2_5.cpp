#include <bits/stdc++.h>
using namespace std;
int main()
{
    int L, M;
    cin >> L >> M;
    vector<int> res(L + 1);
    res.assign(L + 1, 1);
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        for (int i = a; i <= b; i++)
        {
            res[i] = 0;
        }
    }
    cout << accumulate(res.begin(), res.end(), 0);
    return 0;
}