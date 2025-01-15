//
// Created by 18483 on 2025/1/15.
//
#include <iostream>
#include <vector>
#include <functional>
#include <unordered_map>
#include <map>

using namespace std;

// 力扣332.重新安排行程
/*
 * 本题是典型的欧拉回路问题，学完图论后再回顾本题以及尝试力扣753.破解保险箱
 * 本题的思路就是通过出发地找出合适的目的地，因为需要遍历到所有情况，所以可以利用回溯来解决
 * 因为题目中提到，如果存在多种路径，那么就按照字典序排序，所以可以考虑将目的地放入map中
 * 本题因为给定了出发地为JFK，所以从该出发地一定可以找到对应的目的地，再将下一次的目的地作为出发地一直向下寻找，直到找到一条合适的路径直接向上返回即可
 * 本题可能出现两种情况：
 * 1. 一条路走到黑
 * 2. 有循环航班
 * 在笔记中画图分析下面的三种样例：
 * 1. [["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]（一条路走到黑）
 * 2. [["JFK","KUL"],["JFK","NRT"],["NRT","JFK"]]（简单的循环航班）
 * 3. [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]（复杂的循环航班）
 */
class Solution332
{
public:
    // 处理目的地出现次数、目的地映射
    // map<string, int> 目的地与出现次数映射，防止过量使用同一个目的地，并且使用map默认会进行升序排序
    // 将出发地与目的地进行映射
    // unordered_map<string, string> 出发地与目的地映射
    // 将上面两种映射结合，做到通过出发地在map中获取到目的地，获取到目的地后通过map映射获取到票数
    unordered_map<string, map<string, int>> dest;
    // 结果集
    vector<string> ret;

    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        // 建立映射并更新票数
        for (auto &path: tickets)
        {
            // dest[path[0]]表示出发地和目的地进行映射，当前目的地为空
            // dest[path[0]][path[1]]通过出发地获取到目的地，再通过目的地更新票数计数
            dest[path[0]][path[1]]++;
        }

        // 参数为当前使用的票数
        // 因为只需要找到任意一条符合条件的路径就可以直接返回，所以当找到时一直向上层返回true即可
        function<bool(int)> backtracking = [&](int ticketNum)
        {
            // 经过地个数=票数+1
            // 找到一条符合的路径直接返回，不需要再继续向下找
            if (ret.size() == ticketNum + 1)
                return true;

            // 根据出发地获取到目的地，如果目的地的票数仍然大于0，说明还可以走
            // 每一次循环时，出发地就是结果集中最后一个元素
            // 因为map中已经排序，所以获取时也是按照字典序获取
            // 注意string要加const，否则编译报错
            for (pair<const string, int> &p: dest[ret[ret.size() - 1]]) // map<string, int>
            {
                // 票数大于0
                if (p.second > 0)
                {
                    // 走到目的地
                    ret.emplace_back(p.first);
                    // 减少票数
                    p.second--;
                    // 如果找到一条路径，就一直向上返回
                    if (backtracking(ticketNum))
                        return true;

                    // 回溯
                    ret.pop_back();
                    p.second++;
                }
            }

            return false;
        };

        // 开始时一定从JFK机场出发
        ret.emplace_back("JFK");

        backtracking(tickets.size());

        return ret;
    }
};
