//
// Created by 18483 on 2024/12/24.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x)
        : val(x)
        , left(nullptr)
        , right(nullptr)
    {}
};

// ����501.�����������е�����
/*
 * ��ֱ�۵�˼·��������������������Ԫ�����β���vector������vectorʹ�ù�ϣ��ͳ��Ԫ�س��ֵĴ������ҳ����ִ�����������Ԫ��
 */
// ����������+��ϣ��
class Solution501_1
{
public:
    void traversal(TreeNode *root, unordered_map<int, int> &countMap)
    {
        if (!root)
            return;

        traversal(root->left, countMap);
        // ͳ�Ƴ���Ƶ��
        countMap[root->val]++;
        traversal(root->right, countMap);
    }

    vector<int> findMode(TreeNode *root)
    {

        unordered_map<int, int> countMap;
        traversal(root, countMap);

        int maxCount = 0;
        vector<int> ret;
        for (auto &kv: countMap)
        {
            if (kv.second > maxCount)
                maxCount = kv.second;
        }

        for (auto &kv: countMap)
        {
            if (kv.second == maxCount)
                ret.push_back(kv.first);
        }

        for (auto &kv: countMap)
        {
            // ע��ʹ��findȷ����ǰ�����Ԫ�ز������ڽ������
            if (kv.second == maxCount && kv.first != ret[0] && find(ret.begin(), ret.end(), kv.first) == ret.end())
                ret.push_back(kv.first);
        }

        return ret;
    }
};

// �ⷨ2�������ռ䣬ʹ��ǰ��ָ��+���뼼�ɴ�������
class Solution501_2
{
public:
    // ��¼���Ƶ��
    int maxCount = 0;
    // ��¼��ǰԪ�س��ֵ�Ƶ��
    int count = 0;
    // �����
    vector<int> ret;
    // ��һ���ڵ�
    TreeNode *prev = nullptr;

    void traversal(TreeNode *root)
    {
        if (!root)
            return;

        // �������
        traversal(root->left);

        // �м䴦��
        // ͳ�Ƶ�ǰԪ�س���Ƶ��
        if (prev == nullptr) // ǰһ��Ϊ��Ԫ�أ�˵����ǰԪ��һ��Ϊ�³��ֵ�Ԫ�أ�count����Ϊ1
            count = 1;
        else if (prev->val == root->val) // ǰһ��Ԫ�غ͵�ǰԪ����ȣ�˵��һ�����ظ�Ԫ��
            count++;
        else
            count = 1; // ǰһ��Ԫ�غ͵�ǰԪ�ز���ȣ�˵��������Ԫ�أ�count����Ϊ1
        // ����prev
        prev = root;

        // ���count��maxCount��ȣ�˵����ʱ�ҵ���������Ƶ�ʵ�Ԫ��
        // ���½����
        // ʹ��ifȷ��ֻ����һ������������Ƶ�ʵ�Ԫ��
        if (count == maxCount)
            ret.push_back(root->val);

        // ���count����maxCount˵��ǰ���Ѿ����µĽ�������󣬴�ʱ����maxCount�ͽ����
        // ͨ���ڶ��εĸ���һ�����������ڵ�ǰ״̬�½�������ǵ�ǰ����Ƶ������
        // �����һ���в�ͬ��ֵ���ǳ���Ƶ�������Ƶ����ͬ����ô����Ϊ�����if���뵽�������������½����
        if (count > maxCount)
        {
            maxCount = count;
            // �����һ�εĽ����
            ret.clear();
            // ���¸��½����
            ret.push_back(root->val);
        }

        traversal(root->right);
    }

    vector<int> findMode(TreeNode *root)
    {
        traversal(root);

        return ret;
    }
};
