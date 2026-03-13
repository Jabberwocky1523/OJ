#include <bits/stdc++.h>
using namespace std;
struct card
{
    int id, score, color;
    vector<int> colors;
    card() {}
    card(int _id, int _color, int _score)
    {
        id = _id, color = _color, score = _score;
    }
    card(int _id, vector<int> _colors, int _score)
    {
        id = _id, colors = _colors, score = _score;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n;
    vector<card> judge(n, card(0, 0, 0));
    unordered_map<int, int> um;
    for (int i = 0; i < n; i++)
    {
        cin >> judge[i].id >> judge[i].color >> judge[i].score;
    }
    cin >> m;
    vector<card> box[m];
    for (int i = 0; i < m; i++)
    {
        int t;
        cin >> t;
        vector<card> vc;
        for (int j = 0; j < t; j++)
        {
            vector<int> temp;
            int id, p, s;
            cin >> id >> s;
            for (int k = 0; k < s; k++)
            {
                int tt;
                cin >> tt;
                temp.push_back(tt);
            }
            cin >> p;
            vc.push_back(card(id, temp, p));
        }
        box[i] = vc;
    }
    return 0;
}