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

// 力扣144.二叉树的前序遍历
// 递归写法
class Solution144_1
{
public:
    void _preorderTraversal(TreeNode *root, vector<int> &ret)
    {
        if (root == nullptr)
            return;

        // 处理节点
        ret.push_back(root->val);
        _preorderTraversal(root->left, ret);
        _preorderTraversal(root->right, ret);
    }

    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> ret;
        _preorderTraversal(root, ret);
        return ret;
    }
};

// 迭代写法
// 迭代写法的主要思路就是用栈模拟递归的过程
// 前序遍历的顺序是：中左右
// 所以根节点是第一个被处理的节点
// 所以栈内的数据就是当前子树的根节点
// 如果栈不为空说明还没有走完整棵二叉树
// 每一次遍历时，先取出当前栈顶的元素，该元素就是当前子树的根节点，取出后弹出当前元素
// 接着走向右子树，注意不是左子树，因为栈是先进后出，而下一次是左子树先被去除
// 所以右子树先进才能保证左子树在栈顶
class Solution_2
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        // 用栈模拟
        stack<TreeNode *> st;
        // 先插入根节点
        st.push(root);
        vector<int> ret;

        while (!st.empty())
        {
            // 获取栈顶节点
            TreeNode *cur = st.top();
            st.pop();
            // 处理逻辑
            if (cur != nullptr)
                ret.push_back(cur->val);
            else
                continue;

            // 先插入右节点
            st.push(cur->right);
            // 再插入左节点
            st.push(cur->left);
        }

        return ret;
    }
};