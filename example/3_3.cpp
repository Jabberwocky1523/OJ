#include <bits/stdc++.h>
using namespace std;
struct stu
{
    string p;
    int q, id;
};
bool rule = 0;
bool cmp(stu s1, stu s2)
{
    if (s1.q < s2.q)
    {
        return rule;
    }
    else if (s1.q == s2.q)
    {
        return s1.id < s2.id;
    }
    else
    {
        return !rule;
    }
}

int main()
{
    int n;
    cin >> n;
    cin >> rule;
    vector<stu> s;
    for (int i = 0; i < n; i++)
    {
        stu temp;
        cin >> temp.p >> temp.q;
        temp.id = i;
        s.push_back(temp);
    }
    sort(s.begin(), s.end(), cmp);
    for (stu st : s)
    {
        cout << st.p << " " << st.q << endl;
    }
    return 0;
}