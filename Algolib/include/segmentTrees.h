#ifndef SEGMENTTREES_H
#define SEGMENTTREES_H

#include "framework.h"

using namespace std;

class SegmentTrees
{
    SegmentTrees(vector<int> arr)
    {
        n = arr.size();
        tree.assign(2 * n, -1);
        
        for (int i = 0; i < n; i++)
            tree[i + n] = arr[i];

        for (int i = n - 1; i > 0; i--)
            tree[i] = tree[i << 1] + tree[i << 1 | 1];
    }

    void updateNode(int p, int value)
    {
        tree[p + n] = value;
        p += n;
        
        for (int i = p; i > 1; i>>=1)
            tree[i >> 1] = tree[i] + tree[i ^ 1];
    }

    int query(int l, int r)
    {
        int res = 0;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1)
                res += tree[l++];
            if (r & 1)
                res += tree[r--];
        }

        return res;
    }

    private:
    vector<int> tree;
    int n = 0;
};

#endif