//
// Created by 18483 on 2025/2/7.
//
#include <iostream>
#include <vector>

using namespace std;

// ����134.����վ
/*
 * ����ı���˼·��ģ��ÿһ��λ����Ϊ����ж��Ƿ�����ߵ��յ㣬����ʱ�临�ӶȱȽϸߣ�����ʹ��̰��
 * ������Ҫ̰�ľ��ǵ�ǰλ�ü�֮ǰ�ĺ��Ƿ��Ƕ�����������Ч�������ӵ��ͺ�������ĵ���֮���Ƿ����0�������û�У��͵���һ��λ�ü������ң�����ܺͶ�������Ч������ô˵�������ڸ����
 */
class Solution134
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        // ��¼��ǰλ�������滹�����
        int curSum = 0;
        // ��¼����������滹������
        int totalSum = 0;
        // ��¼��ʼλ��
        int start = 0;
        for (int i = 0; i < gas.size(); i++)
        {
            curSum += gas[i] - cost[i];
            totalSum += gas[i] - cost[i];

            // �����ǰλ�������ģ���˵��֮ǰ������λ����Ϊ��ʼλ�õ��ﵱǰλ�ö��ᵼ����������
            if (curSum < 0)
            {
                // ����һ��λ�ÿ�ʼ
                start = i + 1;
                // ����ͳ�����滹������
                curSum = 0;
            }
        }

        // ������������ģ���˵��������һ����������������
        if (totalSum < 0)
            return -1;
        return start;
    }
};
