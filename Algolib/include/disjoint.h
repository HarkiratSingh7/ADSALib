#ifndef DISJOINT_H
#define DISJOINT_J
#include "framework.h"

namespace algolib
{
    class DisjointSet
    {
    private:
        // first -> parent, second -> rank
        std::vector<std::pair<int, int>> subsets;
        int initialTotal{0};

    public:
        DisjointSet(int individual)
            : initialTotal(individual)
        {
            subsets.assign(individual, {0, 0});
            for (int i = 0; i < individual; i++)
                subsets[i].first = i;
        }

        int find(int x)
        {
            if (x != subsets[x].first)
                subsets[x].first = find(subsets[x].first);
            return subsets[x].first;
        }

        void set_union(int x, int y)
        {
            int px = find(x);
            int py = find(y);

            if (subsets[px].second > subsets[py].second)
                subsets[py].first = px;
            else
            {
                subsets[px].first = py;
                if (subsets[px].second == subsets[py].second)
                    subsets[py].second++;
            }
        }
    };
}

#endif