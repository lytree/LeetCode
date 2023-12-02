#include "../header.h"

namespace binary_tree_zigzag_level_order_traversal
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
        std::vector<std::vector<int>> zigzagLevelOrder(TreeNode *root)
        {
            std::vector<std::vector<int>> res;
            if (root == nullptr)
            {
                return res;
            }
            bool isOrderLeft = true;
            std::deque<TreeNode *> deq;
            deq.push_back(root);
            while (!deq.empty())
            {
                TreeNode *node;
                std::vector<int> que;
                int length = deq.size();
                for (int i = 0; i < length; i++)
                {
                    if (isOrderLeft)
                    {
                        node = deq.front();
                        deq.pop_front();
                        if (node->left)
                        {
                            deq.push_back(node->left); // 将下一层节点从左至右的加入队尾
                        }

                        if (node->right)
                        {
                            deq.push_back(node->right);
                        }
                    }
                    else
                    {
                        node = deq.back();
                        deq.pop_back();
                        if (node->right)
                        {
                            deq.push_front(node->right); // 将下一层节点从左至右的加入队尾
                        }

                        if (node->left)
                        {
                            deq.push_front(node->left);
                        }
                    }
                    que.push_back(node->val);
                }

                isOrderLeft = !isOrderLeft;
                res.push_back(que);
            }
            return res;
        }
    };
} // namespace binary_tree_zigzag_level_order_traversal
#define binary_tree_zigzag_level_order_traversal_fun(func) exc.registerMemberFunction(#func, &binary_tree_zigzag_level_order_traversal::Solution::func);

int main()
{
    Excecutor<binary_tree_zigzag_level_order_traversal::Solution, true> exc("../resource/all/103.txt");
    exc.instance = exc.createInstance<void>();
    binary_tree_zigzag_level_order_traversal_fun(zigzagLevelOrder);
    exc.run();
}