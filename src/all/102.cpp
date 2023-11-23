#include "../header.h"

namespace binary_tree_level_order_traversal
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
        std::vector<std::vector<int>> levelOrder(TreeNode *root)
        {
            std::vector<std::vector<int>> res;
            if (!root)
            {
                return res;
            }
            std::queue<TreeNode *> que;
            que.push(root);

            while (!que.empty())
            {
                int currentLevelSize = que.size(); // 当前层节点数目
                res.push_back(std::vector<int>());
                for (int i = 0; i < currentLevelSize; i++)
                {
                    TreeNode *node = que.front();
                    que.pop();
                    res.back().push_back(node->val);
                    if (node->left)
                    {
                        que.push(node->left);
                    }
                    if (node->right)
                    {
                        que.push(node->right);
                    }
                }
            }
            return res;
        }
    };
}
#define binary_tree_level_order_traversal_fun(func) exc.registerMemberFunction(#func, &binary_tree_level_order_traversal::Solution::func);

int main()
{
    Excecutor<binary_tree_level_order_traversal::Solution, true> exc("../resource/all/102.txt");
    exc.instance = exc.createInstance<void>();
    binary_tree_level_order_traversal_fun(levelOrder);
    exc.run();
}