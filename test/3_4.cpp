#include <bits/stdc++.h>
using namespace std;
struct s
{
    int a, b;
};
int main()
{
    int n;
    cin >> n;
    vector<s> vs;
    for (int i = 0; i < n; i++)
    {
        s ss;
        cin >> ss.a >> ss.b;
        vs.push_back(ss);
    }
    sort(vs.begin(), vs.end(), [](s &s1, s &s2)
         { if( s1.a < s2.a)
            return true;
            else if(s1.a == s2.a){
                return s1.b < s2.b;
            } 
            return false; });
    cout << vs[0].a << " " << vs[0].b;
    return 0;
}