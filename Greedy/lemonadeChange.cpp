//
// Created by 18483 on 2025/2/7.
//
#include <iostream>
#include <vector>

using namespace std;

// ����860.����ˮ����
/*
 * ������ǰ�����Ŀ��Ҫ��ȥģ�⣬һ�������������
 * 1. �յ���ֵΪ5��ֱ������
 * 2. �յ���ֵΪ10������ֵ5
 * 3. �յ���ֵΪ20��������10��5��Ҳ������3��5����������10��5����Ϊ5��ͨ��
 * ע�⣬���ⲻ��Ҫ���Ǿ���ļ��㣬�������㻹ʣ����Ǯ��ֻ��Ҫȷ���Ƿ񻹿�����ȷ���㼴�ɣ��������������ֻ��Ҫ��¼���������������ֵ�����Ƿ��㹻����
 */
class Solution860
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        int five = 0;
        int ten = 0;
        for (auto bill: bills)
        {
            if (bill == 5)
                five++;
            else if (bill == 10)
            {
                if (five == 0)
                    return false;
                five--;
                ten++;
            }
            else if (bill == 20)
            {
                if (five > 0 && ten > 0)
                {
                    five--;
                    ten--;
                }
                else if (five >= 3)
                {
                    five -= 3;
                }
                else
                    return false;
            }
        }

        return true;
    }
};
