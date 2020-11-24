#include <iostream>
#include "treesds.h"

#include <chrono> // time calculation

using namespace std;
using namespace algolib;
using namespace trees;

#define RUN_CALC_TIME(precedeText,func) {\
    cout << "\n"<<precedeText<<"\n";\
    auto timePoint1 = chrono::system_clock::now();\
    func;\
    auto timePoint2 = chrono::system_clock::now();\
    chrono::duration<double> TIME_TAKEN = timePoint2 - timePoint1;\
    cout <<'\n' << TIME_TAKEN.count() << " s time elapsed" << endl;\
}

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

    RUN_CALC_TIME("Using iterative PREORDER", PreOrder(GoodTree.GetRoot(), print))
    
    RUN_CALC_TIME("Using recursie PREORDER", PreOrderRec(GoodTree.GetRoot(), print))

    RUN_CALC_TIME("Using iterative INORDER", InOrder(GoodTree.GetRoot(), print))
    
    RUN_CALC_TIME("Using recursive INORDER", InOrderRec(GoodTree.GetRoot(), print))
    
    RUN_CALC_TIME("Using iterative POSTORDER", PostOrder(GoodTree.GetRoot(), print))
    
    RUN_CALC_TIME("Using recursive POSTORDER", PostOrderRec(GoodTree.GetRoot(), print))

    return 0;
}