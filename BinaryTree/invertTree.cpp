//
// Created by 18483 on 2024/12/14.
//
#include <iostream>
#include <stack>
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

// ����226.��ת������
/*
 * ����Ļ���˼·���Ǳ�������������ת��ǰ�ڵ�����Һ��ӽڵ�
 * �ؼ����������ʹ����һ�ֵݹ鷽ʽ
 * ���ȿ�����ֱ�۵�˼·���Ȼ�ȡ����ڵ���ҽڵ��ٽ��н���
 * ���������˼·���Կ�������ȡ����ڵ���ҽڵ���ǵݹ�����������Ĺ���
 * �������ڵ���ǵ���ݹ麯����Ҫ������߼�
 * �����������һ���������
 *
 * ������˼·���£�
 *
 * ������Ķ�����Ϊ��
 *        4                              4
 *    2        7         -->        7          2
 * 1     3  6      8          8         6  3        1
 *
 * ������������������£�
 *
 * 4->��->2->��->1->��->nullptr������nullptr��1�ĺ���ջ֡��
 *              1->��->nullptr������nullptr��1�ĺ���ջ֡��
 *              ��������ң����ص�ǰ��1�ڵ㵽2�ĺ���ջ֡��
 *        2->��->3->��->nullptr������nullptr��3�ĺ���ջ֡��
 *               3->��->nullptr������nullptr��3�ĺ���ջ֡��
 *               ��������ң����ص�ǰ3�ڵ㵽2�ĺ���ջ֡��
 *        ����1��3�����ص�ǰ2�ڵ㵽4�ĺ���ջ֡��
 *        ���ˣ�������������ȫ����ת���
 * 4->��->7->��->6->��->nullptr������nullptr��6�ĺ���ջ֡��
 *              6->��->nullptr������nullptr��6�ĺ���ջ֡��
 *              ��������ң����ص�ǰ6��7�ĺ���ջ֡��
 *        7->��->8->��->nullptr������nullptr��8�ĺ���ջ֡��
 *               8->��->nullptr������nullptr��8�ĺ���ջ֡��
 *               ��������ң�����8��7�ĺ���ջ֡��
 *        ��������ң�����7��4�ĺ���ջ֡��
 *        ���ˣ�������������ȫ����ת���
 * ��������ң�����4��������
 * ���ˣ���������ת���
 */
// �������������ʹ��swap
class Solution226_1_1
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        if (root == nullptr)
            return nullptr;

        TreeNode *left = invertTree(root->left);
        TreeNode *right = invertTree(root->right);

        // ���㺯�������߼�
        root->left = right;
        root->right = left;

        return root;
    }
};

// �����������ʹ��swap
// ʹ��swap�Ͳ�����ʹ�ñ�����¼���ҽڵ㣬���򽻻����Ǿֲ�����
class Solution226_1_2
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        if (root == nullptr)
            return nullptr;

        invertTree(root->left);
        invertTree(root->right);

        // ���㺯�������߼�
        swap(root->left, root->right);

        return root;
    }
};

// ǰ�����
/*
 * ���ſ�����ǰ����������н��з�ת
 * ǰ����������У��ȴ���ǰ�ڵ��ٻ�ȡ���ҽڵ�
 * ���ʺͺ����������һ�£�ֻ�������Ƚ����ٱ���֮��������ٽ���
 */
class Solution226_2_1
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        if (root == nullptr)
            return nullptr;

        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};

// �������
/*
 * ����Ҳ���Կ���ʹ�����������������Ҫע�����
 * ���������˳���������ң��ڱ�����Ҳ�����ȱ�������ڵ㣬���žͽ��н���
 * �����ڽ�����������������ʱ��Ͳ��ѷ��֣���һ�������Ѿ���ԭ������ڵ���ҽڵ�����˽���
 * ��ʱ������������ԭ����������������ٽ��н����ͻ�ص�ԭ����������ʽ
 * ������һ�α������ܱ�����������Ӧ�ü�������������
 */
class Solution226_3
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        if (root == nullptr)
            return nullptr;

        invertTree(root->left);
        swap(root->left, root->right);
        invertTree(root->left);

        return root;
    }
};

// ����д��������ǰ��Ϊ��
class Solution226_2_2
{
public:
    TreeNode *invertTree(TreeNode *root)
    {

        stack<TreeNode*> st;

        st.push(root);
        while(!st.empty() && root != nullptr)
        {
            TreeNode* cur = st.top();
            st.pop();
            swap(cur->left, cur->right);
            if(cur->left)
                st.push(cur->left);
            if(cur->right)
                st.push(cur->right);
        }

        return root;
    }
};

// �������
class Solution226_4
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        queue<TreeNode*> que;

        que.push(root);
        while(!que.empty() && root != nullptr)
        {
            int count = que.size();
            while(count--)
            {
                TreeNode* cur = que.front();
                que.pop();
                swap(cur->left, cur->right);
                if(cur->left)
                    que.push(cur->left);
                if(cur->right)
                    que.push(cur->right);
            }
        }

        return root;
    }
};