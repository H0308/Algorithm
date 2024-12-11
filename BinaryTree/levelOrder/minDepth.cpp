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


// ����111.����������С���
class Solution
{
public:
    int minDepth(TreeNode *root)
    {
        // ��ʼ��ʱ�߶�Ϊ1
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

                // �ҵ�һ��Ҷ�ӽڵ��ֱ�ӷ���
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
