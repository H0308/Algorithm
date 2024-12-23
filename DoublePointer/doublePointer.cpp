//
// Created by 18483 on 2024/11/24.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ����80.ɾ�����������е��ظ����
// ˫ָ�룬�����±����Ϊ2����ֻ���������ظ�����
class Solution80
{
public:
    int removeDuplicates(vector<int>& nums)
    {
        if(nums.size() <= 2)
            return nums.size();
        int slow = 2, fast = 2;

        while(fast < nums.size())
        {
            if(nums[slow - 2] != nums[fast])
            {
                nums[slow] = nums[fast];
                slow++;
            }
            fast++;
        }

        return slow;
    }
};

// ����283.�ƶ���
class Solution283
{
public:
    void moveZeroes(vector<int> &nums)
    {
        for (int left = 0, right = 0; right < nums.size(); right++)
        {
            if (nums[right] != 0)
            {
                swap(nums[left], nums[right]);
                left++;
            }
        }
    }
};

// ����1089.��д��
// �ⷨ1������
class Solution1089_1
{
public:
    void duplicateZeros(vector<int> &arr)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] == 0)
            {
                for (int j = arr.size() - 1; j > i; j--)
                    arr[j] = arr[j - 1];
                i++;
            }
        }
    }
};

// �ⷨ2����ظ�д
class Solution1089_2
{
public:
    void duplicateZeros(vector<int> &arr)
    {
        vector<int> nums(arr.size());

        for (int i = 0, j = 0; i < arr.size() && j < nums.size(); i++, j++)
        {
            if (arr[i] == 0 && j + 1 < nums.size())
            {
                nums[j] = nums[j + 1] = 0;
                j++;
            }
            else
                nums[j] = arr[i];
        }

        arr = nums;
    }
};

// �ⷨ3��˫ָ��
class Solution1089_3
{
public:
    void duplicateZeros(vector<int> &arr)
    {
        int left = 0;
        int right = -1;

        // �ҵ�����д��λ��
        while (left < arr.size())
        {
            if (arr[left])
                right++;
            else
                right += 2;

            if (right >= arr.size() - 1)
                break;
            left++;
        }

        // �����߽����
        if (right == arr.size())
        {
            arr[right - 1] = 0;
            left--;
            right -= 2;
        }

        // ��д
        while (left >= 0)
        {
            if (arr[left])
                arr[right--] = arr[left--];
            else
            {
                arr[right--] = 0;
                arr[right--] = 0;
                left--;
            }
        }
    }
};

// ����202.������
// �ⷨ1����ϣ������ϣ���֣�
// �ⷨ2��˫ָ��
class Solution202
{
public:
    int calQrt(int n)
    {
        int temp = n;
        int sum = 0;
        while (temp)
        {
            int r = temp % 10;
            temp /= 10;

            sum += (r * r);
        }

        return sum;
    }

    bool isHappy(int n)
    {
        int slow = n;
        int fast = n;

        while (slow != 1)
        {
            slow = calQrt(slow);
            fast = calQrt(calQrt(fast));

            if (slow == fast && slow != 1)
                return false;
        }

        return true;
    }
};

// ����11.ʢ���ˮ������
class Solution11
{
public:
    int maxArea(vector<int> &height)
    {
        int maxV = 0;
        for (int left = 0, right = height.size() - 1; left < right;)
        {
            while (left < right && height[left] <= height[right])
            {
                // �����ȼ����������ֹ©����
                maxV = max(maxV, (right - left) * height[left]);
                left++;
            }

            while (left < right && height[left] > height[right])
            {
                maxV = max(maxV, (right - left) * height[right]);
                right--;
            }
        }

        return maxV;
    }
};

// ����611.��Ч�����εĸ���
// ������ʹ����е�����
// �̶�һ�������ߣ�������������߲�������ʼλ�õ�ֵ
// �̶�����ʼλ�þ��޷�ʹ�õ����Խ��
class Solution611
{
public:
    int triangleNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int count = 0;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            for (int left = 0, right = i - 1; left <= right;)
            {
                if (nums[right] + nums[left] > nums[i])
                {
                    count += right - left;
                    right--;
                }
                else
                    left++;
            }
        }

        return count;
    }
};

// ����LCR179.�����ܼ۸�ΪĿ��ֵ��������Ʒ
// ��������֮�����棬��������֮��˫ָ��˼·�ⷨ����ȷ���ж�
class SolutionLCR179
{
public:
    vector<int> twoSum(vector<int> &price, int target)
    {
        for (int left = 0, right = price.size() - 1; left < right;)
        {
            if (price[left] + price[right] > target)
                right--;
            else if (price[left] + price[right] < target)
                left++;
            else
                return {price[left], price[right]};
        }

        return {};
    }
};

// ����15.����֮��
// ������ǰ����Ч�����ε�˼·һ�£�������Ҫ����ȥ��
// ��Ϊ�Ѿ��������Զ��ں�Ϊ0����������˵��һ�������ظ�
// ��һ����һ�����Կ���һֱ����ֱ���������ظ���ֵ
class Solution15
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        // ��¼���
        vector<vector<int>> ret;
        // ��������
        sort(nums.begin(), nums.end());

        // ö�����ֵ
        for (int i = nums.size() - 1; i >= 0;)
        {
            for (int left = 0, right = i - 1; left < right;)
            {
                int sum = nums[left] + nums[right] + nums[i];
                if (sum < 0)
                    left++;
                else if (sum > 0)
                    right--;
                else
                {
                    ret.push_back({nums[left], nums[right], nums[i]});
                    // ���µ��¼���
                    left++;
                    right--;
                    // ��left��right������ȥ�أ�ע��Խ������Ĵ���
                    while (left < right && nums[left] == nums[left - 1])
                        left++;
                    while (right > left && nums[right] == nums[right + 1])
                        right--;
                }
            }

            i--;
            // �Ի���ȥ�أ�ע��Խ������Ĵ���
            while (i >= 0 && nums[i] == nums[i + 1])
                i--;
        }

        return ret;
    }
};

// ����18.����֮��
// ���������˼·һ�£�������Ϊ���ĸ�����������Ҫͨ��i��jö������ֵ
// nums[i] + nums[j] = -(nums[left] + nums[right])
class Solution18
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        int sz = nums.size();
        for (int i = 0; i < sz;)
        {
            //  ����֮��˼·
            for (int j = i + 1; j < sz;)
            {
                // ע�����ͷ�Χ
                long long rest = (long long)target - nums[i] - nums[j];
                int left = j + 1;
                int right = sz - 1;
                // ����֮��˼·
                while (left < right)
                {
                    int sum = nums[left] + nums[right];
                    if (sum > rest)
                        right--;
                    else if (sum < rest)
                        left++;
                    else
                    {
                        ret.push_back({nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        right--;
                        while (left < right && nums[left] == nums[left - 1])
                            left++;
                        while (left < right && nums[right] == nums[right + 1])
                            right--;
                    }
                }
                j++;
                while (j < sz && nums[j] == nums[j - 1])
                    j++;
            }
            i++;
            while (i < sz && nums[i] == nums[i - 1])
                i++;
        }
        return ret;
    }
};