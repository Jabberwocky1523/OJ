#include <bits/stdc++.h>
using namespace std;
class a
{
public:
    /* data */
    int b;
    int c;
    a(int b, int c)
    {
        this->b = b;
        this->c = c;
    }
    a()
    {
        this->b = 1;
        this->c = 1;
    }
};

int main()
{
    unordered_map<char, a> m;
    vector<string> vs = {"abc", "def", "ghi",
                         "jkl", "mno", "pqrs",
                         "tuv", "wxyz"};
    int temp = 2;
    for (string s : vs)
    {
        int num = 1;
        for (char c : s)
        {
            a tempa(temp, num);
            m.insert(pair<char, a>(c, tempa));
            num++;
        }
        temp++;
    }
    a tempa(1, 1);
    m.insert(pair<char, a>('0', tempa));
    string s;
    while (getline(cin, s))
    {
        char last = '0';
        int sum = 0;
        /* code */
        for (char c : s)
        {
            if (m[c].b == m[last].b)
                sum += 2;
            sum += m[c].c;
            last = c;
        }
        cout << sum << endl;
    }
    return 0;
}