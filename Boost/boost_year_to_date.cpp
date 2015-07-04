#include <iostream>
#include <string>
#include <boost/date_time/gregorian/gregorian.hpp>

using namespace boost::gregorian;
using namespace std;
/*
    通过年来改变日期
*/

int main(int ac, char **av)
{
    date today = day_clock::local_day();
    partial_date pd(1, Jan); //指定月和日期
    
    days days1 = today - pd.get_date(today.year()); //指定年
    cout << days1 << endl;
    
    days days2 = pd.get_date(today.year() + 2) - today;
    cout << days2 << endl;
    
    return 0;
}
