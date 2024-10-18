#include "BinarySearch.h"

// ����ұ�ԭ��
// ����ָ��Ԫ�ص��±�
int Array_Basic::BinarySearch(std::vector<int> &nums, int target, int flag)
{
    // ʹ��(void)ǿ��ת����ֹ���������棬flag�ڶ��ֲ�����û������
    (void)flag;
    std::cout << "[left, right]" << std::endl;
    // ����ұ�ԭ��[left, right]����������ֵ����vector����Ч
    int left = 0;
    int right = nums.size() - 1;

    // left <= right, ��Ϊ��left==rightʱ��nums[left] == nums[right]��Ч����ʱ�����һ���ж�
    while (left <= right)
    {
        // ������м�ֵ
        // int mid = (left + right) / 2;
        int mid = left + ((right - left) / 2); // ��ֹ������������Ч�������д��
        // ����2Ҳ����ʹ������>>
        // int mid = left + ((right - left) >> 2);
        /*
         * ����Ĳ���������̶�����ļ��ֵ����ͨ����ʼλ�ü��ϼ��ֵ�������м�ֵλ��
         *  ���岽�����£�
         *  1. ���� right - left���õ�����ĳ���
         *  2. �����䳤�ȳ��� 2���õ��м�ֵ����� left ��ƫ����
         *  3. ��ƫ�����ӵ� left �ϣ��õ��м�ֵ��λ��
         */
        // �ж��Ƿ�ȡ��ָ��ֵ
        if (nums[mid] == target) // ��ȡ�������
        {
            return mid; // ����ָ��ֵ�±�
        }
        else if (nums[mid] > target) // �м�ֵ�ϴ󡪡�targetһ�����м�ֵ���
        {
            // ����ұ�ԭ�򣬴�ʱnums[mid]һ������target
            right = mid - 1;
        }
        else if (nums[mid] < target) // �м�ֵ��С����targetһ�����м�ֵ�ұ�
        {
            // ����ұ�ԭ�򣬴�ʱnums[mid]һ������target
            left = mid + 1;
        }
    }

    // Լ��û�ҵ�����-1
    return -1;
}

// ����ҿ�ԭ��
// ����ָ��Ԫ�ص��±�
int Array_Basic::BinarySearch(std::vector<int>& nums, int target)
{
    std::cout << "[left, right)" << std::endl;
    // ����ҿ�ԭ��[left, right)����ʱ��left==rightʱ������Ч����
    int left = 0;
    int right = nums.size();

    // ��Ϊleft==right����Ч���䣬����left�����Ե���right
    while (left < right)
    {
        int mid = (left + right) / 2;
        if(nums[mid] == target) // ��ȡ�������
        {
            return mid;
        }
        else if(nums[mid] > target) // �м�ֵ�ϴ���Ŀ��ֵһ�����м�ֵ�ұ�
        {
            // ����ҿ�ԭ�򣬴�ʱmid��ֵ����һ�ε��ұ߽磬������mid��ֵ
            right = mid;
        }
        else if(nums[mid] < target) // �м�ֵ��С����Ŀ��ֵһ�����м�ֵ���
        {
            // ����ҿ�ԭ�򣬴�ʱmid��ֵ����һ�ε���߽磬����mid��ֵ
            left = mid + 1;
        }
    }

    // û�ҵ�ָ��ֵ����-1
    return -1;
}

// ����35.��������λ��
class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int mid = 0;
        while(left <= right)
        {
            mid = left + ((right - left) >> 1);
            if(nums[mid] == target)
            {
                return mid;
            }
            else if(nums[mid] > target)
            {
                right = mid - 1;
            }
            else if(nums[mid] < target)
            {
                left = mid + 1;
            }
        }

        // û�ҵ������м�ֵ����һ��λ�ã���Ҫ���������д��ڵ�λ�ã���������ڵ�λ�ã���������һ���������鳤��λ�õ�Ԫ��
        // return target < nums[mid] ? mid: mid + 1;
        // ����ұղ��ܷ���right
        // return right;
        return left;
    }
};