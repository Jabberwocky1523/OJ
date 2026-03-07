#include <bits/stdc++.h>
using namespace std;
int a(int year, int month, int day)
{
    int dayofMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    bool isLeap = (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
    if (isLeap)
    {
        dayofMonth[1] = 29;
    }
    int ans = day;
    for (int i = 0; i < month - 1; i++)
    {
        ans += dayofMonth[i];
    }
    return ans;
}
int main()
{
    int year, month, day;
    while (cin >> year >> month >> day)
    {
        /* code */
        cout << a(year, month, day) << endl;
    }

    return 0;
}