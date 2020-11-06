#ifndef PRIORITYQDS_H
#define PRIORITYQDS_H
#include "framework.h"
#define LL_INHERITED
#include "linkedlist.h"
#include "queueds.h"
namespace algolib
{
    namespace OneWayLList
    {
        template <typename T>
        struct Item
        {
            T info;
            uint32 PriorityValue{0};
        };

        template <typename T>
        class PriorityQ : private LLinkedList<Item<T>>
        {
        public:
            void Insert(T item, uint32 Priority)
            {
                LLNode<Item<T>> *PREV = nullptr;
                if (LLinkedList<Item<T>>::START)
                {
                    LLNode<Item<T>> *PTR = LLinkedList<Item<T>>::START;
                    // Find a node, to insert after
                    // It should be inserted after the node having same priority
                    while (PTR->info.PriorityValue <= Priority)
                    {
                        PREV = PTR;
                        PTR = PTR->link;
                        if (!PTR)
                            break;
                    }
                }

                LLinkedList<Item<T>>::InsertAfter(PREV, {item, Priority});
            }

            T Delete()
            {
                T item{};
                if (this->START == nullptr)
                {
                    _LOG_("UNDERFLOW");
                    return item;
                }
                LLNode<Item<T>> *tmp = LLinkedList<Item<T>>::START;
                item = tmp->info.info;
                LLinkedList<Item<T>>::START = LLinkedList<Item<T>>::START->link;
                delete tmp;
                return item;
            }

            bool IsEmpty() const
            {
                if (LLinkedList<Item<T>>::START == nullptr)
                    return true;
                return false;
            }

            T GetHigh() const
            {
                if (LLinkedList<Item<T>>::START == nullptr)
                {
                    T t{};
                    return t;
                }
                return LLinkedList<Item<T>>::START->info.info;
            }
        };
    } // namespace OneWayLList

    namespace ArrayType
    {
        template <typename T>
        class PriorityQ
        {
        public:
            PriorityQ(int MaximumCount, int MaximumPriority = 0) : MAX(MaximumCount)
            {
                data = new Queue<T>[MaximumCount];

                for (int i = 0; i < MaximumCount; i++)
                    data[i].Create(MaximumCount);

                if (MaximumPriority != 0)
                    this->MaximumPriority = MaximumPriority;
                else
                    this->MaximumPriority = MaximumCount;
            }

            ~PriorityQ()
            {
                delete[] data;
            }

            void Insert(T item, uint32 Priority)
            {
                Priority = (Priority / static_cast<double>(MaximumPriority)) * MAX;
                (data[Priority - 1]).Insert(item);
                Count++;
            }

            T Delete()
            {
                T nullItem{};
                T nitem{};
                int Priority = 1;
                nitem = data[Priority-1].Delete();
                while (nitem == nullItem)
                {
                    Priority++;
                    if (Priority == MaximumPriority)
                        return nitem;
                    nitem = data[Priority-1].Delete();
                }
                Count--;
                return nitem;
            }

            T GetHigh() const
            {
                T nullItem{};
                T item{};
                int Priority = 1;
                item = data[Priority-1].Front();
                while (item == nullItem)
                {
                    Priority++;
                    if (Priority == MaximumPriority)
                        return item;
                    item = data[Priority-1].Front();
                }
                return item;
            }

            uint32 GetCount() const
            {
                return Count;
            }

        private:
            Queue<T> *data;
            uint32 Count {0};
            uint32 MAX;
            uint32 MaximumPriority;
        };
    } // namespace MatrixType
} // namespace algolib
#endif