//
// Created by 18483 on 2024/10/22.
//
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <numeric>
// #include <bits/stdc++.h>
// 力扣209.长度最小的子数组
// 暴力解法，见网站
/*
 * 暴力解法基本思路：
 * 外层循环固定为起始位置，内层循环固定为终止位置
 * 通过内层循环的不断进行一直计算sum以及子数组长度
 * 当sum>=target时就跳出内层循环更新外层循环，内层循环再从外层循环下标位置继续寻找
 * 这里内层循环不要从头开始，否则内层循环和外层循环构成的区间并不是有效区间，例如i=1,j=0，构成的区间为[1,0]
 */
// 双指针——滑动窗口算法
/*
 * 滑动窗口的本质还是双指针，之所以叫滑动窗口本质就是通过终止位置的不断移动，
 * 满足条件时不断更新起始位置直到条件重新不成立，再继续更新终止位置
 * 对于本题而言，暴力解法中的循环主要以起始位置为主，所以导致循环复杂度增加
 */
class Solution209
{
public:
    int minSubArrayLen(int target, std::vector<int> &nums)
    {
        int start = 0;
        int len = INT_MAX; // 定义为最大值可以确保比较时一定可以取到最小值
        int sum = 0;
        for (int end = 0; end < nums.size(); end++)
        {
            // 通过end移动计算起始位置和终止位置区间的和sum
            sum += nums[end];
            // 如果sum大于等于target，说明已经找到符合条件的子数组，可以更新sum和start，准备下一次寻找子数组
            // 此处需要循环判断sum是否在start更新时依旧满足sum>=target，不满足时再更新end继续计算和
            // 否则就相当于移出窗口
            while (sum >= target)
            {
                // 先计算当前满足条件时的下标
                len = std::min(len, end - start + 1);
                // 更新start和sum
                sum -= nums[start];
                start++;
            }
        }

        // 如果不存在指定的子数组，则返回0
        if (len == INT_MAX)
        {
            return 0;
        }

        return len;
    }
};

// 力扣904.水果成篮
/*
 * 根据题目的描述，可以联想出本题涉及到一个窗口的进入和更新
 * 窗口进入：当前元素不存在时，插入到当前容器
 * 窗口更新：当元素个数超过两个时，考虑更新窗口直到重新满足条件
 * 本题并没有提到每一个元素只出现一次，但是需要确保容器中只有两个元素，所以需要用到可以去重的容器
 * 可以选择的结构：红黑树，容器对应的就是set和map，也可以考虑使用unordered_map或者unordered_set
 * 但是在更新窗口时，如果直接删除容器中的元素可能会因为每一个元素不止出现一次导致提前更新窗口
 * 例如[3,3,3,1,2,1,1,2,3,3,4]，如果直接使用一个红黑树容器，在插入时3,1,2，此时size为3需要更新窗口
 * 进入循环更新逻辑时，因为没有对元素进行计数，导致set直接删除start指向的第一个3，现在size重新回到2，循环提前结束
 * 所以可以考虑使用map或者unordered_map，如果元素不存在直接插入，否则只更新计数器
 * 最后，更新计数器不可以在更新窗口中更新，因为不能确定一定会出现3种水果
 */
class Solution904
{
public:
    int totalFruit(std::vector<int> &fruits)
    {
        int start = 0;
        int len = 0;
        std::unordered_map<int, int> m; // 使用unordered_map，查找的时间复杂度为O(1)
        for (int end = 0; end < fruits.size(); end++)
        {
            // 确定元素是否存在，不存在就添加
            m[fruits[end]]++;
            // 当不满足条件：两个篮子中的水果种类大于2种时调整窗口
            while (m.size() > 2)
            {
                // 直到指定元素的计数器为0时才删除，否则一直减少计数器
                if ((--(m.find(fruits[start])->second)) == 0)
                {
                    m.erase(fruits[start]);
                }
                // 更新窗口
                start++;
            }

            // 更新长度
            len = std::max(len, end - start + 1);
        }

        return len;
    }
};

