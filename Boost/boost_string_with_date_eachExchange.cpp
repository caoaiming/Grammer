#include <iostream>
#include <string>
#include <boost/date_time/gregorian/gregorian.hpp>

using namespace boost::gregorian;
using namespace std;
/*
       字符串与日期之间的转换
   
    1. 字符串（两种格式）与日期的互转
    2. 获取日期中的部分信息（年、月、日、星期）
    3. 转换过程中抛出异常

*/

int main(int ac, char **av)
{
    // 1. 字符串与日期互转
    
    /* 2015-01-03 */
    string s1 = "2015-01-03";
    date d(from_simple_string(s1));/*失败，第三方库经常失败，说链接错误*/
    cout << to_simple_string(d) << endl;// 2015-Jan-03
    
    /*20151022*/
    string s2 = "20151022";
    date d1(from_undelimited_string(s1));
    cout <<  to_iso_extended_string(d1) << endl;
    
    cout << "-------------------------------------------" << endl;
    
    
    //2. 获取日期中的部分信息（年、月、日、星期）

    date::ymd_type ymd = d1.year_month_day();
    greg_weekday wd = d1.day_of_week();
    
    cout << "星期代码：" << wd.as_number << endl;
    cout << "星期：" << wd.as_long_string << endl;
    
    cout << "年：" << ymd.year.as_long_string() << endl;
    cout << "月：" << ymd.month.as_long_string() << endl;
    cout << "月：" << ymd.month.as_short_string() << endl;
    cout << "月：" << ymd.month << endl;
    cout << "日：" << ymd.day << endl;
    cout << "-------------------------------------------" << endl;

    //3. 转换过程中抛出异常

    try {
    /* boost库月份是 1——12, 有些语言是 0——11 ,注意区别。 */
        string bad_date = "20151409"; //没有14月
        date error_date(from_umdelimited_string(bad_date));
        
        cout << "执行不到这句话。。。" << endl;
    } catch (exception& e) {
        cout << "异常信息：" << e.what() << endl;
    }
    
    return 0;
}
