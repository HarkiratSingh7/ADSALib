#ifndef TRIE_H
#define TRIE_H

#include "framework.h"

namespace algolib
{
    const int ALPHABET_SIZE = 26;

    struct TrieNode
    {
        std::vector<TrieNode *> childrenNodes;
        bool isLeaf = false;

        TrieNode()
        {
            childrenNodes.assign(ALPHABET_SIZE, nullptr);
        }
    };

    class Trie
    {
    public:
        Trie()
        {
            root = new TrieNode;
            Resources.push_back(root);
        }
        Trie(const std::vector<std::string> &keyList) : Trie()
        {
            for (const auto &word : keyList)
                this->insert(word);
        }
        ~Trie()
        {
            for (const auto &ptr : Resources)
                delete ptr;
        }
        void insert(std::string key)
        {
            TrieNode *pNode = root;
            for (const auto &ch : key)
            {
                int index = ch - 'a';
                if (!pNode->childrenNodes[index])
                {
                    pNode->childrenNodes[index] = new TrieNode;
                    Resources.push_back(pNode->childrenNodes[index]);
                }
                pNode = pNode->childrenNodes[index];
            }

            pNode->isLeaf = true;
        }

        bool search(std::string key)
        {
            TrieNode *pNode = root;
            for (const auto &ch : key)
            {
                int index = ch - 'a';
                if (!pNode->childrenNodes[index])
                    return false;
                pNode = pNode->childrenNodes[index];
            }

            return pNode->isLeaf;
        }

    private:
        TrieNode *root = nullptr;
        std::vector<TrieNode *> Resources;
    };
}

#endif
