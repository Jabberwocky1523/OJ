#include <bits/stdc++.h>
using namespace std;
struct stu
{
    int p;
    int q;
};
bool cmp(stu s1, stu s2)
{
    if (s1.q < s2.q)
    {
        return true;
    }
    else if (s1.q == s2.q)
    {
        return s1.p < s2.p;
    }
    else
    {
        return false;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<stu> s;
    for (int i = 0; i < n; i++)
    {
        stu temp;
        cin >> temp.p >> temp.q;
        s.push_back(temp);
    }
    sort(s.begin(), s.end(), cmp);
    for (stu st : s)
    {
        cout << st.p << " " << st.q << endl;
    }
    return 0;
}