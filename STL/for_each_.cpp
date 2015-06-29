#include <iostream>
#include <vector>

using namespace std;
/*  for_each函数 (可以代替for循环)  */

class Person
{
public:
    int code;
    string name;
    Person(int code ,string name)
    {
        this->code = code;
        this->name = name;
    }
};

void eachPerson(const Person& person)
{
cout<<"code: "<< person.code<<"  name: "<<person.name<< endl;
}

int main(int ac, char **av)
{
    vector<Person> persons;
    persons.push_back(Person(10, "Bill"));
    persons.push_back(Person(20, "Mike"));
    persons.push_back(Person(30, "John"));
#if 0
    for(auto it = persons.begin(); it != persons.end(); it++)
        cout<<"code: "<< it->code<<"  name: "<<it->name<< endl;
#endif
    for_each(persons.begin(), persons.end(), eachPerson);
    
    return 0;
}
