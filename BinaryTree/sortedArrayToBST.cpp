//
// Created by 18483 on 2024/12/27.
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

// ����108.����������ת��Ϊ����������
/*
 * ���ⲻ����ֱ��ʹ�ö����������Ľڵ���뷽������Ϊ�������û�п��ǵ�ƽ�������Ӷ����¶�������Ϊ������
 * ��Ϊ�������������������ģ�����Ĭ����������еĽڵ�Ҳ���Ƕ���������������������
 * ��Ҫע����ǣ������Ѿ��ᵽ�˶������������Ľṹ���Բ�ͬ�����Կ���ֱ��ȡ�м�ֵ��Ϊ���ڵ㣬�����Ϳ��Ա�֤���������ĸ߶���󲻻ᳬ��1
 */
class Solution108
{
public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        if (nums.size() == 0)
            return nullptr;

        // ȡ���м�ֵ��Ϊ���ڵ�
        int mid = (nums.size() - 1) / 2;
        TreeNode *root = new TreeNode(nums[mid]);

        // ���ݸ��ڵ�λ�ù�������������������������ҿ�����
        vector<int> left(nums.begin(), nums.begin() + mid);
        vector<int> right(nums.begin() + mid + 1, nums.end());

        root->left = sortedArrayToBST(left);
        root->right = sortedArrayToBST(right);

        return root;
    }
};
