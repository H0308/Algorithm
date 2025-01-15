//
// Created by 18483 on 2025/1/15.
//
#include <iostream>
#include <vector>
#include <functional>
#include <unordered_map>
#include <map>

using namespace std;

// ����332.���°����г�
/*
 * �����ǵ��͵�ŷ����·���⣬ѧ��ͼ�ۺ��ٻع˱����Լ���������753.�ƽⱣ����
 * �����˼·����ͨ���������ҳ����ʵ�Ŀ�ĵأ���Ϊ��Ҫ������������������Կ������û��������
 * ��Ϊ��Ŀ���ᵽ��������ڶ���·������ô�Ͱ����ֵ����������Կ��Կ��ǽ�Ŀ�ĵط���map��
 * ������Ϊ�����˳�����ΪJFK�����ԴӸó�����һ�������ҵ���Ӧ��Ŀ�ĵأ��ٽ���һ�ε�Ŀ�ĵ���Ϊ������һֱ����Ѱ�ң�ֱ���ҵ�һ�����ʵ�·��ֱ�����Ϸ��ؼ���
 * ������ܳ������������
 * 1. һ��·�ߵ���
 * 2. ��ѭ������
 * �ڱʼ��л�ͼ�������������������
 * 1. [["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]��һ��·�ߵ��ڣ�
 * 2. [["JFK","KUL"],["JFK","NRT"],["NRT","JFK"]]���򵥵�ѭ�����ࣩ
 * 3. [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]�����ӵ�ѭ�����ࣩ
 */
class Solution332
{
public:
    // ����Ŀ�ĵس��ִ�����Ŀ�ĵ�ӳ��
    // map<string, int> Ŀ�ĵ�����ִ���ӳ�䣬��ֹ����ʹ��ͬһ��Ŀ�ĵأ�����ʹ��mapĬ�ϻ������������
    // ����������Ŀ�ĵؽ���ӳ��
    // unordered_map<string, string> ��������Ŀ�ĵ�ӳ��
    // ����������ӳ���ϣ�����ͨ����������map�л�ȡ��Ŀ�ĵأ���ȡ��Ŀ�ĵغ�ͨ��mapӳ���ȡ��Ʊ��
    unordered_map<string, map<string, int>> dest;
    // �����
    vector<string> ret;

    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        // ����ӳ�䲢����Ʊ��
        for (auto &path: tickets)
        {
            // dest[path[0]]��ʾ�����غ�Ŀ�ĵؽ���ӳ�䣬��ǰĿ�ĵ�Ϊ��
            // dest[path[0]][path[1]]ͨ�������ػ�ȡ��Ŀ�ĵأ���ͨ��Ŀ�ĵظ���Ʊ������
            dest[path[0]][path[1]]++;
        }

        // ����Ϊ��ǰʹ�õ�Ʊ��
        // ��Ϊֻ��Ҫ�ҵ�����һ������������·���Ϳ���ֱ�ӷ��أ����Ե��ҵ�ʱһֱ���ϲ㷵��true����
        function<bool(int)> backtracking = [&](int ticketNum)
        {
            // �����ظ���=Ʊ��+1
            // �ҵ�һ�����ϵ�·��ֱ�ӷ��أ�����Ҫ�ټ���������
            if (ret.size() == ticketNum + 1)
                return true;

            // ���ݳ����ػ�ȡ��Ŀ�ĵأ����Ŀ�ĵص�Ʊ����Ȼ����0��˵����������
            // ÿһ��ѭ��ʱ�������ؾ��ǽ���������һ��Ԫ��
            // ��Ϊmap���Ѿ��������Ի�ȡʱҲ�ǰ����ֵ����ȡ
            // ע��stringҪ��const��������뱨��
            for (pair<const string, int> &p: dest[ret[ret.size() - 1]]) // map<string, int>
            {
                // Ʊ������0
                if (p.second > 0)
                {
                    // �ߵ�Ŀ�ĵ�
                    ret.emplace_back(p.first);
                    // ����Ʊ��
                    p.second--;
                    // ����ҵ�һ��·������һֱ���Ϸ���
                    if (backtracking(ticketNum))
                        return true;

                    // ����
                    ret.pop_back();
                    p.second++;
                }
            }

            return false;
        };

        // ��ʼʱһ����JFK��������
        ret.emplace_back("JFK");

        backtracking(tickets.size());

        return ret;
    }
};
