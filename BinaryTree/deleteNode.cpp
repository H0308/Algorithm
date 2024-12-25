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
        TreeNode *prev = nullptr;

        while (cur)
        {
            prev = cur;
            if (cur->val > key)
            {
                cur = cur->left;
            }
            else if (cur->val < key)
            {
                cur = cur->right;
            }
            else // ���ʱִ��ɾ��
            {
                // ���ɾ���Ľڵ�ֻ��һ�����ӣ���ôֱ���ø������Ӹú��Ӽ���
                // �ҵ���ɾ��
                if (cur->right == nullptr)
                {
                    // ���Ǹ��ڵ�����
                    if (cur == root)
                    {
                        root = cur->left;
                    }
                    else
                    {
                        if (prev->right == cur)
                        {
                            prev->right = cur->left;
                        }
                        else if (prev->left == cur)
                        {
                            prev->left = cur->left;
                        }
                    }
                    delete cur;
                    break;
                }
                else if (cur->left == nullptr)
                {
                    // ���Ǹ��ڵ�����
                    if (cur == root)
                    {
                        root = cur->right;
                    }
                    else
                    {
                        // �ҵ����ӵ�λ�ú�����
                        if (prev->left == cur)
                        {
                            prev->left = cur->right;
                        }
                        else if (prev->right == cur)
                        {
                            prev->right = cur->right;
                        }
                    }
                    delete cur;
                    break;
                }
                else
                {
                    // �������ӽڵ�
                    // �ҳ��ʺϵ�����ڵ㣬ѡ����������������
                    TreeNode *replaceNodeP = cur;
                    TreeNode *replaceNode = cur->right;

                    // һֱ����������ֱ���ҵ�����ڵ�
                    while (replaceNode->left)
                    {
                        replaceNodeP = replaceNode;
                        replaceNode = replaceNode->left;
                    }

                    // ��replaceNode��ֵ������Ҫɾ���Ľڵ�
                    cur->val = replaceNode->val;
                    // ��replaceNode�ĸ���ָ���滻�ڵ�ĺ���
                    if (replaceNodeP->left == replaceNode)
                    {
                        // �ҵ�������������ڵ㣬һ��û������
                        replaceNodeP->left = replaceNode->right;
                    }
                    else
                    {
                        // replaceNodeP���ɾ���ڵ�ʱͬһ���ڵ�
                        replaceNodeP->right = replaceNode->right;
                    }
                    delete replaceNode;
                    break;
                }
            }
        }

        return root;
    }
};
