#ifndef SORTINGS_H
#define SORTINGS_H
#include "framework.h"
#include "treesds.h"
namespace algolib
{
    template <typename T>
    void HeapSort(T *Array, uint32 N)
    {
        for (uint32 i = 1; i <= N - 1;)
            trees::MaxHeapSequence<T>::Insert(Array[i], i, N, Array); // Automatically Increments
        while (N > 1)
        {
            T item;
            trees::MaxHeapSequence<T>::Delete(item, N, Array);
            Array[N] = item;
        }

    }

    template <typename T>
    void BubbleSort(T *Array, uint32 N, bool descending = false)
    {
        // Step 1: Repeat Steps 2 and 3 for K = 1 to N - 1
        for (uint32 K = 0; K < N - 1; K++)
        {
            // Step 2: Set Index = 1
            int Index = 0;

            // Repeat while Index <= N - K
            while (Index < N - K - 1)
            {
                // a) Interchange
                if ((Array[Index] > Array[Index + 1] && !descending) || (Array[Index] < Array[Index + 1] && descending))
                {
                    T Temp = Array[Index];
                    Array[Index] = Array[Index + 1];
                    Array[Index + 1] = Temp;
                }

                // Increment Index
                ++Index;
            }
        }
    }

    template <typename T>
    void QUICK(T *Array, uint32 N, T &BEG, T &END, T &LOC)
    {
        // Step 1: Set LEFT := BEG, RIGHT := END and LOC := BEG
        T left = BEG; // Copy Constructor used
        T right = END;
        LOC = BEG;
        //SET_LOCATION(LOC, BEG);
        // Step 2: Scan from right to left
    STEP_2:
    {
        //  a) Repeat while A[LOC] <= A[RIGHT] and LOC != RIGHT
        while (Array[LOC] <= Array[right] && LOC != right)
        {
            --right;
        }

        //  b) If LOC = RIGHT, then: Return
        if (LOC == right)
            return;

        //  c) If A[LOC] > A[RIGHT], then
        {
            // [Interchange A[LOC] and A[RIGHT]
            T temp = Array[LOC];
            Array[LOC] = Array[right];
            Array[right] = temp;

            // Set LOC := RIGHT
            LOC = right;

            goto STEP_3;
        }
    }

        // Step 3 [Scan from left to right]
    STEP_3:
    {
        //  a) while A[LEFT] <= A[RIGHT] and LEFT != LOC:
        while (Array[left] <= Array[LOC] && left != LOC)
        {
            ++left;
        }

        //  b) If LOC = LEFT, then Return
        if (LOC == left)
            return;

        //  c) If A[LEFT] > A[LOC], then
        {
            //  i) Interchange A[LEFT] and A[LOC]
            T temp = Array[LOC];
            Array[LOC] = Array[left];
            Array[left] = temp;

            //  ii) Set LOC := LEFT
            LOC = left;
            //LOC = left;

            goto STEP_2;
        }
    }
    }

    template <typename T>
    void QuickSort(T *Array, uint32 N)
    {
        // Step 1: Intialize
        T TOP = -1;

        using namespace std;
        stack<T> LOWER, UPPER;

        // Step 2: Push boundary values of A onto stacks when A 2 or more elements
        if (N > 1)
        {
            TOP++;
            LOWER.push(0);
            UPPER.push(N - 1);
        }

        // Step 3: Repeat steps 4 to 7 while TOP != NULL
        while (TOP != -1)
        {
            // Step 4: [Pop sublist from stacks]
            T BEG = LOWER.top();
            LOWER.pop();
            T END = UPPER.top();
            UPPER.pop();
            T LOC = -1;
            --TOP;

            // Step 5: Call Quick
            QUICK(Array, N, BEG, END, LOC);

            // Step 6: [Push left sublist onto stacks when it has 2 or more elements]
            if (BEG < LOC - 1)
            {
                ++TOP;
                LOWER.push(BEG);
                UPPER.push(LOC - 1);
            }

            // Step 7: Push right sublist onto stacks when it has 2 or more elements
            if (END > LOC + 1)
            {
                ++TOP;
                LOWER.push(LOC + 1);
                UPPER.push(END);
            }
        }

        return;
    }

} // namespace algolib
#endif