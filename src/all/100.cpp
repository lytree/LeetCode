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
namespace same_tree
{

    class Solution
    {
    public:
        bool isSameTree(TreeNode *p, TreeNode *q)
        {
            if (p == nullptr && q == nullptr)
            {
                return true;
            }

            if (p != nullptr && q != nullptr)
            {
                return dfs(p, q);
            }
            return false;
        }
        bool dfs(TreeNode *root1, TreeNode *root2)
        {
            if (root1 == nullptr && root2 == nullptr)
            {
                return true;
            }
            if (root1 != nullptr && root2 != nullptr)
            {
                bool flagLeft = dfs(root1->left, root2->left);
                bool flag = (root1->val == root2->val);
                bool flagRight = dfs(root1->right, root2->right);
                return flag && flagLeft && flagRight;
            }
            return false;
        }
        /**
         * 简化版
         */
        bool isSameTree1(TreeNode *p, TreeNode *q)
        {
            if (p == nullptr && q == nullptr)
            {
                return true;
            }
            else if (p == nullptr || q == nullptr)
            {
                return false;
            }
            else if (p->val != q->val)
            {
                return false;
            }
            else
            {
                return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
            }
        }
    };
};
#define same_tree_fun(func) exc.registerMemberFunction(#func, &same_tree::Solution::func);

int main()
{
    Excecutor<same_tree::Solution, true> exc("../resource/all/100.txt");
    exc.instance = exc.createInstance<void>();
    same_tree_fun(isSameTree);
    exc.run();
}