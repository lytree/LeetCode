#include "../header.h"

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
namespace symmetric_tree
{
    class Solution
    {
    public:
        bool isSymmetric(TreeNode *root)
        {
            if (root == nullptr)
            {
                return true;
            }
            return dfs(root, root);
        }

        bool dfs(TreeNode *left, TreeNode *right)
        {
            if (left == nullptr && right == nullptr)
            {
                return true;
            }
            if (left != nullptr && right != nullptr)
            {
                return left->val == right->val && dfs(left->left, right->right) && dfs(left->right, right->left);
            }
            return false;
        }
    };
}

#define symmetric_tree_fun(func) exc.registerMemberFunction(#func, &symmetric_tree::Solution::func);

int main()
{
    Excecutor<symmetric_tree::Solution, true> exc("../resource/all/101.txt");
    exc.instance = exc.createInstance<void>();
    symmetric_tree_fun(isSymmetric);
    exc.run();
}