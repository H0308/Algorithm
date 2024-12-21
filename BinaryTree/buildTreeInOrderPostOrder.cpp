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

// ����106.�����������������й��������
/*
 * ����˼·�����ݺ�������ҳ����ڵ㣬�ٸ��ݸ��ڵ�ֱ��и�ǰ���������ͺ�����������ظ����ú���ֱ������Ϊ��ʱ����������
 */
class Solution106
{
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        if (postorder.size() == 0)
            return nullptr;
        // 1. ���ݺ��������ȡ���ڵ�
        int rootVal = postorder[postorder.size() - 1];
        TreeNode *root = new TreeNode(rootVal);

        // 2. ���ݸ��ڵ��������з����������������������
        int rootIndex = 0;
        for (int i = 0; i < inorder.size(); i++)
        {
            if (inorder[i] == rootVal)
            {
                rootIndex = i;
                break;
            }
        }

        // ����ҿ�ԭ��ָ�
        vector<int> inorderLeft(inorder.begin(), inorder.begin() + rootIndex);
        vector<int> inorderRight(inorder.begin() + rootIndex + 1, inorder.end());

        // 3. ���ݸ��ڵ��ں����з����������������������
        // ����ȥ��������һ��Ԫ��
        postorder.resize(postorder.size() - 1);
        // ����ҿ�ԭ��ָ�
        vector<int> postorderLeft(postorder.begin(), postorder.begin() + inorderLeft.size());
        vector<int> postorderRight(postorder.begin() + inorderLeft.size(), postorder.end());

        // 4. �������к�������к��Һ��ظ���������
        root->left = buildTree(inorderLeft, postorderLeft);
        root->right = buildTree(inorderRight, postorderRight);

        // 5. ���ظ��ڵ�
        return root;
    }
};
