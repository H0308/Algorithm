//
// Created by 18483 on 2024/12/16.
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

// ����222.��ȫ�������Ľڵ����
// �������
// ��ͨ�������Ľⷨ����ֱ�ӱ������нڵ��ۼ�
class Solution222_1
{
public:
    int countNodes(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        int leftNum = countNodes(root->left);
        int rightNum = countNodes(root->right);

        return leftNum + rightNum + 1;
    }
};

// ��ȫ�������Ľⷨ�����������ȫ��������ǰ���»�������������ֱ�Ӱ��չ�ʽ����
class Solution222_2
{
public:
    int countNodes(TreeNode *root)
    {
        if (!root)
            return 0;

        // ����������ʱֱ�ӷ���2^���-1
        // �����������������������˵����ǰ��������������������ȫ������Ϊǰ�ᣩ
        int leftHeight = 0;
        int rightHeight = 0;
        TreeNode *leftNode = root->left;
        TreeNode *rightNode = root->right;
        while (leftNode)
        {
            leftHeight++;
            leftNode = leftNode->left;
        }
        while (rightNode)
        {
            rightHeight++;
            rightNode = rightNode->right;
        }

        if (leftHeight == rightHeight)
        {
            // ˵������������
            // ע���������ȼ�
            return (2 << leftHeight) - 1;
        }

        // ����ʣ������
        leftHeight = countNodes(root->left);
        rightHeight = countNodes(root->right);

        return leftHeight + rightHeight + 1;
    }
};