#include "BinarySearch.h"

// ����ұ�ԭ��
// ����ָ��Ԫ�ص��±�
int Array_Basic::BinarySearch(std::vector<int> &nums, int target, int flag)
{
    // ʹ��(void)ǿ��ת����ֹ���������棬flag�ڶ��ֲ�����û������
    (void) flag;
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
int Array_Basic::BinarySearch(std::vector<int> &nums, int target)
{
    std::cout << "[left, right)" << std::endl;
    // ����ҿ�ԭ��[left, right)����ʱ��left==rightʱ������Ч����
    int left = 0;
    int right = nums.size();

    // ��Ϊleft==right����Ч���䣬����left�����Ե���right
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (nums[mid] == target) // ��ȡ�������
        {
            return mid;
        }
        else if (nums[mid] > target) // �м�ֵ�ϴ���Ŀ��ֵһ�����м�ֵ�ұ�
        {
            // ����ҿ�ԭ�򣬴�ʱmid��ֵ����һ�ε��ұ߽磬������mid��ֵ
            right = mid;
        }
        else if (nums[mid] < target) // �м�ֵ��С����Ŀ��ֵһ�����м�ֵ���
        {
            // ����ҿ�ԭ�򣬴�ʱmid��ֵ����һ�ε���߽磬����mid��ֵ
            left = mid + 1;
        }
    }

    // û�ҵ�ָ��ֵ����-1
    return -1;
}

// ����35.��������λ��
class Solution35
{
public:
    int searchInsert(std::vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        int mid = 0;
        while (left <= right)
        {
            mid = left + ((right - left) >> 1);
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] > target)
            {
                right = mid - 1;
            }
            else if (nums[mid] < target)
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
class Solution69
{
public:
    int mySqrt(int x)
    {
        // �����ⷨ
        // size_t ans = 0;
        // for(;ans * ans <= x; ans++);
        // return (ans - 1);
        size_t left = 0;
        size_t right = x;
        size_t ans = 0;
        // ����ұ�����
        while (left <= right)
        {
            size_t mid = left + ((right - left) >> 1);
            // �����޷��ոպõ���
            // if(ans == x)
            // {
            //     ans = mid;
            //     break;
            // }
            if (mid * mid <= x) // �м�ֵ��С
            {
                ans = mid;
                left = mid + 1;
            }
            else if (mid * mid > x) // �м�ֵ�ϴ�
            {
                right = mid - 1;
            }
        }
        return ans;
    }
};

// ����69���ͣ�����367.��Ч����ȫƽ����
class Solution367
{
public:
    bool isPerfectSquare(int num)
    {
        size_t left = 0;
        size_t right = num;
        size_t ans = 0;
        // ����ұ�����
        while (left <= right)
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
class Solution34_1
{
public:
    // ���ֲ���
    int BinarySearch(std::vector<int> &nums, double target)
    {
        int left = 0;
        int right = nums.size();

        // ����ҿ�����
        while (left < right)
        {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] <= target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }

        return left;
    }

    std::vector<int> searchRange(std::vector<int> &nums, int target)
    {
        // ���������
        // ����߽�
        int leftHand = BinarySearch(nums, target - 0.5);
        // ���ұ߽�
        int rightHand = BinarySearch(nums, target + 0.5);
        // �ж�target�Ƿ������nums��

        // if(leftHand >= nums.size() || nums[leftHand] != target)
        // {
        //     return {-1, -1};
        // }
        // return {leftHand, rightHand - 1};

        // ����Ĵ���Ҳ���԰����������ʽд������ע�ⲻ����ʡ��ָ�����͵�vector<int>����Ϊ��ʱ�������޷�ȷ��{-1, -1}��{leftHand, rightHand - 1}�Ƿ���ͬһ������
        return leftHand >= nums.size() || nums[leftHand] != target
                   ? std::vector<int>{-1, -1}
                   : std::vector<int>{leftHand, rightHand - 1};
    }
};

// ֱ���ҵ����ұ߽�
class Solution34_2
{
public:
    std::vector<int> searchRange(std::vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size();

        // ����ҿ���������˵�
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            // <target��>=target
            if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        // �жϵ�ǰleft�Ƿ�ΪĿ��ֵ�Լ��Ƿ����Խ��
        if (left >= nums.size() || nums[left] != target)
        {
            return {-1, -1};
        }
        // �����¼��ǰleft
        int begin = left;

        // ����ҿ��������Ҷ˵�
        left = 0;
        right = nums.size();
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            // <=target��>target
            if (nums[mid] <= target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }

        // ��¼�Ҷ˵��λ��
        int last = left - 1;

        return {begin, last};
    }
};

// ţ��������Ŀ��JZ53 ���������������г��ֵĴ���
#include <vector>

class SolutionJZ53
{
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
    int BinarySearch(std::vector<int> &nums, double target)
    {
        int left = 0;
        int right = nums.size() - 1;
        // ����ұ�����
        while (left <= right)
        {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] <= target)
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

