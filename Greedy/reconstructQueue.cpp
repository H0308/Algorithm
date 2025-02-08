//
// Created by 18483 on 2025/2/8.
//
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

// 力扣406.根据身高重建队列
/*
 * 因为本题需要满足前面正好有ki个身高大于或等于hi的人，所以首先考虑对原数组按照身高降序进行排序（如果身高相同就按照k进行升序排序）
 * 这样排序后就可以确保任何一个元素之前的元素都是身高比当前元素大的，此时的k就代表了插入的位置，例如如果说一个元素的k为1，表示其之前只有一个元素的身高比当前元素的身高大
 * 那么就可以插入到k所在的下标位置，因为下标为1之前只有一个元素（即下标为0的元素），同理可得其他元素
 */
// 版本1：使用vector完成插入
class Solution406
{
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {
        // 先对原数组按照身高降序排序，相同的身高按照k升序排序
        sort(people.begin(), people.end(), [](vector<int> &p1, vector<int> &p2)-> bool
        {
            return p1[0] > p2[0] || p1[0] == p2[0] && p1[1] < p2[1];
        });

        vector<vector<int>> ret;
        // 再按照k插入到新数组中
        for (int i = 0; i < people.size(); i++)
        {
            int pos = people[i][1];
            ret.insert(ret.begin() + pos, people[i]);
        }

        return ret;
    }
};

// 优化：使用list插入
// 因为vector插入元素时涉及到挪动数据和扩容，这两者消耗比较大，所以考虑先用list完成插入操作，再通过list构造vector返回
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // 先对原数组按照身高降序排序，相同的身高按照k升序排序
        sort(people.begin(), people.end(), [](vector<int>& p1, vector<int>& p2)->bool{
            return p1[0] > p2[0] || p1[0] == p2[0] && p1[1] < p2[1];
        });

        list<vector<int>> ret;
        // 再按照k插入到新数组中
        for(int i = 0; i < people.size(); i++)
        {
            int pos = people[i][1];
            auto it = ret.begin();
            // 找到插入位置
            while(pos--)
                it++;
            ret.insert(it, people[i]);
        }

        return vector<vector<int>>(ret.begin(), ret.end());
    }
};