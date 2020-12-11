#ifndef GRAPH_H
#define GRAPH_H
#include "framework.h"

namespace algolib
{
    namespace AdjacencyMatrix
    {
        template <typename T>
        class NodeMatrix
        {
        public:
            NodeMatrix(int n) : NumberOfNodes(n)
            {
                Matrix = new T *[n];
                for (uint32 i = 0; i < NumberOfNodes; i++)
                    Matrix[i] = new T[n];
            }

            ~NodeMatrix()
            {
                for (uint32 i = 0; i < NumberOfNodes; i++)
                    delete[] Matrix[i];
                delete[] Matrix;
            }

            T &Query(uint32 i, uint32 j)
            {
                return Matrix[i][j];
            }

            T GetValue(uint32 i, uint32 j) const
            {
                return Matrix[i][j];
            }

            uint32 GetNumberOfNodes() const
            {
                return NumberOfNodes;
            }

        private:
            T **Matrix;
            uint32 NumberOfNodes;
        };

        template <typename T>
        void ShortestWarshallExists(NodeMatrix<T> &AdjMatrix, NodeMatrix<T> &Q)
        {
            if (AdjMatrix.GetNumberOfNodes() != Q.GetNumberOfNodes())
                return;
            uint32 N = AdjMatrix.GetNumberOfNodes();

            for (uint32 i = 0; i < N; i++)
                for (uint32 j = 0; j < N; j++)
                    if (AdjMatrix.GetValue(i, j))
                        Q.Query(i, j) = 1;
                    else
                        Q.Query(i, j) = 0;

            for (uint32 k = 0; k < N; k++)
                for (uint32 j = 0; j < N; j++)
                    for (uint32 i = 0; i < N; i++)
                        Q.Query(i, j) = Q.GetValue(i, j) | (Q.GetValue(i, k) & Q.GetValue(k, j));
        }

        template <typename T>
        void GetShortestPathMatrix(NodeMatrix<T> &AdjMatrix, T MAX_IN_TERMS_OF_T, NodeMatrix<T> &Q)
        {
            if (AdjMatrix.GetNumberOfNodes() != Q.GetNumberOfNodes())
                return;
            uint32 N = AdjMatrix.GetNumberOfNodes();

            for (uint32 i = 0; i < N; i++)
                for (uint32 j = 0; j < N; j++)
                    if (AdjMatrix.GetValue(i, j))
                        Q.Query(i, j) = AdjMatrix.GetValue(i, j);
                    else
                        Q.Query(i, j) = MAX_IN_TERMS_OF_T;

            for (uint32 k = 0; k < N; k++)
                for (uint32 j = 0; j < N; j++)
                    for (uint32 i = 0; i < N; i++)
                    {
                        if (Q.GetValue(i, k) == MAX_IN_TERMS_OF_T || Q.GetValue(k, j) == MAX_IN_TERMS_OF_T)
                            continue;
                        Q.Query(i, j) = min(Q.GetValue(i, j), (Q.GetValue(i, k) + Q.GetValue(k, j)));
                    }
        }
    } // namespace AdjacencyMatrix
} // namespace algolib
#endif