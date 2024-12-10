//
// Created by 18483 on 2024/12/10.
//
#include <iostream>
#include <vector>
#include <algorithm>
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

// ����145.�������ĺ������
// �ݹ�
class Solution145_1
{
public:
    void _postOrderTraversal(TreeNode *cur, vector<int> &ret)
    {
        if (cur == nullptr)
            return;

        // ������ڵ�
        _postOrderTraversal(cur->left, ret);
        // �����ҽڵ�
        _postOrderTraversal(cur->right, ret);
        // ����ǰ�ڵ�
        ret.push_back(cur->val);
    }

    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> ret;
        _postOrderTraversal(root, ret);

        return ret;
    }
};

// ����д��1
// ԭ�������ϵ�������
class Solution145_2_1
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> ret;
        // ʹ��ջģ��
        stack<TreeNode *> st;
        // ���ڵ�Ϊ��ֱ�ӷ��ؿ�
        if (root == nullptr)
            return ret;

        // ��ֹ������������ѭ��
        TreeNode *prev = nullptr;
        while (!st.empty() || root != nullptr)
        {
            // һֱ�ҵ�����ڵ�
            while (root)
            {
                // ��ѭ�����Ѿ�����һ�θ��ڵ�
                // ��ʱѭ���ϵ��ж�root!=nullptr���Է�ֹ������ͬ�ĸ��ڵ�ͬʱ����ջ��
                st.push(root);
                root = root->left;
            }

            // ��ȡ����ǰ�ڵ�
            root = st.top();
            st.pop();

            // �����ǰ�ڵ㲻����������
            // �����Ѿ���ȡ��ͬһ��������
            // ˵���Ѿ�������ɣ���ǰ�ڵ�����������ڵ�
            if (root->right == nullptr || root->right == prev)
            {
                ret.push_back(root->val);
                prev = root;
                // ��root��Ϊ�շ�ֹ��һ�λ�ȡ����ڵ�
                root = nullptr;
            }
            else
            {
                // �����������ͻ���Ҫ������
                st.push(root); // �������ĸ��ڵ��ٲ��뵽ջ��
                // ��ʱ�϶������ڻ����Ѿ��ж���������������ֱ������������
                root = root->right;
            }
        }

        return ret;
    }
};

// ����д��2����Ͷ��ȡ��
// ����ĵ���д��ʵ���Ͼ��ǡ������󡹵ķ��������С�
// ����ֻ��Ҫ��ǰ������ġ������ҡ���Ϊ�������󡹣��ٷ�����������
// ����ע�⣬�������ֻ������˱����Ľ���������ķ����������ǲ�̫�Ͻ���
// ����˵���칹��ǰ������������������η�ת���ȷ�תΪ�������ٷ�ת�������
class Solution145_2_2
{
public:
    vector<int> postorderTraversal(TreeNode *root)
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

            // ������
            // �Ȳ�����ڵ�
            st.push(cur->left);
            // �ٲ����ҽڵ�
            st.push(cur->right);
        }

        reverse(ret.begin(), ret.end());

        return ret;
    }
};
