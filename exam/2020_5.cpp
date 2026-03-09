#include <bits/stdc++.h>
using namespace std;
string add(string s1, string s2)
{
    if (s1.length() > s2.length())
    {
        swap(s1, s2);
    }
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    long long c = 0;
    string ans;
    for (int i = 0; i < s1.length(); i++)
    {
        int temp = s1[i] - '0' + s2[i] - '0' + c;
        ans.push_back(temp % 10 + '0');
        c = temp / 10;
    }
    for (int i = s1.length(); i < s2.length(); i++)
    {
        int temp = s2[i] - '0' + c;
        ans.push_back(temp % 10 + '0');
        c = temp / 10;
    }
    if (c != 0)
        ans.push_back(c + '0');
    reverse(ans.begin(), ans.end());
    return ans;
};
bool a(string s)
{
    string temp = s;
    reverse(temp.begin(), temp.end());
    return s == temp;
}
int main()
{
    ios::sync_with_stdio(false);
    long long n;
    cin >> n;
    string s1 = to_string(n), s2 = to_string(n);
    reverse(s2.begin(), s2.end());
    string ans = add(s1, s2);
    int sum = 1;
    while (!a(ans))
    {
        /* code */
        string temp = ans;
        reverse(temp.begin(), temp.end());
        ans = add(ans, temp);
        sum++;
    }
    cout << sum << " " << ans;
    return 0;
}