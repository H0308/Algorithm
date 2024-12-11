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

// ����199.������������ͼ
// ���õ����������˼·
// ����ֻ��ӵ�ǰ������һ���ڵ�
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
                // ��ǰ�����һ���ڵ��������ͼ���Կ�����Ψһ�ڵ�
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
