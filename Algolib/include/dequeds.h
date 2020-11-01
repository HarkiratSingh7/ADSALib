#ifndef DEQUEDS_H
#define DEQUEDS_H
#include "framework.h"
namespace algolib
{
    // Deque refers to double ended queue

    // Input Restricted Deque
    // Insertion at only one end. Deletions at both ends
    // Output Restricted Deque
    // Deletion at only one end. Insertions at both ends

    // Both concepts implemented here.
    // Deque. Insertions and Deletions at both ends.
    template <typename T>
    class Deque
    {
        Deque(size_T MaximumCount) : MAX(MaximumCount)
        {
            data = new T[MaximumCount];
        }

        ~Deque()
        {
            delete[] data;
        }

        void InsertFront(T item)
        {
            if ((FRONT == 0 and REAR == MAX - 1) or (FRONT == REAR + 1))
            {
                _LOG_("OVERFLOW");
                return;
            }

            if (FRONT == -1)
            {
                FRONT = REAR = 0;
            }
            else if (FRONT == 0)
            {
                FRONT = MAX - 1;
            }
            else
            {
                FRONT--;
            }
            
            data[REAR] = item;
        }

        void InsertRear(T item)
        {
            if ((FRONT == 0 and REAR == MAX - 1) or (FRONT == REAR + 1))
            {
                _LOG_("OVERFLOW");
                return;
            }

            if (FRONT == -1)
            {
                FRONT = REAR = 0;
            }
            else if (REAR == MAX-1)
            {
                REAR = 0;
            }
            else
            {
                REAR++;
            }

            data[REAR] = item;
        }

        T PopFront()
        {
            T item { };
            if (FRONT == -1)
            {
                _LOG_("UNDERFLOW");
                return item;
            }
            item = data[FRONT];
            if (FRONT == REAR)
            {
                FRONT = REAR = -1;
            }
            else if (FRONT == MAX - 1)
            {
                FRONT = 0;
            }
            else
            {
                FRONT++;
            }
            return item;
        }

        T PopRear()
        {
            T item { };
            if (REAR == -1)
            {
                _LOG_("UNDERFLOW");
                return item;
            }
            item = data[REAR];
            if (REAR == FRONT)
            {
                REAR = FRONT = -1;
            }
            else if (REAR == 0)
            {
                REAR = MAX - 1;
            }
            else
            {
                REAR--;
            }
            return item;
        }

    private:
        T *data = nullptr;
        size_t MAX;
        long long int FRONT{-1}, REAR{-1};
    };
} // namespace algolib
#endif