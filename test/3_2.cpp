#include <bits/stdc++.h>
using namespace std;
struct mouse
{
    int h;
    string c;
};
int main()
{
    vector<mouse> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        mouse m;
        cin >> m.h >> m.c;
        v.push_back(m);
    }
    sort(v.begin(), v.end(), [](mouse &m1, mouse &m2)
         { return m1.h > m2.h; });
    for (mouse m : v)
    {
        cout << m.c << endl;
    }
    return 0;
}