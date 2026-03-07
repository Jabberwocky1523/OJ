#include <bits/stdc++.h>
using namespace std;
string a(int year, int month, int day, int sum)
{
    month--;
    int dayofMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    bool isLeap = (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
    if (isLeap)
    {
        dayofMonth[1] = 29;
    }
    string ans;
    for (; sum >= dayofMonth[month] - day;)
    {

        sum -= dayofMonth[month] - day;
        day += dayofMonth[month] - day;
        if (day == dayofMonth[month])
        {
            day = 0;
            month = month + 1;
            if (month == 12)
            {
                year++;
                month = 0;
                if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
                {
                    dayofMonth[1] = 29;
                }
                else
                {
                    dayofMonth[1] = 28;
                }
            }
        }
    }
    month++;
    day += sum;
    if (day == 0)
    {
        day = dayofMonth[(--month) - 1];
    }
    string month1 = to_string(month), day1 = to_string(day);
    string temp = "0000";
    char *year1 = (char *)malloc(4 * sizeof(char));
    sprintf(year1, "%02d", year);
    ans += year1;
    ans += "-";
    temp = "00";
    temp = temp.erase(temp.length() - month1.length()) + month1;
    ans += temp + "-";
    if (day < 10)
    {
        ans += "0" + day1;
    }
    else
    {
        ans += day1;
    }
    return ans;
}
int main()
{
    int m;
    cin >> m;
    int year, month, day, sum;
    for (int i = 0; i < m; i++)
    {
        /* code */
        cin >> year >> month >> day >> sum;
        cout << a(year, month, day, sum) << endl;
    }

    return 0;
}