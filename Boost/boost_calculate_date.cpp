#include <iostream>
#include <string>

#include <boost/data_time/gregorian/gregorian.hpp>

using namespace boost::gregorian
using namespace std;
/*
     //计算两个时间之间的间隔(以天为单位)
*/

int main(int ac, char **av)
{
    string s1 = "1989-03-15";
    date birthday(from_simple_string(s));
    
    date today = day_clock::local_day();/*获取系统当前时间*/
    days days_alive = today - birthday;
    cout << "已经出生了" << days_alive << " 天" << endl;
    
    // 也可以这样写
    cout << "已经出生了" << days_alive.days() << " 天" << endl;

    return 0;
}
