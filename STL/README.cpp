/*
 * STL = standard template library (标准模板库)
 *    Alex Stepanov和Meng Lee在 Hewlett-Packard实验室开发了STL,并
 *    1994年公开发布。后来ISO/ANSI C++委员会投票，同意将其作为C++标准
 *    的组成部分
 
 * STL是基于泛型编程模式的
 
   【容器】：
             1.与数组相似，可以存储若干个值
             2.容器中每一个值的类型都是相同的
         常用的容器：vector、 valarray
 
   【迭代器】：
             1.可以用来遍历容器中的值
             vactor<double>::iterator it = vdouble.begin();
             copy(darray, darray + 10, it);
             while(it != vdouble.end())
             {
                 cout << *it << endl;
                 it++;
             }
 
   【函数对象】：
               1.类似于函数的对象，可以是类对象或者函数指针.
 
   
   【算法】
               1.综合前边三种方法来完成特定的任务
                  (1)排序
                  (2)查找
 */
