#include <iostream>

using namespace std;

//模板中的非类型参数<类型参数与非类型参数混合使用>

template <class Type, int n>
class ArrayTP {
private:
    Type mValues[n];
public:
    ArrayTP(Type values[]);
    ArrayTP(){}//无参构造方法
    
    virtual Type& operator[](int i);
};

template <class Type, int n>
ArrayTP<Type, n>::ArrayTP(Type values[])
{
    for(int i = 0; i < n; i++)
    {
        mValues[i] = values[i];
    }
}
template <class Type, int n>
Type& ArrayTP<Type, n>::operator[](int i)
{
    if(i < 0 || i >= n) {
        cerr << "索引越界." << endl;
        exit(EXIT_FAILURE);
    }
    return mValues[i];
}

int main(int argc, char *argv[])
{
    cout << "HAHHA" << endl;
    int values[] = {1, 2, 3, 4, 5};
    ArrayTP<int, 5> arrayTP;
    arrayTP = values;
    
    int value  = arrayTP[3];
    cout << "value =" << value << endl;
    for(int j = 0; j < 5; j++) {
        cout << "value[" << j+1 <<"] = " << arrayTP[j] << endl;
    }
    cout << arrayTP[20] << endl;
    return 0;
}