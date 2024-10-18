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
        // int mid = left + ((right - left) >> 1);
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
class Solution35 {
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

// ����69.x��ƽ����
/*
 * ���ֲ��ң�
 * Ϊʲô����ö��С��x��ÿһ������ʱ����С������ƽ������0����������������ֲ��ҵĵ��ڣ��������ϸ����
 * ��ô�ã���С������ƽ������0���������Ϊ0������Ҫ�жϵ��ǵ�ǰö�ٵ���ֵ�Ƿ�Ϊk*k<=x��
 * ����Ϊx������ƽ�����϶���[0, x]�����У�������Ҫö��0��x�е���ֵ��
 * ���轫0��x����ֵ����һ�����飬��ȡ����ǰ������м�Ԫ�أ�
 * �ж��м�Ԫ��mid*mid�Ƿ�<=x��С��˵����Ҫ�ƶ�left�������ƶ�right
 * ��ôд��
 */
class Solution69 {
public:
    int mySqrt(int x) {
        // �����ⷨ
        // size_t ans = 0;
        // for(;ans * ans <= x; ans++);
        // return (ans - 1);
        size_t left = 0;
        size_t right = x;
        size_t ans = 0;
        // ����ұ�����
        while(left <= right)
        {
            size_t mid = left + ((right - left) >> 1);
            // �����޷��ոպõ���
            // if(ans == x)
            // {
            //     ans = mid;
            //     break;
            // }
            if(mid * mid <= x) // �м�ֵ��С
            {
                ans = mid;
                left = mid + 1;
            }
            else if(mid * mid > x) // �м�ֵ�ϴ�
            {
                right = mid - 1;
            }
        }
        return ans;
    }
};

// ����69���ͣ�����367.��Ч����ȫƽ����
class Solution367 {
public:
    bool isPerfectSquare(int num) {
        size_t left = 0;
        size_t right = num;
        size_t ans = 0;
        // ����ұ�����
        while(left <= right)
        {
            size_t mid = left + ((right - left) >> 1);
            if (mid * mid <= num)
            {
                ans = mid;
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return ans * ans == num;
    }
};

// ����34.�����������в���Ԫ�صĵ�һ�������һ��λ��
/*
 * ����˼·��
 * ���ֲ���
 * Ϊʲô����Ŀ�ᵽ���������򵫷ǵݼ�������ֱ����target�϶������Ψһ�����Ǳ�����Ҫ�ҵ��ǵ�һ�������һ��λ�ö�Ӧ���±�
 * ���Կ��Կ����趨����һ�������ڵı߽�ֵ��ʹ�ö��ֲ����趨�߽磬��Ϊ���������飬����һ�������ڵ�ֵ�϶��Ǹ�����
 * ��ô�ң������ж�target�Ƿ������ԭ���飬�����ڷ���{-1, -1}���˴��Ϳ���ֱ��ʹ�ö��ֲ��ң������ҵ�һ����Чλ�ü��ɣ�
 * ������������ʹ�����ζ��ֲ��ң���һ�ζ��ֲ�������߽磬�ڶ������ұ߽缴��
 */
class Solution34 {
public:
    // ���ֲ���
    int BinarySearch(std::vector<int>& nums, double target) {
        int left = 0;
        int right = nums.size();

        // ����ҿ�����
        while (left < right) {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return left;
    }

    // ʹ�ö��ֲ���ȷ���Ƿ����
    bool isExist(std::vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();

        // ����ҿ�����
        while (left < right) {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target){
                right = mid;
            } else {
                return true;
            }
        }

        return false;
    }

    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        // �ж��Ƿ����
        if(!isExist(nums, target))
        {
            // ������ֱ�ӷ���
            return {-1, -1};
        }

        // ���������
        // ����߽�
        int leftHand = BinarySearch(nums, target - 0.5);
        // ���ұ߽�
        int rightHand = BinarySearch(nums, target + 0.5);
        return {leftHand, rightHand - 1};
    }
};

// ţ��������Ŀ��JZ53 ���������������г��ֵĴ���
#include <vector>
class SolutionJZ53 {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param nums int����vector
     * @param k int����
     * @return int����
     */
    // ���ֲ���
    int BinarySearch(std::vector<int>& nums, double target)
    {
        int left = 0;
        int right = nums.size() - 1;
        // ����ұ�����
        while (left <= right)
        {
            int mid = left + ((right - left) >> 1);
            if(nums[mid] <= target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return left;
    }
    int GetNumberOfK(std::vector<int>& nums, int k)
    {
        // ��߽�
        int leftHand = BinarySearch(nums, k - 0.5);
        // �ұ߽�
        int rightHand = BinarySearch(nums, k + 0.5);

        return rightHand - leftHand;
    }
};
// C���԰汾
namespace solutionJZ53
{
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param nums int����һά����
     * @param numsLen int nums���鳤��
     * @param k int����
     * @return int����
     */
    //���ֲ���
    int BinarySearch(int* nums, int numsLen, double k)
    {
        int left = 0;
        int right = numsLen - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if(nums[mid] > k)
            {
                right = mid - 1;
            }
            else if (nums[mid] < k) {
                left = mid + 1;
            }
        }
        //���� left ������ mid
        return left;
    }
    int GetNumberOfK(int* nums, int numsLen, int k )
    {
        return BinarySearch(nums, numsLen, k+0.5)-BinarySearch(nums, numsLen, k-0.5);
    }
}