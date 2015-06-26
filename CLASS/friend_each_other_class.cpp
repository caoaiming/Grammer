#include <iostream>

using namespace std;
//互为友元类
class RemoteController;

class TV
{
private:
    bool mState = false; //true：打开   false：关闭
    int  mProgramIndex = 0; //节目索引
public:
    friend class RemoteController;
    bool getState();
    int  getProgramIndex();
    void reply(RemoteController &rc);
    //只是引用，并没有访问，要提前声明这是个类,如果访问了成员的话，还
    //只能在RemoteController后边实现
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
private:
    string mAudioStr;
public:
    friend class TV;//互为友元类
    void setState(TV &tv)
    {
        tv.mState = !tv.mState;
    }
    void setprogramIndex(TV &tv, int programIndex)
    {
        if(tv.mState)
            tv.mProgramIndex = programIndex;
        else
            cerr << "电视处于关闭状态" << endl;
    }
};

//只能放在这里，放到RemoteController前面不行，那样只知道RemotrController
//是个类，不知道他有什么成员
void TV::reply(RemoteController &rc)
{
    rc.mAudioStr = "非常抱歉，没有搜索到频道";
    cout << rc.mAudioStr << endl;
}

int main(int ac, char **av)
{
    TV tv;
    RemoteController remoteController;
    
    remoteController.setState(tv);
    remoteController.setprogramIndex(tv, 12);
    
    cout << "电视状态：" << (tv.getState() ? "开机" : "关机") << endl;
    cout << "频道：" << tv.getState() << endl;
    
    tv.reply(remoteController);
    return 0;
}