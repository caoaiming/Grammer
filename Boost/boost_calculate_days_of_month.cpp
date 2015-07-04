#include <iostream>
#include <boost/date_time/gregorian/gregorian.hpp>

using namespace boost::gregorian;
using namespace std;
/*
       计算指定月的天数
*/

int main(int ac, char **av)
{
    try {
        int y;
        cout << "请输入年(eg: 2012) /> ";
        cin >> y;
        greg_year year = greg_year(y); //规定范围： 1900 to 10000
        date start_of_next_year(year + 1, 1, 1);
        date d(year, 1, 1);
        
        while(d < start_of_next_year) {
            date::ymd_type ymd = d.end_of_month().year_month_day();
            cout << ymd.month << ": " << ymd.day << endl;
            cout << to_simple_string(d.end_of_month());
            d += months(1); //增量 ： 月
        }
    }
    catch(bad_year& by)
    {
        cout << "年超出范围：1900-10000" << by.what() << endl;
    }
    
    return 0;
}
