#include <bits/stdc++.h>
using namespace std;
bool isLeap(int year)
{
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}
int a(int year1, int month1, int day1, int year2, int month2, int day2)
{
    month1--, month2--;
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
    ans += day2 - day1;
    return ans;
}

int main()
{
    int month, day;
    cin >> month >> day;
    string s[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    int res = a(2012, 4, 12, 2012, month, day);
    int temp = (3 + res) % 7;
    cout << s[temp];
    return 0;
}