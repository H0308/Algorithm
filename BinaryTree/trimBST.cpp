//
// Created by 18483 on 2024/12/27.
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

// ����669.�޼�����������
/*
 * ���ⲻ����ʹ�ö�����ɾ���ڵ���߼�����Ϊ��Ŀ�ᵽ�˲����޸Ķ������ĸ��ӹ�ϵ�����ڶ�����ɾ���ڵ�Ĺ����л��漰��Ų���ڵ�
 * �Ӷ����¸��ӹ�ϵ�ı�
 * ������Կ�����ֱ�۵�������������ĿҪ�����ɾ���ڵ�
 * �����ǰ�ڵ㲻��Ҫ���[low, high]�У����ҵ����Ӧ����������������
 * 1. �����ǰ�ڵ�С��low����Ϊ�Ƕ�������������������������ȫ���ڵ�һ��ҲС��low����ʱֻ��Ҫ���������ݹ��ж��ҵ�������������������
 * 2. �����ǰ�ڵ����high����Ϊ�Ƕ�������������������������ȫ���ڵ�һ��Ҳ����high����ʱֻ��Ҫ���������ݹ��ж��ҵ�������������������
 */
class Solution669
{
public:
    TreeNode *trimBST(TreeNode *root, int low, int high)
    {
        // ����ڵ�Ϊ�գ�ֱ�ӷ��ؿ�
        if (!root)
            return nullptr;

        // �����ǰ�ڵ�С��low����Ϊ�Ƕ�������������������������ȫ���ڵ�һ��ҲС��low
        // ��ʱֻ��Ҫ���������ݹ��ж��ҵ�������������������
        if (root->val < low)
            return trimBST(root->right, low, high); // ֱ�ӷ�����������ǰ�ڵ�ĸ��׽ڵ��൱��ɾ����ǰ�ڵ�
        else if (root->val > high) // �����������
            return trimBST(root->left, low, high);

        // ��������
        // ��������������������˵����ǰ�ڵ���[low, high]֮�ڣ��������±���
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);

        return root;
    }
};
