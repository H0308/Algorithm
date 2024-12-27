//
// Created by 18483 on 2024/12/27.
//
#include <iostream>
#include <vector>
#include <unordered_map>
#include <numeric>
#include <algorithm>

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

// ����538.�Ѷ���������ת��Ϊ�ۼ���
/*
 * ����˼·��ʹ����������������ŵ������У��ټ��������ĺ�׺�ͣ�����׺����ԭ�ڵ����ӳ�䣬���ʹ�ö�Ӧ�ڵ�ĺ�׺�͸���ԭ���Ľڵ㼴��
 */
class Solution538_1
{
public:
    void traversal(TreeNode *root, vector<int> &nums)
    {
        if (!root)
            return;

        traversal(root->left, nums);
        nums.push_back(root->val);
        traversal(root->right, nums);
    }

    vector<int> calSum(const vector<int> &nums)
    {
        vector<int> ret(nums.size());
        partial_sum(nums.rbegin(), nums.rend(), ret.begin());

        return ret;
    }

    void _convertBST(TreeNode *root, unordered_map<int, int> &sum_node)
    {
        if (!root)
            return;

        _convertBST(root->left, sum_node);
        root->val = sum_node[root->val];
        _convertBST(root->right, sum_node);
    }

    void findSum(const vector<int> &nums, const vector<int> &partialSum, unordered_map<int, int> &sum_node)
    {
        for (int i = 0; i < nums.size(); i++)
            sum_node[nums[i]] = partialSum[i];
    }

    TreeNode *convertBST(TreeNode *root)
    {
        vector<int> nums;

        // ��ȡ����������
        traversal(root, nums);

        // �ҵ����ڵ������±�
        int rootIndex = 0;
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] == root->val)
                rootIndex = i;

        // �����׺��
        vector<int> partialSum = calSum(nums);
        reverse(partialSum.begin(), partialSum.end());

        // ����׺����ԭ�����Ľڵ㽨��ӳ���ϵ
        unordered_map<int, int> sum_node;
        findSum(nums, partialSum, sum_node);

        // ��������ԭ��
        _convertBST(root, sum_node);

        return root;
    }
};

// �ⷨ2
/*
 * �ڽⷨ1�У�������������ת��Ϊ����Ĺ�����Ϊ�˸��õ����Ӻ���ǰ������������Ϊת������֮��ڵ��Ԫ��֮�Ͳ���Ӧ
 * ���Ի���Ҫһ����ϣ������¼Ԫ�غͺ�׺�͵�ӳ�䣬�������������˼·��Ȼ���������ǿռ临�ӶȱȽϸ�
 * ���������Ĺ��̣�ʵ���ϾͿ���ֱ��ʹ��˫ָ����ԭ���Ͻ����޸ģ������޸ĵĹ���Ӧ���������󣬱�֤����
 * ����ָ�룬����һ��ָ���ʾǰһ����ֵ�����Ѿ��������׺�͵Ľ��������һ��ָ����ǵݹ�����е�root����¼��ǰ�ڵ��ֵ
 * �ڱ��������У���ǰ�ڵ����ǰһ���ڵ����ֵ����
 */
class Solution538_2
{
public:
    // ʹ�ñ�����¼ǰһ���ڵ��������ܺ�
    // ʹ��ʹ����ֵ��¼����ֹ��ָ������ô����Լ������ָ�봦���߼�
    int prev = 0;

    TreeNode *convertBST(TreeNode *root)
    {
        // �ڵ�Ϊ�գ�����0
        if (!root)
            return 0;

        // ʹ�����������
        root->right = convertBST(root->right);
        root->val += prev;
        prev = root->val;
        root->left = convertBST(root->left);

        return root;
    }
};
