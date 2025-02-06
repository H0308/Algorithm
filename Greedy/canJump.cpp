//
// Created by 18483 on 2025/2/6.
//
#include <iostream>
#include <vector>

using namespace std;

// ����55.��Ծ��Ϸ
/*
 * ����Ļ���˼·�����ҵ������ߵ���β�Ĳ�����Ϊ�˿����ߵ���β�����Բ���Ҫ�����ܵô󣬶�Ҫʹ���������ܴ󣬾ֲ����ž���ÿһ���ߵĲ��������ܴ�
 * �ӵ�һ����ʼ�������һ��Ԫ�ش���ʣ��Ĳ�������ֱ�Ӹ��²���������ͼ���������
 * ����ߵ�Ԫ��Ϊ0��λ��ʱ���������������
 * 1. �Ѿ������һ��Ԫ��
 * 2. ����û������
 * 3. �������겢��û�е����һ��Ԫ��
 * ������������������Եó�ֻ�����һ���������Ҫ����false�ģ�����������true
 */
class Solution55
{
public:
    bool canJump(vector<int> &nums)
    {
        int last = nums.size() - 1;
        int step = nums[0];
        for (int i = 0; i < nums.size(); i++)
        {
            step--;

            // ÿ��̰�ϴ�Ĳ�����ʹ�����ߵĲ��������ܶ�
            if (nums[i] > step)
                step = nums[i];

            // �������겢��û�е����һ��Ԫ��
            if (step <= 0 && i < last)
                return false;
        }

        return true;
    }
};
