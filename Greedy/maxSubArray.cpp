//
// Created by 18483 on 2025/2/6.
//
#include <iostream>
#include <vector>

using namespace std;

// ����53.����������
/*
 * ���⻹�ǿ���ʹ�þֲ������Ƴ�ȫ�����ŵ�˼·�����ǵ������ǰ��Ϊ����ʱ����ô������һ�����Ƿ��������������µ���һ��������ʱ��Ҫ����ÿһ�μ���Ͷ�����һ�κ͵����ֵ
 * �����ǰ��С��0������sum���µ���
 * ��ʱ�������������
 * 1. ��ǰΪ��������ʱ��Ϊret�Ѿ�������һ�μ���ĺͣ������ǰΪ������ô������С�ڵ�ǰsum����Ҳ����Ӱ�쵽���ս��
 * 2. ��ǰΪ��������Ϊ�������ֻ��Խ��Խ�����sumΪ��������ô�����������������ֱ��ʹ������
 */
class Solution53
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int ret = INT_MIN;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            // ���㵱ǰ��
            if (sum < 0)
                sum = nums[i];
            else
                sum += nums[i];

            // ��ȡ����ǰ�������
            ret = max(sum, ret);
        }

        return ret;
    }
};
