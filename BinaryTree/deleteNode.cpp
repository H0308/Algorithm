//
// Created by 18483 on 2024/12/25.
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

// ����450.ɾ�������������еĽڵ�
class Solution450
{
public:
    // �жϲ��ҵĽڵ��Ƿ������BST��
    bool find(TreeNode *root, int key)
    {
        TreeNode *cur = root;
        while (cur)
        {
            // ��ǰ�ڵ�ƫ����������
            if (cur->val > key)
                cur = cur->left;
            else if (cur->val < key) // ��ǰ�ڵ�ƫС����������
                cur = cur->right;
            else
                return true; // �ҵ�����true
        }

        return false; // ѭ������˵��û�ҵ�
    }
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        // ���ڵ�Ϊ�ղ�ִ�л��߲�����ָ����key�򷵻ؿ�ɾ��
        if (!root)
            return nullptr;

        if (!find(root, key))
            return root;

        // �Ȳ��ҵ�ָ���ڵ�
        TreeNode *cur = root;
        TreeNode *prev = prev;

        while (cur)
        {
            // ��¼��ǰ�ڵ�
            if (cur->val > key)
            {
                // ע��prev��λ��Ҫ��if����
                // ��ֹ������һ��curΪ��ɾ���Ľڵ�ʱ��prevҲ����˵�ǰ��ɾ���Ľڵ�
                prev = cur;
                cur = cur->left;
            }
            else if (cur->val < key)
            {
                prev = cur;
                cur = cur->right;
            }
            else // ���ʱִ��ɾ��
            {
                // ��һ�ֺ͵ڶ������
                // �����ǰ�ڵ������Ϊ��
                if (!cur->left)
                {
                    // ע����ڵ�Ϊ��ɾ������ֵʱ��Ҫ��������
                    if(cur == root)
                        root = cur->right;
                    else if (prev->left == cur) // �жϵ�ǰ�ڵ����丸�׽ڵ�����ӻ����Һ���
                        prev->left = cur->right;
                    else if (prev->right == cur)
                        prev->right = cur->right;
                    delete cur;
                }
                else if (!cur->right)
                {
                    // ע����ڵ�Ϊ��ɾ������ֵʱ��Ҫ��������
                    if(cur == root)
                        root = cur->left;
                    else if (prev->left == cur)
                        prev->left = cur->left;
                    else if (prev->right == cur)
                        prev->right = cur->left;
                    delete cur;
                }
                else
                {
                    // ���������
                    // ���ҵ���ɾ���ڵ���Һ��ӵ�������
                    TreeNode *replaceNode = cur->right;
                    TreeNode *replaceNodePrev = cur;

                    while (replaceNode->left)
                    {
                        replaceNodePrev = replaceNode;
                        replaceNode = replaceNode->left;
                    }

                    // ����ɾ���ڵ��ֵ�滻Ϊ�Һ��ӵ������ӵ�ֵ
                    cur->val = replaceNode->val;
                    if (replaceNode == replaceNodePrev->left)
                        replaceNodePrev->left = replaceNode->right;
                    else if (replaceNode == replaceNodePrev->right)
                        replaceNodePrev->right = replaceNode->right;

                    delete replaceNode;
                }
                break;
            }
        }

        return root;
    }
};