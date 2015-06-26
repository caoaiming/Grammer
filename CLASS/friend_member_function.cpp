#include <iostream>

using namespace std;
/*友元类/友元方法： 一个类可以成为另外一个类的友元类，一个方法也可以成为另外一
  个方法的友元方法

  一个友元类中可以访问朋友的私有或者受保护的成员，但是可能只有几方法用到了友元类
  的成员，所以没有必要将这个类设为友元类，只需要将方法设为友元方法。
  所以谁访问这个TV类中的成员，我就单独设置这个方法为TV类的友元方法。
  此方法相当虐心，因为要考虑声明与定义的顺序（特别强调）,差一点C++都不认.
  即便内联方法，也要注意规则
*/
#if 0
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
#endif
              /*如可将一个类的方法设为另外一个类的友元方法*/
/*----------------------------------------------------------------
1.讲需要设为友元函数方法的，把他放到要友元的那个类里边作声明，前边加friend
2.TV类里边使用了RemoteController，所以需要将RemoteController类放到前边
3.但是产生死结：需要解两个扣
              1.讲TV类的声明置前，让RemoteController知道TV是个什么东西
4.            2.访问了其中的成员，所以仅仅靠第三步不行了，需要将内联实现放
                到整个TV类的后边
-----------------------------------------------------------------*/

/*
 *第三步：开始声明， 让TV类声明在这，解决无法识别TV类的问题，知道有就行
 */
class TV;

/*第二步，把 RemoteController类移到TV类前边 在前边出现 <但是问题又来了：
 
 *内部包含TV类的成员，要求TV类在前边>
 *这样下去就死循环了,A要求B在前边， B要求A在前边....
 *
 *如何在一个类中使用另外一个类，分两种情况：
 *  1.只是引用  
            类似 “void setState(TV &tv)” TV只需要声明即可
 *  2.访问了类型中的成员
            类型必须定义（具体实现里面的内容）
 */
class RemoteController
{
public:
    void setState(TV &tv);
    void setProgramIndex(TV& tv, int programIndex);
    void process(TV &tv); //增加一个普通方法
};


class TV
{
private:
    bool mState = false;   //true ：开， false ：关
    int  mProgramIndex = 0;//节目索引
public:
    /*第一步: 在该类中声明，并指明是哪个类的方法，
     其次所属类必须在这个类前边声明               */
    friend void RemoteController::setState(TV &tv);
    friend void RemoteController::setProgramIndex(TV& tv, int programIndex);
    
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

/*第四步： 在外边，TV类后边实现内联函数，因为内部不但引用了TV类，还访问了成员，
 *所以需要第四步，保证TV类有不用关心内部实现
 */
inline void RemoteController::setState(TV &tv)
{
    tv.mState = !tv.mState;
}
inline void RemoteController::setProgramIndex(TV& tv, int programIndex)
{
    if(tv.mState)
        tv.mProgramIndex = programIndex;
    else
        cerr << "电视机未打开，无法设置频道" << endl;
}

void RemoteController::process(TV &tv)
{
    //tv.mState = 20;//报错，不是友元方法，不许访问，上边两个可以.
}



int main(int ac, char **av)
{
#if 1
    TV tv;
    
    RemoteController control;
    
    control.setState(tv);
    control.setProgramIndex(tv, 12);
    
    cout <<  "电视机状态：" << (tv.getState() ? "开机" : "关机")<<endl;
    cout << "频道：" << tv.getProgramIndex() << endl;
#endif
    
    return 0;
}
