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

// ����236.�������������������
/*
 * ����˼·��
 * 1. ͬһ�������д���p��q�����ʱp����q����һ�������ǹ�������
 * 2. ��ͬ�����д���p��q�����ʱ���ߵĹ������׾��ǹ�������
 *
 * �������ڵ�������ݱ�Ϊ����ж���һ�������£�
 * 1. �����p���ҵ�q����˵��p�ǹ������ȣ�����q�ǹ�������
 * 2. ���p��q����Ҷ�ӽڵ㣬�������ǵĹ�������
 *
 * �����д������Ҫע�ⷵ��ֵ�Ŀ��ƣ���������з���ֵ��������Ҫ���Ϸ����������ֵ�ͱ�����ܺ����ķ���ֵ�����䷵��
 */
class Solution236_1
{
public:
    // �ж��Ƿ���ͬһ��������
    bool isUnder(TreeNode *root, TreeNode *target)
    {
        if (!root)
            return false;

        if (root->val == target->val)
            return true;
        // �ڸ��������ҵ��˾ͷ���true
        return isUnder(root->left, target) || isUnder(root->right, target);
    }

    // �������ҽڵ�
    TreeNode *traversal(TreeNode *root, TreeNode *target)
    {
        if (!root)
            return nullptr;

        if (root->val == target->val)
            return root;

        TreeNode *left = traversal(root->left, target);
        TreeNode *right = traversal(root->right, target);

        if (left)
            return left;

        if (right)
            return right;

        return nullptr;
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        // �ҵ������ڵ�
        TreeNode *node1 = traversal(root, p);
        TreeNode *node2 = traversal(root, q);

        // �ж�p��q�Ƿ���ͬһ��������
        if (isUnder(node1, node2)) // q��p��������
            return p;
        else if (isUnder(node2, node1)) // p��q��������
            return q;

        // ����Ȳ���qҲ����p��ֱ�Ӷ��߹��еĸ��׽ڵ�
        // ˼·���£�
        // �Ӹ��ڵ㿪ʼ�����������cur->left���ҵ���node1��node2��˵��node1��node2��cur����������
        // �������±�����ֱ��cur->left������node1��node2����ʱcur���ǹ��еĸ��׽ڵ�
        // �����cur->right���ҵ���node1��node2��˵��node1��node2��cur����������
        // �������±�����ֱ��cur->right������node1��node2����ʱcur���ǹ��еĸ��׽ڵ�
        TreeNode *cur = root;
        while (cur)
        {
            if (isUnder(cur->left, node1) && isUnder(cur->left, node2))
                cur = cur->left;
            else if (isUnder(cur->right, node1) && isUnder(cur->right, node2))
                cur = cur->right;
            else
                break;
        }

        return cur;
    }
};

// д��2
/*
 * ˼·����һ�£����ҵ���������Ⱦ�һֱ���Ϸ���
 * ���������˼·�����������������˵������������е㸴�ӣ������д���������ڴ���һ�������ͬʱ������p����qΪ����������ȵ����
 * ��Ϊ���2�ı��ʾ���p��q��p����q�������£���ô�ڱ����������Ĺ����У�һ�������Ȳ��ҵ�p����q����ʱ�ͻ᷵��p����q
 * ��Ϊp����qһֱ��q����p�ĺ��ӣ������ڷ���left����rightʱ��ֻ���ߵڶ��ֺ͵�����if��֧
 */
class Solution236_2
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        // �����ǰ�ڵ�Ϊp����q����ֱ�ӷ��ص�ǰ�ڵ�
        if (root == p || root == q || root == nullptr)
            return root;

        // �������
        // ��������������p��q������ҵ���p�ͻ�һֱ���Ϸ��ض����������q
        // ����һ���������p����q����������������ȣ���˵��p��q���������ͬһ��·����
        // ����Ҳ�Ͳ�����ֱ���������������������������ͬһ��ֵp����q
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        // ������������p��q
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        // ����
        // ������Ӳ�Ϊ�գ��Һ���Ҳ��Ϊ�գ�˵����ǰ����ջ֡��root��ֵ���������������
        if (left && right)
            return root;
        else if (!left && right) // �����Ϊ�գ��Ҳ�Ϊ�գ�˵����û���ҵ�����������ȣ�ֻ�ҵ���һ�������ĸ�
            return right;
        else if (left && !right) // ͬ��������
            return left;

        return nullptr;
    }
};

// ����235.�����������������������
// д��1
/*
 * �������ֱ��ʹ������Ĵ�����ɣ���Ϊ��������������Ҳ�Ƕ�����
 */
class Solution235_1
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == p || root == q || root == nullptr)
            return root;

        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        // ������Ӳ�Ϊ�գ��Һ���Ҳ��Ϊ�գ�˵����ǰ����ջ֡��root��ֵ���������������
        if (left && right)
            return root;
        else if (!left && right) // �����Ϊ�գ��Ҳ�Ϊ�գ�˵����û���ҵ�����������ȣ�ֻ�ҵ���һ�������ĸ�
            return right;
        else if (left && !right) // ͬ��������
            return left;

        return nullptr;
    }
};

// д��2
/*
 * ���ö��������������ԣ����������нڵ��С�ڸ��ڵ㣬���������нڵ�����ڸ��ڵ���Էֳ���������������
 * 1. ��ǰ�ڵ����p��q��˵���������������������
 * 2. ��ǰ�ڵ�С��p��q��˵���������������������
 * 3. ��ǰ�ڵ����p��q��˵����ǰ�ڵ���������������
 *
 * ע�⣬������֡���ǰ�ڵ����p��q��˵����ǰ�ڵ㲻������������ȡ������
 * ��Ϊһ����ǰ�ڵ����p��q����������һ��С�ڵ�ǰ�ڵ㣬������һ�����ڵ�ǰ�ڵ�
 * ��ô��ǰ�ڵ㲻������������������ұ���������ִ��һ���ڵ�����
 */
class Solution235_2
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (!root)
            return root;

        // �����ǰ�ڵ��ֵ��pֵ��qֵ֮�䣬��˵��һ��������������ȣ���Ϊ���p��q����ͬһ������
        // ��ô���ݶ�������������ͻ���֣�
        // 1. p��q���ڵ�ǰ�ڵ����
        // 2. p��q���ڵ�ǰ�ڵ��Ҳ�

        // ��ǰ�ڵ��p��q������������������
        if (root->val > p->val && root->val > q->val)
        {
            TreeNode *left = lowestCommonAncestor(root->left, p, q);
            if (left)
                return left;
        }

        // ��ǰ�ڵ��p��q��С����������������
        if (root->val < p->val && root->val < q->val)
        {
            TreeNode *right = lowestCommonAncestor(root->right, p, q);
            if (right)
                return right;
        }

        // �����������������if��˵����ǰ�ڵ����p��q�м䣬��Ϊ�����������
        return root;
    }
};
