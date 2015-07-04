#include <iostream>
#include <boost/multi_index_container.hpp>
#include <boost/multi_index/member.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <string>

using namespace boost;
using namespace boost::multi_index;

using namespace std;
/*
      多值索引容器(multi_index_container)
      解决了boost里边bimap只能双值映射的短板.
      
      特点：可以自己设计容器，但是写法相当复杂(很虐心).
*/

struct Person
{
    string name;
    int    age;
    char   sex;
    Person(const string& n, int a, char f):name(n), age(a), sex(f)
    {
        
    }
};

/*用来提供切换索引的标签.*/
struct struct_name
{};
struct struct_age
{};
struct struct_sex
{};

/* 第一个参数是数据类型 ，第二个参数是索引 <里边是枚举所有的索引>  */
typedef multi_index_container<Person, indexed_by
                                                 <
    //  name
    ordered_non_unique<
tag<struct_name>, BOOST_MULTI_INDEX_MEMBER(Person, string, name)
                      >,
    //  age
    ordered_non_unique<
tag<struct_age>, BOOST_MULTI_INDEX_MEMBER(Person, int, age)
                      >,
    //  sex
    ordered_non_unique<
tag<struct_sex>, BOOST_MULTI_INDEX_MEMBER(Person, char, sex)
                      >
                                                 >
> person_multi;


int main(int ac, char **av)
{
    person_multi persons;
    
    persons.insert(Person("Bill", 30, 'a'));
    persons.insert(Person("Mike", 32, 'b'));
    persons.insert(Person("Bill", 32, 'b'));
    
    
                    /* 默认索引为 struct_name */
    cout << persons.count("Bill") << endl;
    cout << "-------------------------------------" << endl;
    
                    /* 切换索引为 struct_age */
    person_multi::index<struct_age>::type &age_index = persons.get<struct_age>();
    
    cout << age_index.count(32) << endl;
    cout << "-------------------------------------" << endl;
    
                    /* 切换索引为 struct_sex */
    person_multi::index<struct_sex>::type &sex_index = persons.get<struct_sex>();
    
    //获得两个迭代器
    person_multi::index<struct_sex>::type::iterator it_begin = sex_index.lower_bound('b');
    
    person_multi::index<struct_sex>::type::iterator it_end   =sex_index.upper_bound('b');
    
    typedef person_multi::index<struct_sex>::type::iterator Newit;
    for(Newit it = it_begin; it != it_end; it++)
        cout << it->name << "  " << it->age << "  " << it->sex;
    cout << endl;
    

    return 0;
}
