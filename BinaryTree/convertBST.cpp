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

// 力扣538.把二叉搜索树转换为累加树
/*
 * 基本思路：使用中序遍历将结果存放到数组中，再计算该数组的后缀和，将后缀和与原节点进行映射，最后使用对应节点的后缀和覆盖原树的节点即可
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

        // 获取中序遍历结果
        traversal(root, nums);

        // 找到根节点所在下标
        int rootIndex = 0;
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] == root->val)
                rootIndex = i;

        // 计算后缀和
        vector<int> partialSum = calSum(nums);
        reverse(partialSum.begin(), partialSum.end());

        // 将后缀和与原先树的节点建立映射关系
        unordered_map<int, int> sum_node;
        findSum(nums, partialSum, sum_node);

        // 遍历覆盖原树
        _convertBST(root, sum_node);

        return root;
    }
};

// 解法2
/*
 * 在解法1中，将二叉搜索树转换为数组的过程是为了更好得理解从后向前遍历，但是因为转换数组之后节点和元素之和不对应
 * 所以还需要一个哈希表来记录元素和后缀和的映射，导致整个代码的思路虽然清晰，但是空间复杂度比较高
 * 理解了上面的过程，实际上就可以直接使用双指针在原树上进行修改，但是修改的过程应该是右中左，保证倒序
 * 两个指针，其中一个指针表示前一个数值（即已经计算过后缀和的结果），另一个指针就是递归过程中的root，记录当前节点的值
 * 在遍历过程中，当前节点加上前一个节点的数值即可
 */
class Solution538_2
{
public:
    // 使用变量记录前一个节点计算出的总和
    // 使用使用数值记录，防止空指针解引用错误以及额外空指针处理逻辑
    int prev = 0;

    TreeNode *convertBST(TreeNode *root)
    {
        // 节点为空，返回0
        if (!root)
            return 0;

        // 使用右中左遍历
        root->right = convertBST(root->right);
        root->val += prev;
        prev = root->val;
        root->left = convertBST(root->left);

        return root;
    }
};
