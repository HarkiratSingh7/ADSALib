#ifndef PRIORITYQDS_H
#define PRIORITYQDS_H
#include "framework.h"
#define LL_INHERITED
#include "linkedlist.h"

// Construction work ahead
namespace algolib
{
    namespace OneWayLList
    {
        template <typename T>
        struct PQNode
        {
            T info;
            size_t PriorityValue{0};
            //PQNode<T> *link = nullptr;
        };

        template <typename T>
        class PriorityQ : private LLinkedList<PQNode<T>>
        {
        public:
            //PriorityQ() : LLinkedList<T>(false) { }

            void Insert(T item, size_t Priority)
            {
                LLNode<PQNode<T>> *PREV = nullptr;
                if (LLinkedList<PQNode<T>>::START)
                {
                    LLNode<PQNode<T>> *PTR = LLinkedList<PQNode<T>>::START;
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

                LLinkedList<PQNode<T>>::InsertAfter(PREV, {item, Priority});
            }

            T Delete()
            {
                T item{};
                if (this->START == nullptr)
                {
                    _LOG_("UNDERFLOW");
                    return item;
                }
                LLNode<PQNode<T>> *tmp = LLinkedList<PQNode<T>>::START;
                item = tmp->info.info;
                LLinkedList<PQNode<T>>::START = LLinkedList<PQNode<T>>::START->link;
                delete tmp;
                return item;
            }

            bool IsEmpty() const
            {
                if (LLinkedList<PQNode<T>>::START == nullptr)
                    return true;
                return false;
            }

            T GetHigh() const
            {
                if (LLinkedList<PQNode<T>>::START == nullptr)
                {
                    T t{};
                    return t;
                }
                return LLinkedList<PQNode<T>>::START->info.info;
            }
        };
    } // namespace OneWayLList
} // namespace algolib
#endif