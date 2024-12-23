//
// Created by 18483 on 2024/12/23.
//
#include <iostream>
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

// ����98.��֤����������
// ����ռ�
/*
 * ������ֱ�ӵ�˼·���Ǹ�����Ŀ�����Ĺ���ģ�⣬���ǲ��ܽ���ֻ�жϵ��������Ƿ�������������������������������һ������
 *
 *       5
 *   4      6
 *        3    7
 * ��������ڵ�Ϊ5������������4��4<5��������Ϊ6��6>5����ǰ�����������������������
 * �ٿ����ڵ�Ϊ6��������������Ϊ3��3<6��������Ϊ7��7>6����ǰ�����������������������
 * ���Ƕ������������˽С��������������С�����������������������Ľ����һ����������
 * �����ԣ���ǰ�������������������������45367�����������������ص㣬�����䲻�Ƕ���������
 * ͨ����������ӿ��Կ��ɣ�����ֻ�ж�ÿһ�������Ƿ��Ƕ�����������һ����֤�������ͨ��
 * ��򵥵��������ǽ����������������������뵽�����У��ж������е�Ԫ���Ƿ��������������ô��ǰ�����Ƕ���������������Ͳ���
 */
class Solution98_1
{
public:
    void traversal(TreeNode* root, vector<int>& ret)
    {
        if(!root)
            return;

        traversal(root->left, ret);
        ret.push_back(root->val);
        traversal(root->right, ret);
    }

    bool isValidBST(TreeNode *root)
    {
        vector<int> ret;

        traversal(root, ret);

        for(int i = 0; i < ret.size() - 1; i++)
            if(ret[i] >= ret[i + 1])
                return false;

        return true;
    }
};

// ʹ��һ���ڵ��¼ǰһ���ڵ����ֵ���ڱ����������Ĺ�����ֱ�ӽ��бȽ�
class Solution98_2
{
public:
    TreeNode* pre = nullptr;
    bool isValidBST(TreeNode *root)
    {
        if(!root)
            return true;

        bool left = isValidBST(root->left);
        if(pre && pre->val >= root->val)
            return false;

        // ����preΪǰһ���ڵ�
        pre = root;
        bool right = isValidBST(root->right);

        return left && right;
    }
};
