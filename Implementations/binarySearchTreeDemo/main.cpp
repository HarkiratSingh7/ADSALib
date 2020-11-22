#include <iostream>
#include "treesds.h"

#include <chrono> // time calculation

using namespace std;
using namespace algolib;
using namespace trees;

int main()
{
    BinarySearchTrees<int> GoodTree;
    GoodTree.Insert(14);
    GoodTree.Insert(10);
    GoodTree.Insert(17);
    GoodTree.Insert(12);
    GoodTree.Insert(10);
    GoodTree.Insert(11);
    GoodTree.Insert(20);
    GoodTree.Insert(12);
    GoodTree.Insert(18);
    GoodTree.Insert(25);
    GoodTree.Insert(20);
    GoodTree.Insert(8);
    GoodTree.Insert(22);
    GoodTree.Insert(11);
    GoodTree.Insert(23);

    std::function<void(int)> print = [] (int a)
    {
        std::cout << a << " ";
    };

    cout << "\nUsing iterative PREORDER\n";
    auto timePoint = chrono::system_clock::now();
    PreOrder(GoodTree.GetRoot(), print);
    auto timePoint2 = chrono::system_clock::now();
    chrono::duration<double> TIME_TAKEN = timePoint2 - timePoint;
    cout <<'\n' << TIME_TAKEN.count() << " s time elapsed" << endl;
        
    cout << "\nUsing recursive PREORDER\n";
    timePoint = chrono::system_clock::now();
    PreOrderRec(GoodTree.GetRoot(), print);
    timePoint2 = chrono::system_clock::now();
    TIME_TAKEN = timePoint2 - timePoint;
    cout <<'\n' << TIME_TAKEN.count() << " s time elapsed" << endl;
     

    cout << "\nUsing iterative INORDER\n";
    timePoint = chrono::system_clock::now();
    InOrder(GoodTree.GetRoot(), print);
    timePoint2 = chrono::system_clock::now();
    TIME_TAKEN = timePoint2 - timePoint;
    cout <<'\n' << TIME_TAKEN.count() << " s time elapsed" << endl;
     
    
    cout << "\nUsing recursive INORDER\n";
    timePoint = chrono::system_clock::now();
    InOrderRec(GoodTree.GetRoot(), print);
    timePoint2 = chrono::system_clock::now();
    TIME_TAKEN = timePoint2 - timePoint;
    cout <<'\n' << TIME_TAKEN.count() << " s time elapsed" << endl;
    

    cout << "\nUsing iterative POSTORDER\n";
    timePoint = chrono::system_clock::now();
    PostOrder(GoodTree.GetRoot(), print);
    timePoint2 = chrono::system_clock::now();
    TIME_TAKEN = timePoint2 - timePoint;
    cout <<'\n' << TIME_TAKEN.count() << " s time elapsed" << endl;
     

    cout << "\nUsing recursive POSTORDER\n";
    timePoint = chrono::system_clock::now();
    PostOrderRec(GoodTree.GetRoot(), print);
    timePoint2 = chrono::system_clock::now();
    TIME_TAKEN = timePoint2 - timePoint;
    cout <<'\n' << TIME_TAKEN.count() << " s time elapsed" << endl;
     

    return 0;
}