//
// Created by 18483 on 2024/10/20.
//

#include <vector>
#include <algorithm>
// ����27.�Ƴ�Ԫ��
// �����ⷨ������վ
// ˫ָ��ⷨ
class Solution27 {
public:
    int removeElement(std::vector<int>& nums, int val) {
        // ˫ָ��ⷨ
        // int count = 0;
        int fast = 0, slow = 0;
        while(fast < nums.size())
        {
            if(nums[fast] != val)
            {
                nums[slow++] = nums[fast];
            }
            fast++;
        }
        // return count;
        // Ҳ���Բ��ü�������ֱ�ӷ���slow
        return slow;
    }
};

// ����26.ɾ�����������е��ظ���
class Solution26 {
public:
    int removeDuplicates(std::vector<int>& nums) {
        // ˫ָ��ⷨ
        int size = nums.size();
        int slow = 0;
        int fast = 0;
        while(fast < nums.size())
        {
            if(nums[fast] != nums[slow])
            {
                // slow+1��ֹԽ��
                if(slow + 1 < nums.size())
                {
                    nums[slow + 1] = nums[fast];
                }
                slow++;
            }
            fast++;
        }

        return slow + 1;
    }
};

// ����283.�ƶ���
class Solution283 {
public:
    void moveZeroes(std::vector<int>& nums) {
        int prev = 0, cur = 0;
        while(cur < nums.size())
        {
            if(nums[cur])
                std::swap(nums[cur++], nums[prev++]);
            else
                cur++;
        }
    }
};

// ����844.�ȽϺ��˸���ַ�


// ����977.���������ƽ��
class Solution977_1 {
public:
    std::vector<int> sortedSquares(std::vector<int>& nums) {
        // β��+����
        std::vector<int> ret;
        for(auto num : nums)
        {
            ret.push_back(num * num);
        }
        std::sort(ret.begin(), ret.end());
        return ret;
    }
};