    int GetNumberOfK(std::vector<int> &nums, int k)
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
    int BinarySearch(int *nums, int numsLen, double k)
    {
        int left = 0;
        int right = numsLen - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] > k)
            {
                right = mid - 1;
            }
            else if (nums[mid] < k)
            {
                left = mid + 1;
            }
        }
        //���� left ������ mid
        return left;
    }

    int GetNumberOfK(int *nums, int numsLen, int k)
    {
        return BinarySearch(nums, numsLen, k + 0.5) - BinarySearch(nums, numsLen, k - 0.5);
    }
}

// ����852.ɽ������ķ嶥����
// �����ⷨ
// ���������ֵ
class Solution852_1
{
public:
    int peakIndexInMountainArray(std::vector<int> &nums)
    {
        int maxIndex = 0;
        for (size_t i = 0; i < nums.size(); i++)
            if (nums[i] > nums[maxIndex])
                maxIndex = i;

        return maxIndex;
    }
};

// ���ֲ���
class Solution852_2
{
public:
    int peakIndexInMountainArray(std::vector<int> &nums)
    {
        int left = 0;
        int right = nums.size();

        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] < nums[mid + 1])
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }

        return left;
    }
};

// ����162.Ѱ�ҷ�ֵ
// �����ⷨ
class Solution162_1
{
public:
    int findPeakElement(std::vector<int> &nums)
    {
        // ��������Сֵ
        int maxIndex = 0;
        for (size_t i = 0; i < nums.size(); i++)
            if (nums[i] > nums[maxIndex])
                maxIndex = i;

        return maxIndex;
    }
};

// ���ֲ���
class Solution162_2
{
public:
    int findPeakElement(std::vector<int> &nums)
    {
        int left = 0;
        int right = nums.size();

        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (mid + 1 < nums.size() && nums[mid] < nums[mid + 1])
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }

        return left;
    }
};

// ����153.Ѱ����ת���������е���Сֵ
// �����ⷨ
class Solution153_1 {
public:
    int findMin(std::vector<int>& nums) {
        // ��������Сֵ
        int minIndex = 0;
        for(size_t i = 0 ; i < nums.size(); i++)
            if(nums[i] < nums[minIndex])
                minIndex = i;

        return nums[minIndex];
    }
};

// ���ֲ���
class Solution153_2 {
public:
    int findMin(const std::vector<int>& nums)
    {
        int left = 0;
        int right = nums.size();
        int last = nums[right - 1];
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] > last)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }

        return nums[left];
    }
};

// LCR 173.����
// �����ⷨ
class SolutionLCR173_1
{
public:
    int takeAttendance(std::vector<int>& records)
    {
        size_t i = 0;
        for(; i <= records.size(); i++)
        {
            // ȱʧ���һ��ֵ
            if(i == records.size())
            {
                return records.size();
            }
            else if(records[i] != i)
            {
                break;
            }
        }

        return i;
    }
};

// λ����
class SolutionLRC173_2
{
public:
    int takeAttendance(std::vector<int>& records)
    {
        int ret = 0;
        for(size_t i = 0; i <= records.size(); i++)
        {
            if(i == records.size())
            {
                return records.size();
            }
            else if(records[i] ^ i)
            {
                ret = i;
                break;
            }
        }

        return ret;
    }
};

// ��ϣ��
class SolutionLCR173_3
{
public:
    int takeAttendance(std::vector<int>& records)
    {
        int hash[10001] = {0};

        for(auto num : records)
        {
            hash[num]++;
        }

        // ������ϣ���ҵ�Ϊ0λ�õ��±�
        int ret = 0;
        for(size_t i = 0; i < 10001; i++)
        {
            if(!hash[i])
            {
                ret = i;
                break;
            }
        }

        return ret;
    }
};

// �Ȳ�����
class SolutionLCR173_4
{
public:
    int takeAttendance(std::vector<int>& records)
    {
        return [&]() -> int{
            int sum = (records.size() + 0) * (records.size() + 1)/2;
            return sum;
        }() -
        std::accumulate(records.begin(), records.end(), 0);
    }
};

// ���ֲ���
class SolutionLCR173_5
{
public:
    int takeAttendance(std::vector<int>& nums)
    {
        int left = 0;
        int right = nums.size();

        while(left < right)
        {
            int mid = left + (right - left) / 2;
            if(nums[mid] == mid)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }

        return left;
    }
};