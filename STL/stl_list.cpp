#include <iostream>
#include <list>


using namespace std;
/*
    双向链表容器类： list <禁忌：不允许用数组[]的随机访问方法>
    1. insert    :时间复杂度为 O(1);
    2. remove    : ...
    3. remove_if :删除满足条件的所有元素;
    4. sort      :排序的复杂度为  (N *lgN)
    5. splice    :合并，将容器元素的节点加到到目标容器的最前边，是一个迁移
    6. merge     :合并（最好是已经排序好的）
    7. unique    :去重,将list变成集合,去除 *相邻* 的重复元素.
 
             <优势>               <劣势>
 vector :    随机访问          插入、删除代价大
   list :   插入、删除快          只能遍历访问
*/
void display(int value)
{
    cout << value << "  ";
}

bool removeIf(int value)
{
    if(value % 2 == 0) //判断偶数
        return true;
    else
        return false;
}

bool compareInt(int n1, int n2)
{
    if(n1 >= n2)
        return true;
    else
        return false;
}

int main(int ac, char **av)
{
    /* 1. 初始化操作 */
    list<int> one(10, 3); /* 预分配10个元素,值为3 */
    
    for_each(one.begin(), one.end(), display);
    cout << endl;
    cout << "----------------------------------------" <<endl;
    
    /*  2. 插入 */
    list<int> two;
    int intArray[] {1, 2, 3, 4, 5, 6};
    
    two.insert(two.begin(), intArray, intArray + 6);
    two.insert(two.end(), 200);
    two.insert(two.begin(), 100);
    //two.insert(two.begin() + 2, 99);  /* 错误，不支持随机访问. */
    
    for_each(two.begin(), two.end(), display);
    cout << endl;
    cout << "----------------------------------------" <<endl;
    
    /* 3. 删除 */
    two.remove(4);  /* 参数是元素值，不是索引 */
    for_each(two.begin(), two.end(), display);
    cout << endl;

    two.remove_if(removeIf); //传入一个回调函数(call-back)删除偶数

    for_each(two.begin(), two.end(), display);
    cout << endl;
    cout << "----------------------------------------" <<endl;

    /* 4. 排序 */
    
    two.sort(compareInt); //降序
    
    for_each(two.begin(), two.end(), display);
    cout << endl;
    cout << "----------------------------------------" <<endl;
    
    /* 5. splice 迁移（不是拷贝）*/
    
    two.splice(two.begin(), one);//将one中所有节点迁移到two的最前边
                                 //之后one为空了.
    
    for_each(two.begin(), two.end(), display);
    cout << endl << endl;
    
    cout << "one已经空了，有木有？  size = " << (one.begin() == one.end() ? 0 : 1) << endl;
    for_each(one.begin(), one.end(), display);
    cout << endl;

    cout << "----------------------------------------" <<endl;
    
    /* 6. unique 去重（线性复杂度 O<n>）*/
    
    two.unique();  /* 只去除相邻元素 */
    
    for_each(two.begin(), two.end(), display);
    cout << endl;
    cout << "-----------------------------------------" <<endl;
    
    /*  7. merge 合并(迁移操作,类似于归并操作) */
    
    one.insert(one.begin(), intArray + 3, intArray + 6);// 4，5，6
    two.sort();  //为two排序(升序).
    two.unique();//去掉重复的一个3
    
    two.merge(one);
    two.unique();//去掉重复的一个5

    for_each(two.begin(), two.end(), display);
    cout << endl << endl;
    
    cout << "one已经空了，有木有？  size = " << (one.begin() == one.end() ? 0 : 1) << endl;
    for_each(one.begin(), one.end(), display);
    cout << endl;
    
    return 0;
}
