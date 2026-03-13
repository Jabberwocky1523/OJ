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
struct node
{
    int color, score, visit = 0;
    node() {}
    node(int _color, int _score)
    {
        color = _color, score = _score;
    }
    bool operator==(node n)
    {
        return this->color == n.color;
    }
    bool operator<(node n)
    {
        return this->color == n.color && this->score < n.score;
    }
};
bool cmp(card c1, card c2)
{
    if (c1.id != c2.id)
    {
        return c1.id < c2.id;
    }
    else
    {
        return c1.score > c2.score;
    }
}
int f(vector<node> v, int color)
{
    int index = -1, max_num = -1;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].color == color)
        {
            if (v[i].score > max_num && v[i].visit == 0)
            {
                index = i;
            }
        }
    }
    return index;
}
int main()
{
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n;
    vector<card> judge(n, card(0, 0, 0));
    unordered_map<int, vector<node>> um;
    for (int i = 0; i < n; i++)
    {
        cin >> judge[i].id >> judge[i].color >> judge[i].score;
        um[judge[i].id].push_back(node(judge[i].color, judge[i].score));
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
            int id, p, s;
            vector<int> temp;
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
        sort(vc.begin(), vc.end(), cmp);
        box[i] = vc;
    }
    vector<int> max_box(m, 0);
    for (int i = 0; i < m; i++)
    {
        unordered_map<int, vector<node>> um1 = um;
        for (int j = 0; j < box[i].size(); j++)
        {
            int id = box[i][j].id, p = box[i][j].score, max_score = INT_MIN;
            vector<int> colors = box[i][j].colors;
            int ii = -1, indexi = -1;
            for (int i = 0; i < colors.size(); i++)
            {
                int index = f(um1[id], colors[i]);
                if (index != -1)
                {
                    if (max_score < p * um1[id][index].score)
                    {
                        ii = id;
                        indexi = index;
                        max_score = p * um1[id][index].score;
                    }
                }
            }
            if (ii != -1 && indexi != -1)
            {
                um1[ii][indexi].visit = 1;
                max_box[i] += max_score;
            }
        }
    }
    // for (int i : max_box)
    // {
    //     cout << i << " ";
    // }
    auto it = max_element(max_box.begin(), max_box.end());
    cout << it - max_box.begin() + 1 << endl
         << *max_element(max_box.begin(), max_box.end());
    return 0;
}