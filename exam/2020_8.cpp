#include <bits/stdc++.h>
using namespace std;
void bfs(string vc, int &flag, string cur, int num, int &ans, vector<int> visit)
{
    if (num == vc.length())
    {
        if (flag == 1)
        {
            return;
        }
        int temp = atoi(cur.c_str());
        if (temp % 30 == 0)
        {
            ans = temp;
            flag = 1;
        }
        return;
    }
    for (int i = 0; i < vc.size(); i++)
    {
        if (visit[i] == 0)
        {
            visit[i] = 1;
            cur.push_back(vc[i]);
            bfs(vc, flag, cur, num + 1, ans, visit);
            visit[i] = 0;
            cur.erase(cur.end() - 1);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    string s, cur;
    cin >> s;
    sort(s.begin(), s.end(), [](char c1, char c2)
         { return c1 > c2; });
    int flag = 0, num = 0, ans = -1;
    vector<int> visit(s.length());
    bfs(s, flag, cur, num, ans, visit);
    cout << ans;
    return 0;
}