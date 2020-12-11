#include <iostream>
#include "graph.h"

using namespace std;
using namespace algolib;

const uint32 N = 4;

void DisplayMatrix(AdjacencyMatrix::NodeMatrix<int>& A)
{
    cout << '\n';
    cout << "N ";
    for (uint32 i = 0; i < A.GetNumberOfNodes(); i++)
        cout << setw(10) << i + 1;

    cout << '\n';

    for (uint32 i = 0; i < A.GetNumberOfNodes(); i++)
    {
        cout << i + 1 << "|";
        for (uint32 j = 0; j < A.GetNumberOfNodes(); j++)
            cout << setw(10) << A.GetValue(i, j);
        cout << '\n';
    }

    cout << endl;
}

int main()
{
    AdjacencyMatrix::NodeMatrix<int> A(N);
    A.Query(0, 0) = 7;
    A.Query(0, 1) = 5;
    A.Query(0, 2) = 0;
    A.Query(0, 3) = 0;
    A.Query(1, 0) = 7;
    A.Query(1, 1) = 0;
    A.Query(1, 2) = 0;
    A.Query(1, 3) = 2;
    A.Query(2, 0) = 0;
    A.Query(2, 1) = 3;
    A.Query(2, 2) = 0;
    A.Query(2, 3) = 0;
    A.Query(3, 0) = 4;
    A.Query(3, 1) = 0;
    A.Query(3, 2) = 1;
    A.Query(3, 3) = 0;
    cout << "The Available Matrix is: ";
    DisplayMatrix(A);
    AdjacencyMatrix::NodeMatrix<int> BoolMatrix(N);
    AdjacencyMatrix::ShortestWarshallExists(A, BoolMatrix);
    cout << "The Path Matrix is: ";
    DisplayMatrix(BoolMatrix);
    AdjacencyMatrix::NodeMatrix<int> ShortestPathMatrix(N);
    AdjacencyMatrix::GetShortestPathMatrix(A, INT32_MAX, ShortestPathMatrix);
    cout << "The Shortest Path Matrix is ";
    DisplayMatrix(ShortestPathMatrix);

    return 0;
}