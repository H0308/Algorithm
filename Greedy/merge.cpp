//
// Created by 18483 on 2025/2/9.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ����56.�ϲ�����
/*
 * �������䱬����˼·Ҳ�ǳ����ƣ��������жϵ�ǰ�������߽��Ƿ�С�ڵ�����һ������ұ߽���Ϊ�ж��ص�����
 * ��������ص�������Ҫ�ϲ����䣬��Ҫע�⣬Ĭ������£�����ֵ��������һ����ʼ���䣬�ϲ�����֮ǰ��Ҫ�ȵ���ǰһ�����䣬�������µ��������߽�Ϊǰһ���������߽�͵�ǰ�������߽��е���Сֵ
 * ͬ������µ�������ұ߽�Ϊǰһ��������ұ߽�͵�ǰ������ұ߽�����ֵ
 * ��ʱҲ����ȷ����һ�αȽ��ǰ���������͵�ǰ������бȽϴӶ�������©���
 * ���û���ص���ֱ�Ӳ��뵱ǰ���伴��
 */
class Solution56
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> ret;

        sort(intervals.begin(), intervals.end(), [](vector<int> &i1, vector<int> &i2)
        {
            return i1[0] < i2[0];
        });

        // Ĭ���е�һ������
        ret.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++)
        {
            // �жϵ�ǰ�������߽��Ƿ�С�ڵ�����һ������ұ߽�
            if (intervals[i][0] <= intervals[i - 1][1])
            {
                // ���Ƴ�ǰһ������
                ret.pop_back();
                // �ϲ����䲢����ϲ��������
                intervals[i][0] = min(intervals[i - 1][0], intervals[i][0]);
                intervals[i][1] = max(intervals[i - 1][1], intervals[i][1]);
                ret.push_back(intervals[i]);
            }
            else
            {
                // ����ֱ�Ӳ���
                ret.push_back(intervals[i]);
            }
        }

        return ret;
    }
};
