#include <iostream>

using namespace std;
//模板类<泛型>

typedef int Item;
class Stack
{
private:
    enum{Max = 20};
    Item mItems[Max];
    int mTop;
public:
    Stack();
    bool isEmpty() const;
    bool isFull() const;
    bool push(const Item& item);
    bool pop(Item& item);
    Item* getTop();
};

Stack::Stack()
{
    mTop = 0;
}

bool Stack::isEmpty() const
{
    return mTop == 0;
}

bool Stack::isFull() const
{
    return mTop == Max;
}

bool Stack::push(const Item &item)
{
    if(!isFull())
    {
        mItems[mTop++] = item;
        return true;
    } else {
        return false;
    }
}

bool Stack::pop(Item &item)
{
    if(!isEmpty())
    {
        item = mItems[--mTop];
        return true;
    } else {
        return false;
    }
}

Item* Stack::getTop()
{
    if(!isEmpty())
    {
        return &mItems[mTop-1];
    } else {
        return nullptr;
    }
}

template <class StackType>
class TemlateStack
{
private:
    enum{Max = 20};
    StackType mItems[Max];
    int mTop;
public:
    TemlateStack();
    bool isEmpty() const;
    bool isFull() const;
    bool push(const StackType& item);
    bool pop(StackType& item);
    StackType* getTop();
};

template <class StackType>
TemlateStack<StackType>::TemlateStack()
{
    mTop = 0;
}

template <class StackType>
bool TemlateStack<StackType>::isEmpty() const
{
    return mTop == 0;
}

template <class StackType>
bool TemlateStack<StackType>::isFull() const
{
    return mTop == Max;
}

template <class StackType>
bool TemlateStack<StackType>::push(const StackType &item)
{
    if(!isFull())
    {
        mItems[mTop++] = item;
        return true;
    } else {
        return false;
    }
}

template <class StackType>
bool TemlateStack<StackType>:: pop(StackType &item)
{
    if(!isEmpty())
    {
        item = mItems[--mTop];
        return true;
    } else {
        return false;
    }
}

template <class StackType>
StackType* TemlateStack<StackType>::getTop()
{
    if(!isEmpty())
    {
        return &mItems[mTop-1];
    } else {
        return nullptr;
    }
}

int main(int ac, char **av)
{
    Stack stack;
    stack.push(20);
    stack.push(30);
    stack.push(40);
    Item item;
    stack.pop(item);
    cout << "item = " << item << endl;
    cout << "stack top = " << *(stack.getTop()) << endl;
    
    TemlateStack<int> stack1;
    TemlateStack<string> stack2;
    
    stack1.push(88);
    stack2.push("Hello world");
    
    cout << "stack2 top -->" << *stack2.getTop() << endl;
    
    return 0;
}