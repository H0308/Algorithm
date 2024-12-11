//
// Created by 18483 on 2024/12/11.
//
#include <iostream>
#include <algorithm>
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

// ����107.�������Ĳ��������
// ����102��Ĵ�����Ͻ������ת����
class Solution
{
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        // ��¼��ǰ��ڵ�ĸ���
        int count = 0;
        vector<vector<int>> ret;

        queue<TreeNode *> que;

        que.push(root);
        while (!que.empty() && root != nullptr)
        {
            count = que.size();
            // �洢��ǰ��Ľڵ�
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

        reverse(ret.begin(), ret.end());

        return ret;
    }
};
