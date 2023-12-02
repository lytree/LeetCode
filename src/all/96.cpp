#include "../header.h"

namespace unique_binary_search_trees
{
    class Solution
    {
    public:
        int numTrees(int n)
        {
            std::vector<int> g(n + 1, 0);
            g[0] = 1;
            g[1] = 1;
            for (int i = 2; i <= n; i++)
            {
                for (int j = 1; j <= i; j++)
                {
                    g[i] += g[j - 1] * g[i - j];
                }
            }
            return g[n];
        }
    };
}
#define unique_binary_search_trees_fun(func) exc.registerMemberFunction(#func, &unique_binary_search_trees::Solution::func);

int main()
{
    Excecutor<unique_binary_search_trees::Solution, true> exc("../resource/all/96.txt");
    exc.instance = exc.createInstance<void>();
    unique_binary_search_trees_fun(numTrees);
    exc.run();
}