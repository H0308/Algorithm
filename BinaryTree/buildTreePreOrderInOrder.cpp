//
// Created by 18483 on 2024/12/21.
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

// ����105.��ǰ��������������й��������
/*
 * ���������˼·����һ�£�ֻ��ʹ�õ����鲻ͬ����
 * ע�⣬����ʹ��ǰ����ߺ���+���򹹽������������ǲ���ʹ��ǰ��+���򹹽�����������Ϊ��ʱ�����Ķ�������Ψһ
 */
class Solution105
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        // ��������������Ч��
        if (preorder.size() == 0)
            return nullptr;

        // ��ȡ���ڵ�ֵ
        int rootVal = preorder[0];
        TreeNode *root = new TreeNode(rootVal);

        // ����������в��Ҹ��ڵ�λ��
        int rootIndex = -1;
        for (int i = 0; i < inorder.size(); i++)
        {
            if (inorder[i] == rootVal)
            {
                rootIndex = i;
                break;
            }
        }

        // �ָ��������� - ������
        vector<int> inorderLeft(inorder.begin(), inorder.begin() + rootIndex);
        // �ָ��������� - ������
        vector<int> inorderRight(inorder.begin() + rootIndex + 1, inorder.end());

        // �ָ�ǰ������ʱȷ������Խ��
        if (inorderLeft.size() > preorder.size() - 1)
            return nullptr;

        // �ָ�ǰ������ - ������
        vector<int> preorderLeft(preorder.begin() + 1,preorder.begin() + 1 + inorderLeft.size());
        // �ָ�ǰ������ - ������
        vector<int> preorderRight(preorder.begin() + 1 + inorderLeft.size(),preorder.end());

        // �ݹ鹹����������
        root->left = buildTree(preorderLeft, inorderLeft);
        root->right = buildTree(preorderRight, inorderRight);

        return root;
    }
};
