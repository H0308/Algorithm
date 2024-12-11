//
// Created by 18483 on 2024/12/10.
//
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode()
        : val(0)
        , left(nullptr)
        , right(nullptr)
    {}

    TreeNode(int x)
        : val(x)
        , left(nullptr)
        , right(nullptr)
    {}

    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x)
        , left(left)
        , right(right)
    {}
};

// 力扣94.二叉树的中序遍历
// 递归写法
class Solution94_1
{
public:
    void _inorderTraversal(TreeNode *cur, vector<int> &ret)
    {
        if (cur == nullptr)
            return;

        _inorderTraversal(cur->left, ret);
        ret.push_back(cur->val);
        _inorderTraversal(cur->right, ret);
    }

    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ret;
        _inorderTraversal(root, ret);

        return ret;
    }
};

// 迭代写法
// 中序的迭代相对容易
// 先找到左子树，再取出当前节点
// 取出左节点后，下一个节点一定是根节点
// 所以只需要将root更新为nullptr就可以防止重复走到原来的节点
// 考虑到如果左节点是叶子，那么此时root->right一定为nullptr
// 所以可以更新为root = root->right，如果存在右节点，则下一次又会走右侧子树重复前面的步骤
// 如果不存在右节点，则下一次取出的就是根节点
class Solution_2
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> st;
        vector<int> ret;

        TreeNode *prev = nullptr;

        while (!st.empty() || root != nullptr)
        {
            // 先找到最左节点
            while (root)
            {
                st.push(root);
                root = root->left;
            }

            // 获取当前节点
            root = st.top();
            st.pop();
            ret.push_back(root->val);

            // 不论是否为空都要走右子树，一旦右为空，下一次就会取到当前子树的根节点
            root = root->right;
        }

        return ret;
    }
};