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

// 力扣112.路径总和
/*
 * 本题基本思路：通过sum变量的值判断是否与目标值targetSum相等，并且当前节点需要满足是叶子节点
 * 「当前节点是叶子」在本题中尤为重要，因为存在一种情况：还没到叶子时，sum就已经和targetSum相等，或者sum大于targetSum
 * 对于上面这两种情况，如果单独处理会非常麻烦还不容易处理
 * 所以针对上面的思路，考虑出递归的终止条件：
 * 1. 当前节点是叶子节点，并且当前的sum == targetSum时，说明找到一条路径满足
 * 2. 当前节点是叶子节点，但是当前的sum != targetSum时，说明当前路径此时不满足
 * 既然要判断是叶子节点，就需要判断当前节点的左孩子和右孩子都是nullptr，所以为了防止出现空指针解引用的错误
 * 在遍历下一层时也需要判断下一层是否为空
 * 最后就是需要考虑到sum的计算问题，因为是不同的函数栈帧，在退回时sum的值会进行改变，或者说在一个函数内对sum的修改不影响另外一个函数中的sum
 * 所以需要考虑到sum何时需要恢复到原来的数值，给出一种思路：
 * 先遍历左子树，此时sum加上左子树节点的值，进入新的函数栈帧，如果为true直接返回，代表找到一条路径；如果为false就要走右子树，此时就需要更新sum，让其减去左子树回到没有加左子树值的状态；
 * 接着遍历右子树，此时sum也是加上右子树节点的值，进入新的函数栈帧，如果为true直接返回，代表找到一条路径；如果为false就要走右子树，此时可以考虑恢复sum，也可以不考虑，因为走到右子树还没有找到路径
 * 说明当前子树不存在一条根节点到叶子节点的路径和为targetSum，直接返回false，此时的sum因为是在当前节点的栈帧中更新的，既然不存在满足条件的路径，那么说明当前子树一定不存在满足条件的路径，向上返回时sum还是原来的sum
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

            // 此处的回溯可以保留也可以去掉，因为走到了这一步说明上面sum改变的值进入到右子树的栈帧空间返回的是false
            // 如果没有下面的回溯，那么走完if就直接走到了下面的return false回到上一层函数栈帧
            // 此时的sum依旧是没有加上右子树节点值的sum
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

// 力扣113.路径总和Ⅱ
/*
 * 本题和上题基本类似，不同的是，本题不是找到一条满足条件的路径就结束，而是找到所有满足条件的路径
 * 所以不论是找到还是没有找到，都需要继续执行上层栈帧的回溯
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
