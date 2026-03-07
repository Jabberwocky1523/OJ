    #include <bits/stdc++.h>
    using namespace std;
    string a(int year, int day)
    {
        int dayofMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        bool isLeap = (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
        if (isLeap)
        {
            dayofMonth[1] = 29;
        }
        string ans;
        int i = 0;
        for (i = 0; day > dayofMonth[i];)
        {
            day -= dayofMonth[i];
            i++;
            if (i == 12)
            {
                i = 0;
                year++;
            }
        }
        int month = i + 1;
        string year1 = to_string(year), month1 = to_string(month), day1 = to_string(day);
        string temp = "0000";
        temp = temp.erase(temp.length() - year1.length()) + year1;
        ans += temp + "-";
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
        int year, day;
        while (cin >> year >> day)
        {
            /* code */
            cout << a(year, day) << endl;
        }

        return 0;
    }