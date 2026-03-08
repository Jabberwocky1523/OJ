#include <bits/stdc++.h>
using namespace std;
struct cylinder
{
    long long R, H;
    cylinder(long long _R, long long _H)
    {
        R = _R;
        H = _H;
    }
    long long vo()
    {
        return H * pow(R, 2);
    }
};
void bfs(vector<cylinder> v, int &sum, int ii, int &max, int depth, int k)
{
    if (depth == k)
    {
        return;
    }
    for (int i = ii; i < v.size(); i++)
    {
        
    }
}
bool cmp(cylinder c1, cylinder c2)
{
    return c1.R < c2.R;
}
int main()
{
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    vector<cylinder> v;
    for (int i = 0; i < n; i++)
    {
        long long R, H;
        cin >> R >> H;
        v.push_back(cylinder(R, H));
    }
    sort(v.begin(), v.end(), cmp);
    return 0;
}