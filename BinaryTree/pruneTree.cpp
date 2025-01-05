//
// Created by 18483 on 2025/1/5.
//
#include <iostream>
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

// ����814.��������֦
/*
 * �����˼·�ܼ򵥣�������Ŀ������������������0��ΪҶ�ӽڵ㣬��ɾ���ýڵ㣬���򲻴���
 * ��ΪҪ�ж�һ���ڵ��Ƿ���Ҷ�ӽڵ㣬�ͱ����Ȼ�ȡ��������������Ϣ�����Ծ���Ҫ�������
 * ɾ���ڵ�����ϲ㷵�ؿգ��ϲ���Ҫʹ�ýڵ��left����right����
 * ע�⣬���ⲻҪʹ��delete������ʱһ��Ҫѯ�����Թ����Ľڵ��Ƿ����ڶ��Ͽ��ٵĿռ�
 */
class Solution814
{
public:
    TreeNode *pruneTree(TreeNode *root)
    {
        if (!root)
            return nullptr;

        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);

        if (!root->left && !root->right && root->val == 0)
        {
            // delete root; ע���Ƿ���Ҫ�ͷ��ڴ�Ҫ�����������һ��Ҫȷ���Ƿ����ڶ��Ͽ����Ŀռ䣩�����ⲻ���ͷ�
            return nullptr;
        }

        // ���Ϊ1�ͷ��ص�ǰ�����ĸ�
        return root;
    }
};