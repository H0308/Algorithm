//
// Created by 18483 on 2025/2/8.
//
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

// ����406.��������ؽ�����
/*
 * ��Ϊ������Ҫ����ǰ��������ki����ߴ��ڻ����hi���ˣ��������ȿ��Ƕ�ԭ���鰴����߽������������������ͬ�Ͱ���k������������
 * ���������Ϳ���ȷ���κ�һ��Ԫ��֮ǰ��Ԫ�ض�����߱ȵ�ǰԪ�ش�ģ���ʱ��k�ʹ����˲����λ�ã��������˵һ��Ԫ�ص�kΪ1����ʾ��֮ǰֻ��һ��Ԫ�ص���߱ȵ�ǰԪ�ص���ߴ�
 * ��ô�Ϳ��Բ��뵽k���ڵ��±�λ�ã���Ϊ�±�Ϊ1֮ǰֻ��һ��Ԫ�أ����±�Ϊ0��Ԫ�أ���ͬ��ɵ�����Ԫ��
 */
// �汾1��ʹ��vector��ɲ���
class Solution406
{
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {
        // �ȶ�ԭ���鰴����߽���������ͬ����߰���k��������
        sort(people.begin(), people.end(), [](vector<int> &p1, vector<int> &p2)-> bool
        {
            return p1[0] > p2[0] || p1[0] == p2[0] && p1[1] < p2[1];
        });

        vector<vector<int>> ret;
        // �ٰ���k���뵽��������
        for (int i = 0; i < people.size(); i++)
        {
            int pos = people[i][1];
            ret.insert(ret.begin() + pos, people[i]);
        }

        return ret;
    }
};

// �Ż���ʹ��list����
// ��Ϊvector����Ԫ��ʱ�漰��Ų�����ݺ����ݣ����������ıȽϴ����Կ�������list��ɲ����������ͨ��list����vector����
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // �ȶ�ԭ���鰴����߽���������ͬ����߰���k��������
        sort(people.begin(), people.end(), [](vector<int>& p1, vector<int>& p2)->bool{
            return p1[0] > p2[0] || p1[0] == p2[0] && p1[1] < p2[1];
        });

        list<vector<int>> ret;
        // �ٰ���k���뵽��������
        for(int i = 0; i < people.size(); i++)
        {
            int pos = people[i][1];
            auto it = ret.begin();
            // �ҵ�����λ��
            while(pos--)
                it++;
            ret.insert(it, people[i]);
        }

        return vector<vector<int>>(ret.begin(), ret.end());
    }
};