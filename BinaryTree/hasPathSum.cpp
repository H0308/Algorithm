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

// ����112.·���ܺ�
/*
 * �������˼·��ͨ��sum������ֵ�ж��Ƿ���Ŀ��ֵtargetSum��ȣ����ҵ�ǰ�ڵ���Ҫ������Ҷ�ӽڵ�
 * ����ǰ�ڵ���Ҷ�ӡ��ڱ�������Ϊ��Ҫ����Ϊ����һ���������û��Ҷ��ʱ��sum���Ѿ���targetSum��ȣ�����sum����targetSum
 * �������������������������������ǳ��鷳�������״���
 * ������������˼·�����ǳ��ݹ����ֹ������
 * 1. ��ǰ�ڵ���Ҷ�ӽڵ㣬���ҵ�ǰ��sum == targetSumʱ��˵���ҵ�һ��·������
 * 2. ��ǰ�ڵ���Ҷ�ӽڵ㣬���ǵ�ǰ��sum != targetSumʱ��˵����ǰ·����ʱ������
 * ��ȻҪ�ж���Ҷ�ӽڵ㣬����Ҫ�жϵ�ǰ�ڵ�����Ӻ��Һ��Ӷ���nullptr������Ϊ�˷�ֹ���ֿ�ָ������õĴ���
 * �ڱ�����һ��ʱҲ��Ҫ�ж���һ���Ƿ�Ϊ��
 * ��������Ҫ���ǵ�sum�ļ������⣬��Ϊ�ǲ�ͬ�ĺ���ջ֡�����˻�ʱsum��ֵ����иı䣬����˵��һ�������ڶ�sum���޸Ĳ�Ӱ������һ�������е�sum
 * ������Ҫ���ǵ�sum��ʱ��Ҫ�ָ���ԭ������ֵ������һ��˼·��
 * �ȱ�������������ʱsum�����������ڵ��ֵ�������µĺ���ջ֡�����Ϊtrueֱ�ӷ��أ������ҵ�һ��·�������Ϊfalse��Ҫ������������ʱ����Ҫ����sum�������ȥ�������ص�û�м�������ֵ��״̬��
 * ���ű�������������ʱsumҲ�Ǽ����������ڵ��ֵ�������µĺ���ջ֡�����Ϊtrueֱ�ӷ��أ������ҵ�һ��·�������Ϊfalse��Ҫ������������ʱ���Կ��ǻָ�sum��Ҳ���Բ����ǣ���Ϊ�ߵ���������û���ҵ�·��
 * ˵����ǰ����������һ�����ڵ㵽Ҷ�ӽڵ��·����ΪtargetSum��ֱ�ӷ���false����ʱ��sum��Ϊ���ڵ�ǰ�ڵ��ջ֡�и��µģ���Ȼ����������������·������ô˵����ǰ����һ������������������·�������Ϸ���ʱsum����ԭ����sum
 */
class Solution112
{
public:
    bool _hashPathSum(TreeNode *root, int targetSum, int sum)
    {
        if (!root->left && !root->right && sum == targetSum)
            return true;
        else if (!root->left && !root->right && sum != targetSum)
            return false;

        if (root->left)
        {
            sum += root->left->val;
            if (_hashPathSum(root->left, targetSum, sum))
                return true;

            sum -= root->left->val;
        }

        if (root->right)
        {
            sum += root->right->val;
            if (_hashPathSum(root->right, targetSum, sum))
                return true;

            // �˴��Ļ��ݿ��Ա���Ҳ����ȥ������Ϊ�ߵ�����һ��˵������sum�ı��ֵ���뵽��������ջ֡�ռ䷵�ص���false
            // ���û������Ļ��ݣ���ô����if��ֱ���ߵ��������return false�ص���һ�㺯��ջ֡
            // ��ʱ��sum������û�м����������ڵ�ֵ��sum
            sum -= root->right->val;
        }

        return false;
    }

    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (!root)
            return false;
        else if (!root->left && !root->right && root->val == targetSum)
            return true;

        return _hashPathSum(root, targetSum, root->val);
    }
};

// ����113.·���ܺ͢�
/*
 * ���������������ƣ���ͬ���ǣ����ⲻ���ҵ�һ������������·���ͽ����������ҵ���������������·��
 * ���Բ������ҵ�����û���ҵ�������Ҫ����ִ���ϲ�ջ֡�Ļ���
 */
class Solution113
{
public:
    void _pathSum(TreeNode *root, int targetSum, int sum, vector<int> &temp, vector<vector<int>> &ret)
    {
        if (!root->left && !root->right && sum == targetSum)
        {
            ret.push_back(temp);
            return;
        }

        if (root->left)
        {
            sum += root->left->val;
            temp.push_back(root->left->val);
            _pathSum(root->left, targetSum, sum, temp, ret);

            sum -= root->left->val;
            temp.pop_back();
        }

        if (root->right)
        {
            sum += root->right->val;
            temp.push_back(root->right->val);
            _pathSum(root->right, targetSum, sum, temp, ret);

            sum -= root->right->val;
            temp.pop_back();
        }
    }

    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        if (!root)
            return {};
        else if (!root->left && !root->right && root->val == targetSum)
            return {{root->val}};

        vector<int> temp;
        vector<vector<int>> ret;
        temp.push_back(root->val);

        _pathSum(root, targetSum, root->val, temp, ret);

        return ret;
    }
};
