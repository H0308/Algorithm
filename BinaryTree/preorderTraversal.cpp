//
// Created by 18483 on 2024/12/10.
//
#include <iostream>
#include <vector>
#include <stack>

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

// ����144.��������ǰ�����
// �ݹ�д��
class Solution144_1
{
public:
    void _preorderTraversal(TreeNode *root, vector<int> &ret)
    {
        if (root == nullptr)
            return;

        // ����ڵ�
        ret.push_back(root->val);
        _preorderTraversal(root->left, ret);
        _preorderTraversal(root->right, ret);
    }

    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> ret;
        _preorderTraversal(root, ret);
        return ret;
    }
};

// ����д��
// ����д������Ҫ˼·������ջģ��ݹ�Ĺ���
// ǰ�������˳���ǣ�������
// ���Ը��ڵ��ǵ�һ��������Ľڵ�
// ����ջ�ڵ����ݾ��ǵ�ǰ�����ĸ��ڵ�
// ���ջ��Ϊ��˵����û���������ö�����
// ÿһ�α���ʱ����ȡ����ǰջ����Ԫ�أ���Ԫ�ؾ��ǵ�ǰ�����ĸ��ڵ㣬ȡ���󵯳���ǰԪ��
// ����������������ע�ⲻ������������Ϊջ���Ƚ����������һ�����������ȱ�ȥ��
// �����������Ƚ����ܱ�֤��������ջ��
class Solution_2
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        // ��ջģ��
        stack<TreeNode *> st;
        // �Ȳ�����ڵ�
        st.push(root);
        vector<int> ret;

        while (!st.empty())
        {
            // ��ȡջ���ڵ�
            TreeNode *cur = st.top();
            st.pop();
            // �����߼�
            if (cur != nullptr)
                ret.push_back(cur->val);
            else
                continue;

            // �Ȳ����ҽڵ�
            st.push(cur->right);
            // �ٲ�����ڵ�
            st.push(cur->left);
        }

        return ret;
    }
};