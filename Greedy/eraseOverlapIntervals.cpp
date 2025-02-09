//
// Created by 18483 on 2025/2/9.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ����435.���ص�����
/*
 * ����˼·���䱬����˼·�ǳ����ƣ���ͬ���ǣ����ⲻ���ǵ��ڵ���������Ƚ���߽��Ƿ�С����һ��Ԫ�ص��ұ߽���Ϊ�ж��ص�������
 * ��������ص��������͸��¼�������������ΪҪ�ж���һ�������Ƿ������ص�����Ҫ�����ұ߽�Ϊ��С���ұ߽磬��һ�����¾��൱���Ƴ���ǰ�����ص�������
 * ��������;���������һ���ж��Ƿ��ص�
 */
class Solution435
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        int count = 0;

        sort(intervals.begin(), intervals.end(), [](vector<int> &i1, vector<int> &i2)
        {
            return i1[0] < i2[0];
        });

        for (int i = 1; i < intervals.size(); i++)
        {
            // �жϵ�ǰλ�õ���߽��Ƿ�С��ǰһ��λ�õ��ұ߽�
            if (intervals[i][0] < intervals[i - 1][1])
            {
                count++;
                // ȡ��С�ұ߽���Ϊ��һ���жϵ��������˲�����൱���Ƴ��ص�����
                intervals[i][1] = min(intervals[i - 1][1], intervals[i][1]);
            }
        }

        return count;
    }
};
