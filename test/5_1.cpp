#include <bits/stdc++.h>
using namespace std;
#define i64 long long
struct stu
{
    i64 a, t, b;
};
int main()
{
    ios::sync_with_stdio(false);
    i64 n;
    cin >> n;
    queue<stu> vs;
    for (i64 i = 0; i < n; i++)
    {
        stu s;
        cin >> s.a >> s.t >> s.b;
        vs.push(s);
    }
    i64 sum = vs.front().a, size = vs.size();
    for (i64 i = 0; i < size; i++)
    {
        stu s = vs.front();
        vs.pop();
        if (sum > s.b + s.a)
        {
            cout << -1 << " ";
            continue;
        }
        if (s.a > sum)
        {
            sum = s.a;
        }
        cout << sum << " ";
        sum += s.t;
    }
    return 0;
}