// 力扣76.最小覆盖子串
/*
 * 本题暴力思路：枚举出所有包含查找子串的所有字符的字符串，比较长度取出最小的子串
 * 本题可以考虑使用滑动窗口的方法
 * 为什么：根据暴力解法，每一次枚举所有包含的子串这个过程中涉及到一些重复的步骤，例如已经完全包含内容的子串被多次枚举
 * 而如果需要将这个过程中的枚举次数减少，策略就是找到最接近最优解的一个子串，整个遍历过程中，当一个指针在遍历s字符串时
 * 这个指针离起始位置的距离越来越远，此时与起始位置的指针就构成一个区间，而当刚好满足找到子串的条件时，就需要减小区间
 * 确保能找到更小一点的区间，而这个过程就正好满足不定长滑动窗口的过程
 * 怎么用：
 * 1. 题目提到了t字符串中的重复字符也需要完全匹配，所以需要使用哈希表来统计出现的次数
 * 2. 构建窗口：在t字符串的哈希表m中找s字符串中的字符，如果出现添加到另一个哈希表c中进行计数，方便更新窗口时比较
 * 3. 更新窗口：当哈希表m中字符的个数与c中对应的字符个数相同，说明一定存在子串包含t中的所有字符，此时就需要更新窗口
 *             否则一定不需要更新窗口。更新窗口的过程中需要记录当前子串的长度已经起始位置方便最后截取字符串，
 *             更新逻辑：让c中的字符个数与m中的字符个数不匹配，即类似于从c中依次移除出现于t中的字符
 * 4. 本题只需要考虑短的字符串中的字符即可，对于s字符串来说，其他字符是否存在不需要考虑
 *
 */
// 滑动窗口
class Solution76
{
public:
    // 哈希表统计数量——定义为成员，方便checkNum函数调用
    std::unordered_map<char, int> m, c;

    // 判断t字符串中字符的个数是否与存在于c中的字符个数相同
    int checkNum()
    {
        for (auto &ch: m)
        {
            // 如果个数不匹配直接返回false
            if (c[ch.first] < ch.second)
            {
                return false;
            }
        }

        // 循环走完说明个数一致
        return true;
    }

    std::string minWindow(std::string s, std::string t)
    {
        // 定义s字符串的窗口端点
        int l = 0, r = 0;
        int len = INT_MAX;
        int ret = -1;
        // 统计字符串t中的字符和个数
        for (auto &ch: t)
        {
            m[ch]++;
        }

        // 构建滑动窗口
        int sz = s.size();
        while (r < sz)
        {
            // 如果s中的字符存在于t中，就插入并计数——构建窗口
            if (m.find(s[r]) != m.end())
            {
                c[s[r]]++;
            }

            // 更新窗口
            // 何时更新：当找到了足够的字符与t中的字符匹配并且区间有效时
            while (checkNum())
            {
                // 如何更新：进入循环说明一定已经找到了满足条件的子串
                // 先更新长度，最后需要通过变量取出返回的子串
                if (r - l + 1 < len)
                {
                    len = r - l + 1;
                    // 更新用于截取子串的起点
                    ret = l;
                }

                // 缩短窗口，判断是否还有满足条件的更短窗口
                if (m.find(s[l]) != m.end())
                {
                    c[s[l]]--;
                }

                l++;
            }

            r++;
        }

        return ret == -1 ? std::string() : s.substr(ret, len);
    }
};

// 力扣3. 无重复字符的最长子串
// 滑动窗口解法
class Solution3
{
public:
    int lengthOfLongestSubstring(std::string s)
    {
        std::unordered_map<char, int> m;
        int len = 0;
        for (int start = 0, end = 0; end < s.size(); end++)
        {
            // 进入窗口
            // 向哈希表中添加字符，如果字符存在就改变计数器
            m[s[end]]++;

            // 更新窗口——目的是为了移除重复的元素
            while (m[s[end]] > 1)
            {
                m.find(s[start++])->second--;
            }
            len = std::max(len, end - start + 1);
        }

        return len;
    }
};

// 力扣1004.最大连续1的个数Ⅲ
// 滑动窗口算法
/* 本题的主要思路就是通过记录0的个数（变向达到翻转0的目的）来构建一个滑动窗口
 * 本题需要注意使用一个计数器统计0的个数而非通过一个变量依次减少直到小于k
 * 因为小于k不止一个情况，例如k=2时，tmpk可以有0,1两种情况都小于k，甚至逻辑上还有可能存在负数
 * 但是考虑到大于k只需要考虑一次，尽管大于k有3,4...多种情况，但是第一次大于k只有一种情况
 * 所以通过计数器改变统计当前0的个数
 */
