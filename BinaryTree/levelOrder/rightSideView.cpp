//
// Created by 18483 on 2024/12/11.
//
#include <iostream>
#include <queue>
#include <vector>

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

// 力扣199.二叉树的右视图
// 利用到层序遍历的思路
// 但是只添加当前层的最后一个节点
class Solution
{
public:
    vector<int> rightSideView(TreeNode *root)
    {
        int count = 0;
        vector<int> ret;

        queue<TreeNode *> que;
        que.push(root);

        while (!que.empty() && root != nullptr)
        {
            count = que.size();
            while (count)
            {
                TreeNode *cur = que.front();
                que.pop();
                count--;
                // 当前层最后一个节点就是右视图可以看到的唯一节点
                if (count == 0)
                    ret.push_back(cur->val);

                if (cur->left)
                    que.push(cur->left);
                if (cur->right)
                    que.push(cur->right);
            }
        }

        return ret;
    }
};
