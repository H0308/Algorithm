//
// Created by 18483 on 2024/12/18.
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

// ����257.������������·��
/*
 * ����˼·������һ���ڵ����temp����ýڵ㣬��¼��ǰ�ڵ㱻������
 * �������һ���ڵ�����Ϊ�գ��Һ���ҲΪ�գ���һ����Ҷ�ӽڵ㣬��ʱ��Ҫ��temp�е��ַ����ι���·���ַ������뵽�������
 * ������ɺ���Ҫ������ǰ��Ҷ�ӣ���������������
 * ϸ�ڣ������ǰ��������������ô��Ҫ��������temp�е����һ��Ԫ�أ�������Ҫ�������߼�������Ϊһ����䣬��Ϊ���Ϸ���ǰһ��Ҫִ�е����
 *
 * ������Ķ�����Ϊ��
 *
 *       1
 *    2     3
 *  4   5
 *
 *  �������["1->2->4", "1->2->5", "1->3"]
 *  ����˼·���£�
 *  1->��->2->��->4->��->nullptr�����ص�4�ĺ���ջ֡��temp=["1", "2", "4"]
 *               4->��->nullptr�����ص�4�ĺ���ջ֡
 *               �ж�4���Ҿ�Ϊ�գ�˵����Ҷ�ӽڵ㣬��ʱ��temp�е����ݹ��ɽ����1->2->4
 *               �������һ��Ԫ�ء�temp=["1", "2"]
 *               ���ص�2�ĺ���ջ֡
 *         2->��->5->��->nullptr�����ص�5�ĺ���ջ֡��temp=["1", "2", "5"]
 *                5->��->nullptr�����ص�5�ĺ���ջ֡
 *                �ж�5���Ҿ�Ϊ�գ�˵����Ҷ�ӽڵ㣬��ʱ��temp�е����ݹ��ɽ����1->2->5
 *                �������һ��Ԫ�ء�temp=["1", "5"]
 *                ���ص�2�ĺ���ջ֡
 *         �������һ��Ԫ�ء�temp=["1"]
 *         ���ص�1�ĺ���ջ֡
 *  1->��->3->��->nullptr�����ص�3�ĺ���ջ֡��temp=["1", "3"]
 *         3->��->nullptr�����ص�3�ĺ���ջ֡
 *         �ж�3���Ҿ�Ϊ�գ�˵����Ҷ�ӽڵ㣬��ʱ��temp�е����ݹ��ɽ����1->3
 *         �������һ��Ԫ�ء�temp=["1"]
 *         ���ص�1�ĺ���ջ֡
 *  �������һ��Ԫ�ء�temp=[]
 *  �ص���������������
 */
class Solution257
{
public:
    void addchar(TreeNode *root, vector<string> &ret, vector<string> &temp)
    {
        if (!root)
            return;

        temp.push_back(to_string(root->val));
        addchar(root->left, ret, temp);
        addchar(root->right, ret, temp);

        if (!root->left && !root->right)
        {
            string backup = "";
            for (int i = 0; i < temp.size(); i++)
            {
                backup += temp[i];
                if (i != temp.size() - 1)
                    backup += "->";
            }
            ret.push_back(backup);
        }
        temp.pop_back();
    }

    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> ret;
        vector<string> temp;

        addchar(root, ret, temp);

        return ret;
    }
};

// ȥ�����ã�ͨ������������ɻ��ݣ�ʡȥ�ֶ�pop_back()
class Solution257_2
{
public:
    void addchar(TreeNode *root, vector<string> &ret, vector<string> temp)
    {
        if (!root)
            return;

        temp.push_back(to_string(root->val));
        addchar(root->left, ret, temp);
        addchar(root->right, ret, temp);

        if (!root->left && !root->right)
        {
            string backup = "";
            for (int i = 0; i < temp.size(); i++)
            {
                backup += temp[i];
                if (i != temp.size() - 1)
                    backup += "->";
            }
            ret.push_back(backup);
        }
    }

    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> ret;
        vector<string> temp;

        addchar(root, ret, temp);

        return ret;
    }
};

// string�����м����vector<string>
class Solution257_3
{
public:
    void addchar(TreeNode *root, vector<string> &ret, string temp)
    {
        if (!root)
            return;

        temp += to_string(root->val);
        // Ҷ�ӽڵ㵥������
        if(!root->left && !root->right)
        {
            ret.push_back(temp);
            // ֱ�ӷ��ز���Ҫ����->
            return;
        }
        temp += "->";

        addchar(root->left, ret, temp);
        addchar(root->right, ret, temp);
    }

    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> ret;
        string temp;

        addchar(root, ret, temp);

        return ret;
    }
};