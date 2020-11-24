#include <iostream>

#include "sortings.h"

using namespace std;
using namespace algolib;
#define DATA_ARR                                                           \
    {                                                                      \
        34, 34, 99, -1, 89, 45, 21, 0, 34, 95, 33, 432, 999, 1001, -11, 94 \
    }
#define N 16
inline void Print(int *arr)
{
    for (uint32 i = 0; i < N; i++)
        cout << arr[i] << " ";
    cout << "\n";
}
int main()
{
    // No need to delete stack allocated arrays
    int arr1[N] = DATA_ARR;
    cout << "The array is ";
    Print(arr1);
    RUN_CALC_TIME("HeapSort", HeapSort(arr1, N));
    Print(arr1);

    int arr2[N] = DATA_ARR;
    RUN_CALC_TIME("BubbleSort", BubbleSort(arr2, N));
    Print(arr2);

    int arr3[N] = DATA_ARR;
    RUN_CALC_TIME("QuickSort", QuickSort(arr3, N));
    Print(arr3);

    return 0;
}