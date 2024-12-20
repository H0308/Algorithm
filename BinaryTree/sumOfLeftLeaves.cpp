//
// Created by 18483 on 2024/12/20.
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

// ����404.��Ҷ��֮��
/*
 * ������ֱ�۵�˼·���Ǳ���������ʱ�ٴ������ӣ��������������һ���������������Һ���
 * ʵ���ϣ��������Ҫ�����������������⣬Ҳ��Ҫ�������������Һ��ӵ����ӡ������������Ӻ����������Һ��ӵ�����
 * ���Ա����˼·�ǣ�����������������ֻ���������ӵ����
 * �������ʵ��Ϊ����
 *            3
 *      9           20
 *  11     21    15      7
 *       5
 *
 * ������Ϊ��11+5+15=31
 * ����˼·Ϊ��
 * 3->��->9->��->11->��->nullptr������0��11�ĺ���ջ֡
 *               11->��->nullptr������0��11�ĺ���ջ֡
 *               ����0��9�ĺ���ջ֡
 *        �ж�11Ϊ9����Ҷ�ӣ�������Ҷ�ӽ��
 *        9->��->21->��->5->��->nullptr������0��5�ĺ���ջ֡
 *                      5->��->nullptr������0��5�ĺ���ջ֡
 *                      ����0��21�ĺ���ջ֡
 *              �ж�5Ϊ���ӣ��������ӽ��
 *              21->��->nullptr������0��21�ĺ���ջ֡
 *              ����5��9�ĺ���ջ֡
 *         ����16��3�ĺ���ջ֡
 * 3->��->20->��->15->��->nullptr������0��15�ĺ���ջ֡
 *               15->��->nullptr������0��15�ĺ���ջ֡
 *               ����0��20�ĺ���ջ֡
 *        �ж�15Ϊ20����Ҷ�ӣ�������Ҷ�ӽ��
 *        20->��->7->��->nullptr������0��7�ĺ���ջ֡
 *                7->��->nullptr������0��7�ĺ���ջ֡
 *                ����0��20�ĺ���ջ֡
 *        ����15��3�ĺ���ջ֡
 * ����31
 *
 *
 */
class Solution404
{
public:
    int sumOfLeftLeaves(TreeNode *root)
    {
        if (!root)
            return 0;
        if (!root->left && !root->right)
            // ���Ӻ��Һ��Ӷ���գ��޷��жϵ�ǰ����һ��Ϊ����
            // ����ֱ�ӷ���0����
            return 0;

        // ����������
        int leftNum = sumOfLeftLeaves(root->left);
        // �ж��Ƿ������ӣ��Ǿʹ���
        if (root->left && (!root->left->left && !root->left->right))
            leftNum = root->left->val;

        // ����������
        int rightNum = sumOfLeftLeaves(root->right);
        // ��Ȼ�����������������Һ��Ӷ���������

        return leftNum + rightNum;
    }
};