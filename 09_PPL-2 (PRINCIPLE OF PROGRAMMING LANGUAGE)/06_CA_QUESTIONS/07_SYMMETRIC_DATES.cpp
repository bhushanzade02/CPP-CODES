#include <iostream>
using namespace std;

bool isValid(int day, int month, int year)
{

    int daysinmonth[] = {31, 28, 31, 30, 31, 30,
                         31, 31, 30, 31, 30, 31};

    bool isleap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
    if (month == 2 && isleap)
    {
        return day >= 1 && day <= 29;
    }

    if (month < 1 || month > 12)
        return false;
    if (day < 1 || day > daysinmonth[month - 1])
        return false;

    return true;
}

string toTwodigit(int num)
{
    if (num < 10)
    {
        return "0" + to_string(num);
    }
    return to_string(num);
}

string toFourdigit(int num)
{
    string str = to_string(num);
    while (str.length() < 4)
    {
        str = "0" + str;
    }
    return str;
}

int main()
{
    for (int year = 2000; year <= 2100; year++)
    {
        for (int month = 1; month <= 12; month++)
        {
            for (int day = 1; day <= 31; day++)
            {
                if (!isValid(day, month, year))
                    continue;

                
                string datestr = toTwodigit(day) + toTwodigit(month) + toFourdigit(year);
                string reverse = string(datestr.rbegin(), datestr.rend());

                if (datestr == reverse)

                {
                    cout << toTwodigit(day) << "-" << toTwodigit(month) << "-" << toFourdigit(year) << " It is Palindrome" << endl;
                }
            }
        }
    }
}