class Solution1004
{
public:
    int longestOnes(std::vector<int> &nums, int k)
    {
        int len = 0;
        // int tmpk = k;
        int zeroNum = 0;

        for (int left = 0, right = 0; right < nums.size(); right++)
        {
            // 变量依次减少的方式——复杂且不易控制
            // if(nums[end] == 0)
            // {
            //     tmpk--;
            // }

            // while(tmpk < k)
            // {

            // }

            // 进窗口
            if (nums[right] == 0)
            {
                zeroNum++;
            }

            // 更新窗口
            while (zeroNum > k)
            {
                // 不要在循环内部更新结果
                // len = max(len, right - left + 1);
                if (nums[left++] == 0)
                {
                    zeroNum--;
                }
            }
            // 注意，题目提到最多翻转k个0，所以可能出现翻转0,1,2,3...k
            // 言外之意就是翻转0的个数小于等于k
            // 故存在k特别大而zero一直不可能大于k的情况
            // 综上，考虑在循环外部更新结果
            len = std::max(len, right - left + 1);
        }

        return len;
    }
};

// 力扣1658.将x减到0的最小操作数
/*
 * 本题使用到正难则反的策略
 * 因为本题既要考虑左侧又要考虑右侧，但是连续的部分是中间区域
 * 所以本题就可以转换为“求出最长的一段区间（此时剩余区间就是最小的）其中的和大于等于数组和sumNums-x”
 * 需要注意本题有两个特殊情况:
 * 1. 当sumNums-x == 0时，此时最小的操作数的个数就是整个数组
 * 2. 当sumNums-x < 0时，说明无法使x减到0，自然也就无法算出sumNums-x == target的情况
 */
class Solution1658 {
public:
    int minOperations(std::vector<int>& nums, int x) {
        int target = std::accumulate(nums.begin(), nums.end(), 0) - x;
        // 特判，当target刚好为0，说明此时最小的操作数的个数就是整个数组
        if(target == 0)
        {
            return nums.size();
        }
        // 定义变量记录区间和
        int sum = 0;
        // 定义变量记录区间长度
        int len = -1;
        for(int start = 0, end = 0; end < nums.size(); end++)
        {
            // 进入窗口
            sum += nums[end];

            // 更新窗口
            while(sum > target && start < end)
            {
                sum -= nums[start++];
            }

            // 可能存在数组中的数据无法使x减到0，自然也就无法算出sumNums-x == target的情况
            if(sum == target)
            {
                len = std::max(len, end - start + 1);
            }
        }

        // 返回最长区间的其他区间总长度即为所求
        return len == -1 ? -1 : nums.size() - len;
    }
};

// //其他写法
// class Solution1658 {
// public:
//     int minOperations(std::vector<int>& nums, int x) {
//         int sum = 0;
//         for (int a : nums)
//             sum += a;
//         int target = sum - x;
//         // 细节问题
//         if (target < 0)
//             return -1;
//         int ret = -1;
//         for (int left = 0, right = 0, tmp = 0; right < nums.size(); right++) {
//             tmp += nums[right];      // 进窗?
//             while (tmp > target)     // 判断
//                 tmp -= nums[left++]; // 出窗?
//             if (tmp == target)       // 更新结果
//                 ret = std::max(ret, right - left + 1);
//         }
//         // 此处包括了一种情况：当x与sumNums完全相等的时候，此时区间和永远大于target，因为target为0
//         if (ret == -1)
//             return ret;
//         else
//             return nums.size() - ret;
//     }
// };

// 力扣438.找到字符串中所有字母异位词
// 滑动窗口算法——定长窗口
// 使用库版本
class Solution438_1 {
public:
    std::unordered_map<char, int> ori, sub;
    bool check() {
        for (auto kv : sub) {
            if (ori[kv.first] != kv.second) {
                return false;
            }
        }

        return true;
    }
    std::vector<int> findAnagrams(std::string s, std::string p) {
        std::vector<int> v;
        for(auto ch : p)
        {
            sub[ch - 'a']++;
        }
        for(int left = 0, right = 0; right < s.size(); right++)
        {
            // 进入窗口
            ori[s[right] - 'a']++;

            // 更新窗口
            if(right - left + 1 > p.size())
            {
                ori[s[left] - 'a']--;
                left++;
            }

            // 更新结果
            if(check())
            {
                v.push_back(left);
            }
        }

        return v;
    }
};

