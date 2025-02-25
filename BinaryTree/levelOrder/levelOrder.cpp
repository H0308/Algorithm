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

// 力扣102.二叉树的层序遍历
class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        // 记录当前层节点的个数
        int count = 0;
        vector<vector<int>> ret;

        queue<TreeNode *> que;

        que.push(root);
        while (!que.empty() && root != nullptr)
        {
            count = que.size();
            // 存储当前层的节点
            vector<int> temp;

            while (count--)
            {
                TreeNode *cur = que.front();
                que.pop();
                temp.push_back(cur->val);

                if (cur->left)
                    que.push(cur->left);
                if (cur->right)
                    que.push(cur->right);
            }

            ret.push_back(temp);
        }

        return ret;
    }
};
