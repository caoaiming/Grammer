#include <iostream>

using namespace std;

//虚方法与多态:

//1.在类中创建对象,每一个方法都对应一个地址,如果是虚方法的话，我这个类中
//创建的对象的方法对应的地址是可以改变的，在C++中创建的类默认不是虚方法
//意味着类中所有方法的地址是不可以改变的.
//2.java所有的方法都是虚方法，地址都可以改变.


//多态：
//1.一个父类他所创建的对象可以描述多个子类所创建的对象，在同一时间内
//只能描述一个， 但是在不同的时间可以描述多个指类的对象

class Vehicle
{
private:
    string mName = "未知";
    float mMaxSpeed = 0;
public:
    virtual string getName()
    {
        return mName;
    }
    void setMaxSpeed(float maxSpeed)
    {
    
    }
    bool hasWheel()
    {
        return false;
    }
    int getWheelCount()
    {
        return 0;
    }
    bool canFly()
    {
        return false;
    }
};
class Car:public Vehicle
{
public:
    string getName()
    {
        return "小气车";
    }
    bool hasWheel()
    {
        return true;
    }
    bool canFly()
    {
        return false;
    }
    int getWheelCount()
    {
        return 4;
    }
};
class Car1:public Car
{
public:
    string getName()
    {
        return "小气车1";
    }
    bool hasWheel()
    {
        return true;
    }
    bool canFly()
    {
        return false;
    }
    int getWheelCount()
    {
        return 4;
    }
};
class Plane:public Vehicle
{
public:
    string getName()
    {
        return "飞机";
    }
    bool hasWheel()
    {
        return true;
    }
    bool canFly()
    {
        return true;
    }
    int getWheelCount()
    {
        return 3;
    }
};


int main(int ac, char **av)
{
    Vehicle *vehicle = new Car();//子类是完全继承父类，不需要转换，隐式转换
    cout << vehicle->getWheelCount() << endl; //输出父类的默认值。。。
    cout << vehicle->getName() << endl;//因为方法指针没有改变，仍然是父类的
    cout << "-------------------------------------------------" << endl;
    vehicle = new Plane();
    cout << vehicle->getWheelCount() << endl;
    cout << vehicle->getName() << endl;
    //在函数或方法中，可以用Vehicle作为参数类型，在不同的情况下传递不同的类
    //Car或者Plane,这些对象必须都是Vehicle的子类,这样就可以不关心内部实现
    //只调用父类的方法就可实现转换,Vehicle *vehicle必须是指针,否则没有办法
    //成为多态,要实现多态必须是指针
    cout << "---------------------------------------------------" << endl;
//    Vehicle vehicle1 = Car();
//    cout << vehicle1.getWheelCount() << endl;
//    cout << vehicle1.getName() << endl;

    return 0;
}
