#include "../header.h"

namespace validate_binary_search_tree
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
        bool isValidBST(TreeNode *root)
        {
            return isValid(root, LONG_MIN, LONG_MAX);
        }
        bool isValid(TreeNode *root, long lower, long upper)
        {
            if (root == nullptr)
            {
                return true;
            }
            if (root->val <= lower || root->val >= upper)
            {
                return false;
            }
            return isValid(root->left, lower, root->val) && isValid(root->right, root->val, upper);
        }

        /**
         * 中序遍历 会先遍历出最小值 后面的遍历出来的值都比前一个大
         *
         **/
        bool isValidBSTV1(TreeNode *root)
        {
            long inorder = (long)INT_MIN - 1;
            std::stack<TreeNode *> stk;
            while (!stk.empty() || root != nullptr)
            {
                while (root != nullptr)
                {
                    stk.push(root);
                    root = root->left;
                }
                root = stk.top();
                stk.pop();
                if (root->val > inorder)
                {
                    return false;
                }
                inorder = root->val;
                root = root->right;
            }
        }
    };
} // namespace validate_binary_search_tree
#define validate_binary_search_tree_fun(func) exc.registerMemberFunction(#func, &validate_binary_search_tree::Solution::func);

int main()
{
    Excecutor<validate_binary_search_tree::Solution, true> exc("../resource/all/98.txt");
    exc.instance = exc.createInstance<void>();
    validate_binary_search_tree_fun(isValidBSTV1);
    exc.run();
}