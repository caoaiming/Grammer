#include <iostream>

using namespace std;
//模板中的嵌套类

template <class T>
class Queue
{
private:
    class Item //用内部类作为队列成员
    {
    public:
        T value;
        Item* next;
        Item(const T& v): value(v), next(nullptr)
        {
        }
    };
    Item* mFirstItem; //对首元素
    Item* mLastItem;  //队尾元素
public:
    void enqueue(const T&value); //入队
    bool dequeue(T &value);      //出队
    T* getQueue()
    {
        if(mFirstItem != nullptr)
        {
            return &mFirstItem->value;
        }
        else
            return nullptr;
    }
    Queue():mFirstItem(nullptr), mLastItem(nullptr)
    {                   /*特别注意 <NOTE>*/
        /*这里要初始化，不然mFirstItem与mLastItem默认都不为空指针，
        会在第一次添加检测时就不成功，会进入else分支，造成内存非法访问*/
    }
};
template <class T>
void Queue<T>::enqueue(const T &value)
{
    Item *item = new Item(value);
    if(mFirstItem == nullptr)
    {
        mFirstItem = item;
        mLastItem  = item;
    }
    else
    {
        mLastItem->next = item;
        mLastItem = item;
    }
    
}
template <class T>
bool Queue<T>::dequeue(T &value)
{
    if(mFirstItem == nullptr)
        return false;
    
    value = mFirstItem->value;
    
    Item *tempItem = mFirstItem;
    mFirstItem = mFirstItem->next;
    delete tempItem;
    
    return true;
}

int main(int ac, char **av)
{
    Queue<string> strQueue;
    
    strQueue.enqueue("xyz");
    strQueue.enqueue("龙腾虎跃");
    
    cout << "队首元素: "<<*strQueue.getQueue() << endl;
    
    string value;
    strQueue.dequeue(value);
    cout << "出队元素: " << value << endl;
    cout << "队首元素: " << *strQueue.getQueue() << endl;

    return 0;
}