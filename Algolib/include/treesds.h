#ifndef TREESDS_H
#define TREESDS_H
#include "framework.h"
#include <stack>
namespace algolib
{
    namespace trees
    {
        template <typename T>
        struct node
        {
            T info;
            node<T> *left;
            node<T> *right;
        };

        template <typename T>
        void InOrder(node<T> *root, std::function<void(T)> func)
        {
            std::stack<node<T> *> ADDRESSES;
            ADDRESSES.push(nullptr);
            node<T> *ptr = root;

        ADD_ADDRESSES:
            while (ptr != nullptr)
            {
                ADDRESSES.push(ptr);
                ptr = ptr->left;
            }

            ptr = ADDRESSES.top();
            ADDRESSES.pop();

            while (ptr != nullptr)
            {
                func(ptr->info);
                if (ptr->right != nullptr)
                {
                    ptr = ptr->right;
                    goto ADD_ADDRESSES;
                }
                ptr = ADDRESSES.top();
                ADDRESSES.pop();
            }
        }

        template <typename T>
        struct node_address
        {
            bool isNegative = false;
            node<T> *address = nullptr;
        };

        template <typename T>
        void PostOrder(node<T> *root, std::function<void(T)> func)
        {
            std::stack<node_address<T>> ADDRESSES;
            ADDRESSES.push({false, nullptr});
            node_address<T> ptr = {false, root};

        HERE_ADD_ADDRESSES:
            while (ptr.address != nullptr)
            {
                ADDRESSES.push(ptr);
                if (ptr.address->right != nullptr)
                {
                    ADDRESSES.push({true, ptr.address->right});
                }
                ptr = {false, ptr.address->left};
            }

            ptr = ADDRESSES.top();
            ADDRESSES.pop();
            while (ptr.isNegative == false && ptr.address != nullptr)
            {
                func(ptr.address->info);
                ptr = ADDRESSES.top();
                ADDRESSES.pop();
            }

            if (ptr.isNegative)
            {
                ptr.isNegative = false;
                goto HERE_ADD_ADDRESSES;
            }
        }

        template <typename T>
        void PreOrder(node<T> *root, std::function<void(T)> func)
        {
            std::stack<node<T> *> ADDRESSES;
            ADDRESSES.push(nullptr);
            node<T> *ptr = root;
            while (ptr != nullptr)
            {
                func(ptr->info);
                if (ptr->right != nullptr)
                    ADDRESSES.push(ptr->right);

                if (ptr->left != nullptr)
                    ptr = ptr->left;
                else
                {
                    ptr = ADDRESSES.top();
                    ADDRESSES.pop();
                }
            }
        }

        template <typename T>
        void InOrderRec(node<T> *root, std::function<void(T)> func)
        {
            if (root == nullptr)
                return;

            if (root->left)
                InOrderRec(root->left, func);
            func(root->info);
            if (root->right)
                InOrderRec(root->right, func);
        }

        template <typename T>
        void PreOrderRec(node<T> *root, std::function<void(T)> func)
        {
            if (root == nullptr)
                return;

            func(root->info);
            if (root->left)
                PreOrderRec(root->left, func);
            if (root->right)
                PreOrderRec(root->right, func);
        }

        template <typename T>
        void PostOrderRec(node<T> *root, std::function<void(T)> func)
        {
            if (root == nullptr)
                return;

            if (root->left)
                PostOrderRec(root->left, func);
            if (root->right)
                PostOrderRec(root->right, func);
            func(root->info);
        }

        template <typename T>
        class BinarySearchTrees
        {
        public:
            void find(const T &item, node<T> *&nodeloc, node<T> *&nodeparent) const
            {
                if (!root)
                {
                    nodeloc = nodeparent = nullptr;
                    return;
                }

                if (root->info == item)
                {
                    nodeloc = root;
                    nodeparent = nullptr;
                    return;
                }

                node<T> *curr, *prev;
                if (item < root->info)
                {
                    curr = root->left;
                    prev = root;
                }
                else
                {
                    curr = root->right;
                    prev = root;
                }

                while (curr != nullptr)
                {
                    if (item == curr->info)
                    {
                        nodeloc = curr;
                        nodeparent = prev;
                        return;
                    }

                    prev = curr;
                    if (item < curr->info)
                        curr = curr->left;
                    else
                        curr = curr->right;
                }

                nodeloc = nullptr;
                nodeparent = prev;
            }

            void Insert(T item)
            {
                node<T> *node_location, *node_parent;
                find(item, node_location, node_parent);
                if (node_location)
                    return;

                node<T> *newNode = new node<T>;
                newNode->info = item;
                newNode->left = newNode->right = nullptr;

                if (node_parent == nullptr)
                    root = newNode;
                else if (item < node_parent->info)
                    node_parent->left = newNode;
                else
                    node_parent->right = newNode;
            }

            node<T> *GetRoot() const
            {
                return root;
            }

        private:
            node<T> *root = nullptr;
        };

        template <typename T>
        class MaxHeapSequence // MaxHeap
        {
        public:
            MaxHeapSequence(uint32 _size)
            {
                Array = new T[_size];
            }
            ~MaxHeapSequence()
            {
                delete[] Array;
            }

            static void Insert(T item, uint32 &NumOfItems, uint32_t MaxSize, T *arr) // Can be used with any array
            {
                NumOfItems++;
                if (NumOfItems > MaxSize)
                {
                    _LOG_("HEAP STRUCTURE OVERFLOW");
                    return;
                }
                uint32 itr = NumOfItems - 1;
                while (itr > 0)
                {
                    uint32 parentIndex = ((itr+1) / 2) - 1 ;
                    if (item <= arr[parentIndex])
                    {
                        arr[itr] = item;
                        return;
                    }
                    arr[itr] = arr[parentIndex];
                    itr = parentIndex;
                }
                arr[0] = item;
            }

            static void Delete(T &item, uint32 &NumOfItems, T *arr) // Can be used with any array
            {
                item = arr[0];
                T last = arr[NumOfItems - 1];
                NumOfItems--;
                uint32 itr = 0, Litr = 1, Ritr = 2;
                while (Ritr < NumOfItems)
                {
                    if (last >= arr[Litr] && last >= arr[Ritr])
                    {
                        arr[itr] = last;
                        return;
                    }

                    if (arr[Ritr] <= arr[Litr])
                    {
                        arr[itr] = arr[Litr];
                        itr = Litr;
                    }
                    else
                    {
                        arr[itr] = arr[Ritr];
                        itr = Ritr;
                    }
                    Litr = itr * 2 + 1;
                    Ritr = Litr + 1;
                }
                if (Litr == NumOfItems - 1 && last < arr[Litr])
                    itr = Litr;

                arr[itr] = last;
            }

        private:
            T *Array;
        };
    } // namespace trees
} // namespace algolib
#endif