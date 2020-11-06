#include <iostream>
#include <string>
#include "priorityqds.h"

using namespace std;
using namespace algolib;

int main()
{
    ArrayType::PriorityQ<string> Example(10);
    Example.Insert("D", 4);
    Example.Insert("A", 1);
    Example.Insert("C", 2);
    Example.Insert("E", 4);
    Example.Insert("G", 5);
    Example.Insert("B", 1);
    Example.Insert("F", 4);
    Example.Insert("1", 2);
    Example.Insert("HAHA", 1);

    while (Example.GetCount())
    {
        cout << Example.GetHigh() << " ";
        Example.Delete();
    }

    cout << endl;

    OneWayLList::PriorityQ<int> IntExample;
    IntExample.Insert(0, 3);
    int aa{};
    IntExample.Insert(aa, 1);
    IntExample.Insert(1, 1);

    while (IntExample.IsEmpty() == false)
    {
        cout << IntExample.GetHigh() << " ";
        IntExample.Delete();
    }

    cout << endl;

    return 0;
}

