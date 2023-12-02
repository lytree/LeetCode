#include "../header.h"

namespace unique_binary_search_trees_ii
{
    /**
     * Definition for a binary tree node.
     * struct TreeNode {
     *     int val;
     *     TreeNode *left;
     *     TreeNode *right;
     *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
     * };
     */
    class Solution
    {
    public:
        std::vector<TreeNode *> generateTrees(int n)
        {

            if (n <= 0)
            {
                return {};
            }
            return generateTree(1, n);
        }
        std::vector<TreeNode *> generateTree(int start, int end)
        {
            if (start > end)
            {
                return {nullptr};
            }
            std::vector<TreeNode *> res;
            for (int i = start; i <= end; i++)
            {
                // 左子树
                std::vector<TreeNode *> leftTrees = generateTree(start, i - 1);

                // 右子树
                std::vector<TreeNode *> rightTrees = generateTree(i + 1, end);

                // 拼接左右子树
                for (auto &leftTree : leftTrees)
                {
                    for (auto &rightTree : rightTrees)
                    {
                        TreeNode *root = new TreeNode(i);
                        root->left = leftTree;
                        root->right = rightTree;
                        res.push_back(root);
                    }
                }
            }
            return res;
        }
    };
};
#define unique_binary_search_trees_ii_fun(func) exc.registerMemberFunction(#func, &unique_binary_search_trees_ii::Solution::func);

int main()
{
    Excecutor<unique_binary_search_trees_ii::Solution, true> exc("../resource/all/95.txt");
    exc.instance = exc.createInstance<void>();
    unique_binary_search_trees_ii_fun(generateTrees);
    exc.run();
}