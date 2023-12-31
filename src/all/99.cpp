#include "../header.h"

namespace recover_binary_search_tree
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
        /**
         *
         *
         * 中序遍历搜索数 前一个小于后一个
         *
         *
         *
         * **/
        void recoverTree(TreeNode *root)
        {
            std::stack<TreeNode *> stk;
            // 需要交换的两个节点
            TreeNode *x = nullptr;
            TreeNode *y = nullptr;
            TreeNode *pre = nullptr;
            while (root != nullptr || !stk.empty())
            {
                while (root != nullptr)
                {
                    stk.push(root);
                    root = root->left;
                }
                root = stk.top();
                stk.pop();
                if (pre != nullptr && pre->val > root->val)
                {
                    y = root;
                    if (x == nullptr)
                    {
                        x = pre;
                    }
                    else
                    {
                        break;
                    }
                }
                pre = root;
                root = root->right;
            }
            std::swap(x->val, y->val);
        }

        TreeNode *x = nullptr;
        TreeNode *y = nullptr;
        TreeNode *pre = nullptr;

        void recoverTree1(TreeNode *root)
        {
            dfs(root);

            std::swap(x->val, y->val);
        }
        void dfs(TreeNode *root)
        {
            if (root == nullptr)
            {
                return;
            }
            dfs(root->left);

            if (pre != nullptr)
            {
                if (pre->val > root->val)
                {
                    if (x == nullptr)
                    {
                        x = pre;
                        y = root; // 防止当前位置就是交换的位置
                    }
                    else
                    {
                        y = root;
                        return;
                    }
                }
            }
            pre = root;
            dfs(root->right);
        }
    };
} // namespace recover_binary_search_tree
#define recover_binary_search_tree_fun(func) exc.registerMemberFunction(#func, &recover_binary_search_tree::Solution::func);

int main()
{
    Excecutor<recover_binary_search_tree::Solution, true> exc("../resource/all/99.txt");
    exc.instance = exc.createInstance<void>();
    recover_binary_search_tree_fun(recoverTree);
    exc.run();
    recover_binary_search_tree_fun(recoverTree1);
    exc.run();
}