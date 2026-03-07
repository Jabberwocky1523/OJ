#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int n;
    cin >> n;
    getchar();
    for (int i = 0; i < n; i++)
    {
        getline(cin, s);
        string ans;
        int sum = 0;
        for (char c : s)
        {

            if (sum == 5)
            {
                sum = 0;
                continue;
            }
            if (c == '0')
            {
                sum = 0;
            }
            else
            {
                sum++;
            }
            ans.push_back(c);
        }
        cout << ans << endl;
    }
    return 0;
}