// 直接定址法
// 元素有限时，可以考虑使用直接定址法，减少时间和空间的消耗
class Solution438_2 {
public:
    // 元素个数有限时，可以考虑使用直接定址法，减少时间和空间的消耗
    int ori[26] = {0}, sub[26] = {0};
    bool check() {
        for(size_t i = 0; i < 26; i++)
        {
            if(ori[i] != sub[i])
            {
                return false;
            }
        }

        return true;
    }

    std::vector<int> findAnagrams(std::string s, std::string p) {
        std::vector<int> v;
        for(auto ch : p)
        {
            sub[ch - 'a']++;
        }
        for(int left = 0, right = 0; right < s.size(); right++)
        {
            // 进入窗口
            ori[s[right] - 'a']++;

            // 更新窗口
            if(right - left + 1 > p.size())
            {
                ori[s[left] - 'a']--;
                left++;
            }

            // 更新结果
            if(check())
            {
                v.push_back(left);
            }
        }

        return v;
    }
};

// 优化比较逻辑版本
class Solution438_3 {
public:
    // 元素个数有限时，可以考虑使用直接定址法，减少时间和空间的消耗
    int ori[26] = {0}, sub[26] = {0};
    std::vector<int> findAnagrams(std::string s, std::string p) {
        std::vector<int> v;
        // 存储有效字符个数
        int count = 0;
        for(auto ch : p)
        {
            sub[ch - 'a']++;
        }
        for(int left = 0, right = 0; right < s.size(); right++)
        {
            // 进入窗口
            ori[s[right] - 'a']++;
            // 维护有效字符个数
            // 当字符进入窗口后，如果当前比较的字符存在与ori中，但不存在于sub中，那么说明不是有效字符，count不变
            // 如果既存在于ori，也存在于sub中，说明是有效字符
            // 注意需要小于等于而不是仅等于，因为可能存在重复字符
            if(ori[s[right] - 'a'] <= sub[s[right] - 'a'])
            {
                count++;
            }

            // 更新窗口
            if(right - left + 1 > p.size())
            {
                // 出窗口前维护有效字符个数
                // 维护有效字符个数有三种情况：
                // 1. 当出去的字符在哈希表ori中的个数比哈希表sub中的多，此时说明移出去的是多余的字符，不需要更新count
                // 2. 当出去的字符在哈希表ori中的个数与哈希表sub中的相等，此时说明有效字符被移除，需要更新count
                // 3. 当出去的字符在哈希表ori中不存在，但是在哈希表sub中存在，此时个数关系就是小于
                //    当前这个情况就是说明sub中有重复的字符，此时ori中只出现了一次这个重复字符但是要被移除，
                //    所以依旧是有效字符被移除，需要更新count，例如s="abacc" p="abbc"
                if(ori[s[left] - 'a'] <= sub[s[left] - 'a'])
                {
                    count--;
                }

                ori[s[left] - 'a']--;
                left++;
            }

            // 更新结果优化版
            // 如果有效字符个数与p的长度相同，则一定是异位词
            if(count == p.size())
            {
                v.push_back(left);
            }
        }

        return v;
    }
};

// 力扣30.串联所有单词的子串
class Solution30 {
public:
    std::unordered_map<std::string, int> ori, sub;
    std::vector<int> findSubstring(std::string s, std::vector<std::string>& words) {
        std::vector<int> v;
        for(auto& str : words)
        {
            sub[str]++;
        }
        // 每个单词的长度
        int sz = words[0].size();
        // 控制滑动窗口执行的次数
        for(int count = 0; count < sz; count++)
        {
            // 滑动窗口
            // right+sz总共就是words的总长度，所以需要注意可以相等
            for(int left = count, right = count, cnt = 0; right + sz <= s.size(); right += sz)
            {
                // 进入窗口
                std::string str = s.substr(right, sz);
                ori[str]++;
                // 判断是否更新有效字符个数
                // 先判断sub中有对应的字符串，再比较
                if(sub.count(str) && ori[str] <= sub[str])
                {
                    cnt++;
                }

                // 更新窗口
                if(right - left + 1 > sz * words.size())
                {
                    std::string tmp = s.substr(left, sz);
                    // 更新计数器
                    if(sub.count(tmp) &&ori[tmp] <= sub[tmp])
                    {
                        cnt--;
                    }

                    ori[tmp]--;
                    left += sz;
                }

                // 更新结果
                if(cnt == words.size())
                {
                    v.push_back(left);
                }
            }
            ori.clear();
        }
        return v;
    }
};