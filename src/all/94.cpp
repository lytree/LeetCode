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
namespace binary_tree_inorder_traversal
{
    class Solution
    {
    public:
        std::vector<int> inorderTraversalV1(TreeNode *root)
        {
            std::vector<int> res;
            inorder(root, res);
            return res;
        }

        void inorder(TreeNode *root, std::vector<int> &res)
        {
            if (root == nullptr)
            {
                return;
            }
            inorder(root->left, res);
            res.push_back(root->val);
            inorder(root->right, res);
        }

        std::vector<int> inorderTraversalV2(TreeNode *root)
        {
            std::vector<int> res;
            std::stack<TreeNode *> stk;
            while (root != nullptr || !stk.empty())
            {
                while (root != nullptr)
                {
                    stk.push(root);
                    root = root->left;
                }
                root = stk.top();
                stk.pop();
                res.push_back(root->val);
                root = root->right;
            }
            return res;
        }
        std::vector<int> inorderTraversalV3(TreeNode *root)
        {
            std::vector<int> res;
            TreeNode *pre = nullptr;

            while (root != nullptr)
            {
                if (root->left != nullptr)
                {
                    pre = root->left;
                    while (pre->right != nullptr && pre->right != root)
                    {
                        pre = pre->right;
                    }
                    if (pre->right == nullptr)
                    {
                        pre->right = root;
                        root = root->left;
                    }
                    else
                    {
                        res.push_back(root->val);
                        pre->right = nullptr;
                        root = root->right;
                    }
                }
                else
                {
                    res.push_back(root->val);
                    root = root->right;
                }
            }

            return res;
        }
    };
}
#define binary_tree_inorder_traversal_fun(func) exc.registerMemberFunction(#func, &binary_tree_inorder_traversal::Solution::func);

int main()
{
    Excecutor<binary_tree_inorder_traversal::Solution, true> exc("../resource/all/94.txt");
    exc.instance = exc.createInstance<void>();
    binary_tree_inorder_traversal_fun(inorderTraversalV3);
    exc.run();
}