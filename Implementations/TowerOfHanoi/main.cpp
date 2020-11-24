// This file has implemented TowerOfHanoi using Recursion and without using Recursion
// We can use Stacks to emulate recursions.
// Stacks seem to get faster sometimes. Sometimes recursion seem faster. (INCASE OF BIGGER NUMBERS 6,7,8,9,10,.. etc)

#include <iostream>
#include "stackds.h"
#include <chrono>

using namespace std;
using namespace algolib;

#define PEGWRITE(from, to) cout << from << "-->" << to << ", "

void RecTowerOfHanoi(int n, string BeginningPegName, string AuxiliaryPegName, string EndPegName); // Recursion
void TowerOfHanoi(int n, string BeginningPegName, string AuxiliaryPegName, string EndPegName);    // Stacks

int main()
{
    SetLog_OSTREAM_OBJ(&cout);
    while (true)
    {
        int n;
        cout << "Now steps for tower of hanoi for n = (Input your value) ";
        cin >> n;
        RUN_CALC_TIME("Using Recursion", RecTowerOfHanoi(n, "A", "B", "C"));
        
        RUN_CALC_TIME("Using Stacks", TowerOfHanoi(n, "A", "B", "C"));

        cout << "Do you want to continue ? (y/n) ";
        char a;
        cin >> a;
        if (a == 'n')
            break;
    }

    return 0;
}

// Using stacks
void TowerOfHanoi(int n, string BeginningPegName, string AuxiliaryPegName, string EndPegName)
{
    Stack<int> T_N(n);
    Stack<string> T_BEG(n);
    Stack<string> T_AUX(n);
    Stack<string> T_END(n);
    Stack<int> T_ADD(n);
    string temp;
    int add = 1;
    bool running = true;

    while (running)
    {
        switch (add)
        {
        case 1:
            if (n == 1)
            {
                PEGWRITE(BeginningPegName, EndPegName);
                add = 5;
                break;
            }
        case 2:
            T_N.Push(n);
            T_BEG.Push(BeginningPegName);
            T_AUX.Push(AuxiliaryPegName);
            T_END.Push(EndPegName);
            T_ADD.Push(3);
            n--;
            temp = EndPegName;
            EndPegName = AuxiliaryPegName;
            AuxiliaryPegName = temp;
            add = 1;
            break;
        case 3:
            PEGWRITE(BeginningPegName, EndPegName);
        case 4:
            T_N.Push(n);
            T_BEG.Push(BeginningPegName);
            T_AUX.Push(AuxiliaryPegName);
            T_END.Push(EndPegName);
            T_ADD.Push(5);
            n--;
            temp = BeginningPegName;
            BeginningPegName = AuxiliaryPegName;
            AuxiliaryPegName = temp;
            add = 1;
            break;
        case 5:
            if (T_ADD.IsEmpty())
            {
                return;
            }
            n = T_N.PopAndGetTop();
            BeginningPegName = T_BEG.PopAndGetTop();
            AuxiliaryPegName = T_AUX.PopAndGetTop();
            EndPegName = T_END.PopAndGetTop();
            add = T_ADD.PopAndGetTop();
            break;
        default:
            break;
        }
    }
}

// Using Recursion
void RecTowerOfHanoi(int n, string BeginningPegName, string AuxiliaryPegName, string EndPegName)
{
    if (n == 1)
    {
        PEGWRITE(BeginningPegName, EndPegName);
        return;
    }

    RecTowerOfHanoi(n - 1, BeginningPegName, EndPegName, AuxiliaryPegName);
    PEGWRITE(BeginningPegName, EndPegName);
    RecTowerOfHanoi(n - 1, AuxiliaryPegName, BeginningPegName, EndPegName);
}