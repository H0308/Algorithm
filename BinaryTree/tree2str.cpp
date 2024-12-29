//
// Created by 18483 on 2024/12/29.
//
#include <iostream>
#include <string>

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

// ����606.���ݶ����������ַ���
/*
 * ����˼·��������Ŀ���������Էֳ���������
 * 1. ��ǰ�ڵ�����Ӻ��Һ��Ӿ���Ϊ��ʱ���������벢��ȷ�պ�����
 * 2. ��ǰ�ڵ�����Ӳ�Ϊ�գ��Һ���Ϊ��ʱ���������벢��ȷ�պ�����
 * 3. ��ǰ�ڵ������Ϊ�գ������Һ��Ӳ�Ϊ��ʱ��������Ҫ��������Ŷԣ��ٲ����ҽڵ������
 */
class Solution606_1
{
public:
    void _tree2str(TreeNode *root, string &ret)
    {
        ret += "(" + to_string(root->val);
        if (!root->left && root->right)
            ret += "()";

        if (root->left)
            _tree2str(root->left, ret);

        if (root->right)
            _tree2str(root->right, ret);

        // ����������������Ϻ���������β
        ret += ")";
    }

    string tree2str(TreeNode *root)
    {
        if (!root)
            return "";

        string ret;
        // ����������ڵ�
        ret += to_string(root->val);

        if (root->left)
            _tree2str(root->left, ret);
        else if (!root->left && root->right)
            ret += "()";

        if (root->right)
            _tree2str(root->right, ret);

        return ret;
    }
};

/*
 * �������˼·��������ʵֻ��Ҫ�������һ�������Ҳ������Ϊ�գ������Ҳ�Ϊ��ʱ����Ҫ�������������������
 * ���Կ��Կ�����д������ȫ�����ŵ��߼���ʹ��if�������
 * ������ֻ��д���ϵĲ�ͬ��˼·����һ��
 * ���ǣ��ڶ���д�������������кܴ�Ӱ�죬��Ϊÿһ�εݹ鶼�ᴴ��һ���µ�string���󣬲�����ÿһ�η���ʱ����Ҫ���й��죬���¶����ʱ��Ϳռ�Ŀ���
 */
// д��2
class Solution606_2
{
public:
    string tree2str(TreeNode *root)
    {
        string ret;
        if (!root)
            return ret;

        // ����ڵ�ֵ
        ret += to_string(root->val);

        // ��������Ϊ�գ���������������������
        // ������Ϊ�գ�����������Ϊ�գ�������������
        if (root->left || root->right)
        {
            ret += "(";
            if (root->left)
                ret += tree2str(root->left);
            ret += ")";
        }

        // ��������Ϊ��ʱ����������������������
        if (root->right)
        {
            ret += "(";
            ret += tree2str(root->right);
            ret += ")";
        }

        return ret;
    }
};
