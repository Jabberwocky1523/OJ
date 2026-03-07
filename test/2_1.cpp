#include <bits/stdc++.h>
using namespace std;
bool isLeap(int year)
{
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}
int a(int year1, int month1, int day1, int year2, int month2, int day2)
{
    int dayofMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int ans = 0;
    for (; year1 != year2 || month1 != month2;)
    {
        if (isLeap(year1))
        {
            dayofMonth[1] = 29;
        }
        else
        {
            dayofMonth[1] = 28;
        }
        ans += dayofMonth[month1] - day1;
        day1 = 0;
        month1++;
        if (month1 == 12)
        {
            year1++;
            month1 = 0;
        }
    }
    ans += day2 - day1 + 1;
    return ans;
}

int main()
{
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    int year1 = atoi(s1.substr(0, 4).c_str()), month1 = atoi(s1.substr(4, 2).c_str()), day1 = atoi(s1.substr(6, 2).c_str()),
        year2 = atoi(s2.substr(0, 4).c_str()), month2 = atoi(s2.substr(4, 2).c_str()), day2 = atoi(s2.substr(6, 2).c_str());
    month1--, month2--;
    cout << a(year1, month1, day1, year2, month2, day2) << endl;
    return 0;
}