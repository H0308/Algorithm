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

// 力扣111.二叉树的最小深度
// 后序遍历
// 在最大深度中取出最小值即为二叉树的最小深度
// 注意处理不存在右子树或者左子树的情况
class Solution111_1
{
public:
    int minDepth(TreeNode *root)
    {
        if (!root)
            return 0;

        int leftHeight = minDepth(root->left);
        int rightHeight = minDepth(root->right);

        int depth = 0;
        if (leftHeight && rightHeight)
            depth = min(leftHeight, rightHeight);
        else if (leftHeight || rightHeight)
            depth = leftHeight ? leftHeight : rightHeight;

        return depth + 1;
    }
};

// 层序遍历
class Solution111_2
{
public:
    int minDepth(TreeNode *root)
    {
        // 初始化时高度为1
        int count = 0, floor = 1;
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

                // 找到一个叶子节点就直接返回
                if (!cur->left && !cur->right)
                {
                    return floor + 1;
                }
            }
            floor++;
        }

        return 0;
    }
};
