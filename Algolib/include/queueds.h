#ifndef QUEUEDS_H
#define QUEUEDS_H
#include "framework.h"
namespace algolib
{
    template <typename T>
    class Queue
    {
    public:
        Queue() { }

        Queue(size_t MaximumCount) : MAX(MaximumCount)
        {
            data = new T[MaximumCount];
        }

        ~Queue()
        {
            delete[] data;
        }

        void Create(size_t MaxmimumCount)
        {
            delete[] data;
            MAX = MaxmimumCount;
            data = new T[MaxmimumCount];
        }

        void Insert(T item)
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

        T Delete()
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

        const T& Front() const {
            return data[FRONT];
        } 
    private:
        T* data = nullptr;
        size_t MAX {0};
        long long int FRONT{-1}, REAR{-1};
    };
} // namespace algolib
#endif