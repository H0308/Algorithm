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

// ����94.���������������
// �ݹ�д��
class Solution94_1
{
public:
    void _inorderTraversal(TreeNode *cur, vector<int> &ret)
    {
        if (cur == nullptr)
            return;

        _inorderTraversal(cur->left, ret);
        ret.push_back(cur->val);
        _inorderTraversal(cur->right, ret);
    }

    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ret;
        _inorderTraversal(root, ret);

        return ret;
    }
};

// ����д��
// ����ĵ����������
// ���ҵ�����������ȡ����ǰ�ڵ�
// ȡ����ڵ����һ���ڵ�һ���Ǹ��ڵ�
// ����ֻ��Ҫ��root����Ϊnullptr�Ϳ��Է�ֹ�ظ��ߵ�ԭ���Ľڵ�
// ���ǵ������ڵ���Ҷ�ӣ���ô��ʱroot->rightһ��Ϊnullptr
// ���Կ��Ը���Ϊroot = root->right����������ҽڵ㣬����һ���ֻ����Ҳ������ظ�ǰ��Ĳ���
// ����������ҽڵ㣬����һ��ȡ���ľ��Ǹ��ڵ�
class Solution_2
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> st;
        vector<int> ret;

        TreeNode *prev = nullptr;

        while (!st.empty() || root != nullptr)
        {
            // ���ҵ�����ڵ�
            while (root)
            {
                st.push(root);
                root = root->left;
            }

            // ��ȡ��ǰ�ڵ�
            root = st.top();
            st.pop();
            ret.push_back(root->val);

            // �����Ƿ�Ϊ�ն�Ҫ����������һ����Ϊ�գ���һ�ξͻ�ȡ����ǰ�����ĸ��ڵ�
            root = root->right;
        }

        return ret;
    }
};