#include <bits/stdc++.h>
using namespace std;
vector<string> getByLevel(vector<string> &m, int level)
{
    if (level == 1)
    {
        return m;
    }
    vector<string> ans;
    vector<string> temp = getByLevel(m, level - 1);
    int size = m.size() * temp.size();
    for (int i = 0; i < size; i++)
    {
        ans.push_back(string(size, ' '));
    }
    for (int i = 0; i < m.size(); i++)
    {
        for (int j = 0; j < m.size(); j++)
        {
            if (m[i][j] != ' ')
            {
                for (int x = 0; x < temp.size(); x++)
                {
                    for (int y = 0; y < temp.size(); y++)
                    {
                        ans[i * temp.size() + x][j * temp.size() + y] = temp[x][y];
                    }
                }
            }
        }
    }
    return ans;
}
int main()
{
    int N;
    while (cin >> N)
    {
        /* code */
        if (N == 0)
        {
            break;
        }
        getchar();
        vector<string> m;
        for (int i = 0; i < N; i++)
        {
            string s;
            getline(cin, s);
            m.push_back(s);
        }
        int level;
        cin >> level;
        vector<string> ans = getByLevel(m, level);
        for (string s : ans)
        {
            cout << s << endl;
        }
    }

    return 0;
}