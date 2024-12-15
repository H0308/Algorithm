//
// Created by 18483 on 2024/12/11.
//
#include <iostream>
#include <queue>

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

// 力扣104.二叉树的最大深度
// 后序遍历思路
/*
 * 二叉树的最大深度实际上应该用前序遍历进行求解，而后序遍历一般用来求二叉树的高度
 * 但是因为二叉树的最大深度就是根节点的高度
 * 而后序遍历的思路就是将当前层的高度返回给上一层，由上一层统计当前高度，一直到根节点
 * 此时根节点的高度就是二叉树的最大深度
 */
class Solution104_1
{
public:
    int maxDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        if (!root->left && !root->right)
            return 1;

        int leftHeight = maxDepth(root->left);
        int rightHeight = maxDepth(root->right);

        return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
    }
};

// 层序遍历思路
class Solution104_2
{
public:
    int maxDepth(TreeNode *root)
    {
        int floor = 0;
        int count = 0;
        queue<TreeNode *> que;
        que.push(root);

        while (!que.empty() && root != nullptr)
        {
            count = que.size();

            while (count--)
            {
                TreeNode *cur = que.front();
                que.pop();

                if (cur->left)
                    que.push(cur->left);

                if (cur->right)
                    que.push(cur->right);
            }

            floor++;
        }

        return floor;
    }
};
