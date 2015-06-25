#include <iostream>

using namespace std;
//友元类： 一个类一旦成为另外一个类的友元类，就可以访问他的私有、保护成员

//例子: 由于电视机不能自己控制自己，所以需要遥控器变成电视机的友元类，以便于控制

class TV
{
private:
    bool mState = false;   //true ：开， false ：关
    int  mProgramIndex = 0;//节目索引
public:
    friend class RemoteController;
    bool getState();
    int  getProgramIndex();
};

bool TV::getState()
{
    return mState;
}

int TV::getProgramIndex()
{
    return mProgramIndex;
}

class RemoteController
{
public:
    void setState(TV &tv)
    {
        tv.mState = !tv.mState;
    }
    void setProgramIndex(TV& tv, int programIndex)
    {
        if(tv.mState)
            tv.mProgramIndex = programIndex;
        else
            cerr << "电视机未打开，无法设置频道" << endl;
    }
};

int main(int ac, char **av)
{
    TV tv;
    
    RemoteController control;
    
    control.setState(tv);
    control.setProgramIndex(tv, 12);
    
    cout <<  "电视机状态：" << (tv.getState() ? "开机" : "关机")<<endl;
    cout << "频道：" << tv.getProgramIndex() << endl;
    
    return 0;
}