//
// Created by 18483 on 2024/12/11.
//
#include <iostream>
#include <vector>
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

// ����515.��ÿ�������������ֵ
// ��������ҳ����ֵ����
class Solution
{
public:
    vector<int> largestValues(TreeNode* root)
    {
        int count = 0;

        vector<int> ret;

        queue<TreeNode*> que;
        que.push(root);

        while(!que.empty() && root != nullptr)
        {
            count = que.size();

            // ������ڸ�������ʼֵ������Ϊ0
            // ����ǰ��ȫ�Ǹ���������޷��ҵ����ֵ
            int maxVal = INT_MIN;
            while(count--)
            {
                TreeNode* cur = que.front();
                que.pop();

                maxVal = max(maxVal, cur->val);

                if(cur->left)
                    que.push(cur->left);

                if(cur->right)
                    que.push(cur->right);
            }
            ret.push_back(maxVal);
        }

        return ret;
    }
};