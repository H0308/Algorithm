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
class Solution
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
