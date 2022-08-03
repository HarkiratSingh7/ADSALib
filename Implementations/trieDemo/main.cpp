#include <iostream>
#include "trie.h"

using namespace std;
using namespace algolib;

int main()
{
    vector<string> keys = {"the", "a", "there",
        "dictionary", "airplane", "goodnight"};
    
    Trie myTrie(keys);

    if (myTrie.search("hello"))
        cout << "hello found" << '\n';
    else
        cout << "hello not found" << '\n';
    
    if (myTrie.search("dictionary"))
        cout << "dictionary found" << '\n';
    else
        cout << "dictionary not found" << '\n';

    if (myTrie.search("there"))
        cout << "there found" << '\n';
    else
        cout << "there not found" << '\n';

    return 0;
}