//
// Created by 18483 on 2024/12/10.
//
#include <iostream>
#include <vector>
#include <algorithm>
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

// 力扣145.二叉树的后序遍历
// 递归
class Solution145_1
{
public:
    void _postOrderTraversal(TreeNode *cur, vector<int> &ret)
    {
        if (cur == nullptr)
            return;

        // 访问左节点
        _postOrderTraversal(cur->left, ret);
        // 访问右节点
        _postOrderTraversal(cur->right, ret);
        // 处理当前节点
        ret.push_back(cur->val);
    }

    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> ret;
        _postOrderTraversal(root, ret);

        return ret;
    }
};

// 迭代写法1
// 原则意义上的左右中
class Solution145_2_1
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> ret;
        // 使用栈模拟
        stack<TreeNode *> st;
        // 根节点为空直接返回空
        if (root == nullptr)
            return ret;

        // 防止满二叉子树死循环
        TreeNode *prev = nullptr;
        while (!st.empty() || root != nullptr)
        {
            // 一直找到最左节点
            while (root)
            {
                // 在循环中已经插入一次根节点
                // 此时循环上的判断root!=nullptr可以防止两个相同的根节点同时插入栈中
                st.push(root);
                root = root->left;
            }

            // 获取到当前节点
            root = st.top();
            st.pop();

            // 如果当前节点不存在右子树
            // 或者已经获取过同一个右子树
            // 说明已经遍历完成，当前节点就是子树根节点
            if (root->right == nullptr || root->right == prev)
            {
                ret.push_back(root->val);
                prev = root;
                // 将root置为空防止再一次获取最左节点
                root = nullptr;
            }
            else
            {
                // 存在右子树就还需要继续找
                st.push(root); // 将弹出的根节点再插入到栈中
                // 此时肯定不存在或者已经判断完左子树，所以直接走向右子树
                root = root->right;
            }
        }

        return ret;
    }
};

// 迭代写法2——投机取巧
// 后序的迭代写法实际上就是「中右左」的反向「左右中」
// 所以只需要将前序遍历的「中左右」改为「中右左」，再反向结果集即可
// 但是注意，这个方法只是完成了遍历的结果，遍历的方法基本上是不太严谨的
// 或者说是异构的前序遍历（即利用了两次反转：先反转为中右左，再反转结果集）
class Solution145_2_2
{
public:
    vector<int> postorderTraversal(TreeNode *root)
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

            // 中右左
            // 先插入左节点
            st.push(cur->left);
            // 再插入右节点
            st.push(cur->right);
        }

        reverse(ret.begin(), ret.end());

        return ret;
    }
};
