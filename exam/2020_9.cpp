#include <bits/stdc++.h>
using namespace std;
string add(string s11, string s12, string s21, string s22)
{
    string ans1, ans2;
    int c = 0;
    for (int i = 0; i < s12.length(); i++)
    {
        int temp = s12[i] - '0' + s22[i] - '0' + c;
        ans2.push_back(temp % 3 + '0');
        c = temp / 3;
    }
    for (int i = 0; i < s11.length(); i++)
    {
        int temp = s11[i] - '0' + s21[i] - '0' + c;
        ans1.push_back(temp % 3 + '0');
        c = temp / 3;
    }
    if (c)
    {
        ans1.push_back(c + '0');
    }
    reverse(ans1.begin(), ans1.end());
    reverse(ans2.begin(), ans2.end());
    if (ans2 == "")
    {
        return ans1;
    }
    return ans1 + "." + ans2;
}
string sub(string s11, string s12, string s21, string s22)
{
    string ans1, ans2;
    for (int i = 0; i < s11.length(); i++)
    {
        if (s11[i] - s21[i] == -1)
        {
            ans1.push_back('2');
        }
        else
            ans1.push_back(s11[i] - s21[i] + '0');
    }
    for (int i = 0; i < s12.length(); i++)
    {
        if (s12[i] - s22[i] == -1)
        {
            ans2.push_back('2');
        }
        else
            ans2.push_back(s12[i] - s22[i] + '0');
    }
    if (ans2.length() == 0)
    {
        return ans1;
    }
    return ans1 + "." + ans2;
}
int main()
{
    ios::sync_with_stdio(false);
    int a, b, flag = 0;
    cin >> a >> b;
    if (a < 0)
    {
        a = -a;
        flag = 1;
    }
    int n1 = a / b, n2 = a % b;
    string s1, s2, temp1, temp2;
    while (n1 != 0)
    {
        // cout << n1 << " " << n1 % 3 << endl;
        s1.push_back(n1 % 3 + '0');
        n1 /= 3;
    }
    while (n2 != 0)
    {
        s2.push_back(n2 % 3 + '0');
        n2 /= 3;
    }
    for (char c : s1)
    {
        temp1.push_back('1');
    }
    for (char c : s2)
    {
        temp2.push_back('1');
    }
    string s3;
    s1 = add(s1, s2, temp1, temp2);
    // cout << s1 << endl;
    if (s1.find(".") != string::npos)
    {
        s2 = s1.substr(0, s1.find("."));
        s3 = s1.substr(s1.find(".") + 1, -1);
    }
    else
    {
        s2 = s1;
    }
    int size = temp1.length();
    for (int i = size; i < s2.length(); i++)
    {
        temp1.insert(temp1.begin(), '0');
    }
    string ans = sub(s2, s3, temp1, temp2);
    if (flag)
    {
        for (int i = 0; i < ans.length(); i++)
        {
            if (ans[i] == '2')
            {
                ans[i] = '1';
            }
            else if (ans[i] == '1')
            {
                ans[i] = '2';
            }
        }
    }
    cout << ans;
    return 0;
}