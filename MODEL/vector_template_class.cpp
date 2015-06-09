#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
    //vector template class is dynamic arry
    //is can be used as stack used.

    vector<int> values;

    values.push_back(20);
    values.push_back(40);
    values.push_back(60);
    values.push_back(80);

    //delete element.
    values.pop_back(); // delete is top_sp stack  = 80

    //values.erase(values.begin()); // delete the first  element   = 20
    //values.erase(values.begin() + 1);  //delete the second element    = 40


    for(int n:values) // enum every  member
    {
        cout << n << endl;
    }
    long size = values.size();

    cout << "values size = " << size << endl;

    for(long i = size -1 ; i >= 0; i--)
    {
        cout << values[i] << endl;
    }
    // othre  cite method.--->   values.at()
    cout << values.at(0) << endl;
    cout << values.at(1) << endl;

    return 0;
}
