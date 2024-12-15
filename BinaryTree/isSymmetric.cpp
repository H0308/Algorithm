//
// Created by 18483 on 2024/12/15.
//
#include <iostream>
#include <queue>

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

// ����101.�Գƶ�����
/*
 * �ж�һ�����Ƿ��ǶԳƶ���������Ҫ�Ƚ��������Ƿ���Է�תΪ��Ӧ��������
 * �����ж���������ֵ�Ƿ������������Ӧ��ֵ��������������������������࣬���������ڲ�������������ڲࣩ
 * ������Ķ�����Ϊ����
 *           1
 *     2           2
 * 3       4   4        3
 * �������˼·���£�
 *
 * 1->��->2->��->3
 *  ->��->2->��->3
 *  ��ȷ���true��2�ڵ�ĺ���ջ֡
 *        2->��->4
 *        2->��->4
 *  ��ȷ���true��2�ڵ�ĺ���ջ֡
 * ��������2����������2����true��1�ĺ���ջ֡
 *
 * ������Ĺ��̿��Է��֣���Ҫ���ж��������ĺ��Ӻ��������ĺ����Ƿ��Ӧһ��
 * ���Բ��õı���˳��ֻ���Ǻ��������У�����Ϊֻ�к�����������ȱ���������������ȡ��������ٱ������ڵ����ϲ㷵�ؽ��
 *
 * ������Ϊ��Ҫͬʱ��ȡ�����Ӻ��Һ��ӣ�����ʹ��һ�����ڵ�϶��ǲ����ģ����Ի���Ҫ�������һ���������ں����ڲ�ͬʱ������������
 * ��ʱ��ȷ���˺����Ĳ���Ϊ�������ֱ�����ڵ���ҽڵ㣬��Ϊֻ��Ҫ�жϽڵ��Ƿ���ȣ����Է���ֵΪ�������ͼ���
 * ���ſ��ǵݹ���ֹ������һ�������漸�������
 * 1. ��ڵ�Ϊ�գ��ҽڵ㲻Ϊ��->false
 * 2. ��ڵ㲻Ϊ�գ��ҽڵ�Ϊ��->false
 * 3. ��ڵ���ҽڵ㶼Ϊ��->true
 * 4. ��ڵ���ҽڵ��ֵ�����->false
 * ����4���е�ǰ������Ϊ���ų���ڵ���ҽڵ����Ϊ�յ����
 *
 * �����ǵ��㴦���߼���һ���ж�����ڵ���ҽڵ���ȣ��Ϳ������ϲ㷵�ؽ�����������˼·�еġ���������2����������2����true��1�ĺ���ջ֡��
 */
class Solution101_1
{
public:
    // ͬʱ�ж�������
    bool _isSymmetric(TreeNode *left, TreeNode *right)
    {
        // ��ֹ����
        if (!left && right || left && !right)
            return false;
        else if (!left && !right)
            return true;
        else if (left->val != right->val)
            return false;

        // �����������������
        bool outside = _isSymmetric(left->left, right->right);
        // ���������������ڲ�
        bool inside = _isSymmetric(left->right, right->left);

        // ���㴦���߼�
        return outside && inside;
    }

    bool isSymmetric(TreeNode *root)
    {
        if (!root)
            return true;
        return _isSymmetric(root->left, root->right);
    }
};

// ������
class Solution101_2
{
public:
    bool isSymmetric(TreeNode *root)
    {
        if (!root)
            return true;
        queue<TreeNode *> que;

        que.push(root->left);
        que.push(root->right);

        while (!que.empty())
        {
            TreeNode *left = que.front();
            que.pop();
            TreeNode *right = que.front();
            que.pop();
            if (!left && right || left && !right)
                return false;
            else if (!left && !right)
                continue;
            else if (left->val != right->val)
                return false;

            // �Ȳ������
            que.push(left->left);
            que.push(right->right);
            // �ٲ����ڲ�
            que.push(left->right);
            que.push(right->left);
        }

        return true;
    }
};
