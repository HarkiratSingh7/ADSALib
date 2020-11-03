#ifndef PRIORITYQDS_H
#define PRIORITYQDS_H
#include "framework.h"

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
            PQNode<T> *link = nullptr;
        };

        template <typename T>
        class PriorityQ
        {
        public:
            void Insert(T item, size_t Priority)
            {
                PQNode<T> *NEW_NODE = new PQNode<T>;
                NEW_NODE->info = item;
                NEW_NODE->PriorityValue = Priority;
                if (START == nullptr)
                {
                    NEW_NODE->link = nullptr;
                    START = NEW_NODE;
                    return;
                }
                PQNode<T> *PREV = nullptr;
                PQNode<T> *PTR = START;
                // Find a node, to insert after
                // It should be inserted after the node having same priority
                while (PTR->PriorityValue <= Priority)
                {
                    PREV = PTR;
                    PTR = PTR->link;
                    if (!PTR)
                        break;
                }
                NEW_NODE->link = PTR;
                if (PREV)
                    PREV->link = NEW_NODE;
                else
                    START = NEW_NODE;
                
            }

            T Delete()
            {
                T item {};
                if (this->START == nullptr)
                {
                    _LOG_("UNDERFLOW");
                    return item;
                }
                PQNode<T> *tmp = START;
                item = tmp->info;
                START = START->link;
                delete tmp;
                return item;
            }

            bool IsEmpty() const
            {
                if (START == nullptr)
                    return true;
                return false;
            }

            T GetHigh() const
            {
                if (START == nullptr)
                {
                    T t{};
                    return t;
                }
                return START->info;
            }

        private:
            PQNode<T> *START = nullptr;
        };
    } // namespace OneWayLList
} // namespace algolib
#endif