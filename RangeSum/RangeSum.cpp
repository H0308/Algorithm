//
// Created by 18483 on 2024/10/30.
//
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// 卡码网KamaCoder58.区间和：暴力解法
int main58_1()
{
    // 解除同步
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // 输入数组长度
    int len = 0;
    cin >> len;

    vector<int> arr(len);

    for (int i = 0; i < len; i++)
    {
        cin >> arr[i];
    }

    int a = 0, b = 0;
    int sum = 0;
    while (cin >> a >> b)
    {
        for (int i = a; i <= b; i++)
        {
            sum += arr[i];
        }
        cout << sum << endl;

        sum = 0;
    }

    return 0;
}

// 卡码网KamaCoder58.区间和：前缀和解法——写法1
int main58_2()
{
    // 解除同步
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // 输入数组长度
    int len = 0;
    cin >> len;

    vector<int> arr(len);
    // 前缀和数组
    vector<int> prefixSum(len + 1, 0);

    for (int i = 0; i < len; i++)
    {
        cin >> arr[i];
        // 计算前缀和：前i个元素的和
        prefixSum[i + 1] = prefixSum[i] + arr[i];
    }

    int a = 0, b = 0;
    while (cin >> a >> b)
    {
        // 输出区间和
        cout << prefixSum[b + 1] - prefixSum[a] << endl;
    }

    return 0;
}

// 卡码网KamaCoder58.区间和：前缀和解法——写法2
int main58_3()
{
    // 解除同步
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // 输入数组长度
    int len = 0;
    cin >> len;

    // 元素数组
    vector<int> arr(len);
    // 前缀和数组
    vector<int> sum(len);

    int preSum = 0;
    for (int i = 0; i < len; i++)
    {
        cin >> arr[i];

        // 计算前缀和
        preSum += arr[i];
        sum[i] = preSum;
    }

    int a = 0, b = 0;
    while (cin >> a >> b)
    {
        // 求和
        if (a == 0)
        {
            cout << sum[b] << endl;
        }
        else
        {
            cout << sum[b] - sum[a - 1] << endl;
        }
    }

    return 0;
}


// 卡码网KamaCoder44.开发商购买土地
int main44()
{
    int n = 0, m = 0;
    while (cin >> n >> m)
    {
        vector<vector<int>> arr(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> arr[i][j];
            }
        }

        int minNum = INT_MAX;
        // 统计总和
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                sum += arr[i][j];
            }
        }

        // 横向划分
        // 注意保证至少有一方有一块区域
        for (int i = 0; i < n - 1; i++)
        {
            int sumA = 0;
            // 给A划分区域
            for (int x = 0; x <= i; x++)
            {
                for (int y = 0; y < m; y++)
                {
                    sumA += arr[x][y];
                }
            }

            int sumB = sum - sumA;
            minNum = min(minNum, abs(sumA - sumB));
        }

        // 纵向划分
        for (int j = 0; j < m - 1; j++)
        {
            int sumA = 0;
            // 给A划分区域
            for (int x = 0; x < n; x++)
            {
                for (int y = 0; y <= j; y++)
                {
                    sumA += arr[x][y];
                }
            }

            int sumB = sum - sumA;
            minNum = min(minNum, abs(sumA - sumB));
        }

        cout << minNum << endl;
    }

    return 0;
}

// 牛客网DP34.【模版】前缀和
int mainDP34()
{
    int n, q;
    while (cin >> n >> q)
    {
        // 注意使用long long防止溢出
        long long sumArr = 0;
        vector<long long> arr(n);
        vector<long long> sum(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            sumArr += arr[i];
            sum[i] = sumArr;
        }

        int l = 0, r = 0;
        for (int i = 0; i < q; i++)
        {
            cin >> l >> r;

            if (l - 1 == 0)
            {
                cout << sum[r - 1] << endl;
            }
            else
            {
                cout << sum[r - 1] - sum[l - 2] << endl;
            }
        }
    }
}

// 牛客网DP35.【模版】二维前缀和
int mainDP35()
{
    int n = 0, m = 0;
    int q = 0;
    while (cin >> n >> m >> q)
    {
        // 原数组
        vector<vector<long long>> arr(n + 1);
        for (auto &v: arr)
        {
            v.resize(m + 1);
        }
        // 和数组
        vector<vector<long long>> sum(n + 1);
        for (auto &v: sum)
        {
            v.resize(m + 1);
        }

        // 读取数组并填充前缀和
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> arr[i][j];

                // 填充前缀和数组
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] + arr[i][j] - sum[i - 1][j - 1];
            }
        }

        int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
        // 使用前缀和数组
        for (int i = 0; i < q; i++)
        {
            cin >> x1 >> y1 >> x2 >> y2;
            cout << sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1] << endl;
        }
    }
}

// 力扣724.寻找数组的中心下标
// 解法1：直接使用前缀和数组
/*
 * 本题需要利用到前缀和数组，求出前缀和数组后，遍历前缀和数组，
 * 如果找到一个下标i，满足sum[i-1] == sum[n] - sum[i]，则返回i-1，否则返回-1
 * 注意，前缀和的有效元素下标是从1开始的，所以返回的下标需要减1
 */
class Solution724_1
{
public:
    int pivotIndex(vector<int> &nums)
    {
        vector<int> sum(nums.size() + 1);
        // 求出前缀和数组
        for (int i = 1; i <= nums.size(); i++)
        {
            sum[i] = nums[i - 1] + sum[i - 1];
        }

        // 使用前缀和数组
        int index = 0;
        int back = sum[sum.size() - 1];
        for (int i = 1; i < sum.size(); i++)
        {
            if (back - sum[i] == sum[i - 1])
            {
                index = i;
                break;
            }
        }

        return index - 1 == nums.size() ? -1 : index - 1;
    }
};

// 解法2：前缀和数组与后缀和数组
/*
 * 使用两个数组分别构建前缀和与后缀和，因为需要找的中心下标的值在判断过程中是不包括的
 * 所以可以考虑计算前缀和时只考虑[0, i - 1]区间的值，为了形成错位并且保证不出现越界问题
 * 需要满足前缀和数组第一个元素为0
 * 与前缀和数组一样，后缀和数组也不需要考虑第i个位置的值，但是后缀和是从右侧向左侧进行计算
 * 所以只需要考虑区间[i + 1, n - 1]中的元素之和即可，
 * 后缀和数组的左侧第一个元素就代表右侧区间[i + 1, n - 1]所有元素的和
 * 注意，本题的前缀和数组和后缀和数组与原数组均是nums.size的长度
 * 得出递推公式：
 * 前缀和prefix[i] = prefix[i - 1] + nums[i - 1]，其中i从1开始，prefix[0] = 0
 * 后缀和suffix[i] = suffix[i + 1] + nums[i + 1]，其中i从nums.size() - 1开始，suffix[nums.size() - 1] = 0
 */
class Solution724_2
{
public:
    int pivotIndex(vector<int> &nums)
    {
        vector<int> prefix(nums.size());
        vector<int> suffix(nums.size());

        // 构建前缀和
        // 因为只需要考虑[0, i - 1]区间中的值，所以第i位的值可以不用考虑
        // 当前情况下，前缀和数组的一个元素为0
        // 因为当i=0时，区间为[0, -1]，是一个不存在的区间
        for (int i = 1; i < nums.size(); i++)
            prefix[i] = nums[i - 1] + prefix[i - 1];
        // 构建后缀和
        // 因为只需要考虑[i + 1, size - 1]区间中的值，所以第i位的值可以不用考虑
        // 为了形成错位，需要将suffix[size-1]置为0
        for (int i = nums.size() - 2; i >= 0; i--)
            suffix[i] = nums[i + 1] + suffix[i + 1];

        // 使用前缀和与后缀和
        for (int i = 0; i < nums.size(); i++)
        {
            if (suffix[i] == prefix[i])
            {
                return i;
            }
        }

        return -1;
    }
};

// 力扣238.除自身以外数组的乘积
/*
 * 本题与上题思路基本一样，使用两个数组，分别表示前缀积和后缀积
 */
class Solution238
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        // 处理结果
        vector<int> ret;

        // 前缀积数组
        vector<int> prefix(nums.size(), 1);
        // 后缀积数组
        vector<int> suffix(nums.size(), 1);

        // 构建前缀积数组
        for (int i = 1; i < nums.size(); i++)
            prefix[i] = prefix[i - 1] * nums[i - 1];

        // 构建后缀积数组
        for (int i = nums.size() - 2; i >= 0; i--)
            suffix[i] = suffix[i + 1] * nums[i + 1];

        for (int i = 0; i < nums.size(); i++)
            ret.push_back(prefix[i] * suffix[i]);

        return ret;
    }
};

// 力扣560.和为k的子数组
// 错误：滑动窗口
/*
 * 本题第一反应是使用滑动窗口来解决，但是本题数组中的元素涉及到负数，
 * 导致在遍历过程中不满足单调性，从而会产生遗漏情况，所以不可以使用滑动窗口算法解决
 */
class Solution560_false
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int sum = 0;
        int count = 0;
        for (int left = 0, right = 0; right < nums.size(); right++)
        {
            // 进窗口
            sum += nums[right];

            // 更新窗口
            while (sum >= k && left <= right)
            {
                if (sum == k)
                {
                    count++;
                }
                sum -= nums[left++];
            }
        }

        return count;
    }
};

// 前缀和+哈希表
/*
 * 本题要找到和为k的子数组，最简单的方法就是暴力枚举，但是其时间复杂度较高，
 * 此时如何结合前缀和解决就是解题关键。
 * 考虑使用一种思路：找到以i结尾的和为k的子数组
 * 为什么使用这种思路：以i结尾可以保证在前缀和数组中i-1位置一定是前面所有元素之和
 * 而题目要求和为k的子数组，此时就只需要在[0, i-1]区间内找到和为k的子数组
 * 这里考虑找和为当前位置的前缀和sum减去k，得出一个新的区间，
 * 这个区间的出现就代表一定在[0, i-1]内存在一个和为k的子数组
 * 之所以需要反向找是因为直接查找与暴力枚举思路一致，导致效率低下且没有利用到前缀和的特性
 * 其次，为了进一步保证复杂度不会退化到暴力枚举的程度，可以借助哈希表结构统计当前区间中出现sum-k的次数
 * 这个次数就代表了多少个和为k的子数组，如果哈希表中已经存在sum-k，就说明之前已经出现过一次子数组，否则就更新次数即可
 * 未解决：
 * 1. 为什么是[0, i-1]区间
 * 2. 为什么需要求sum-k而不直接是k
 * 3. 为什么要使用哈希表统计次数
 */
class Solution560
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        // 统计个数
        unordered_map<int, int> cnt;
        // 如果整个数组的元素和为k，则也必须算一次
        cnt[0] = 1;

        int sum = 0;
        int ret = 0;
        for (auto num: nums)
        {
            // 求前缀和
            sum += num;
            // 判断当前前缀和是否等于sum - k
            // 如果等于sum-k代表当前区间内一定存在一个和为k的子数组
            if (cnt.find(sum - k) != cnt.end())
            {
                ret += cnt[sum - k];
            }
            // 记录当前前缀和出现的次数
            cnt[sum]++;
        }

        return ret;
    }
};

// 力扣974.和可被K整除的子数组
/*
 * 本题根据同余定理可以将题目转化为在前缀和数组中找tempSum%k==sum%k的子数组，注意取余运算的修正
 * 剩余思路与上题基本一致
 */
class Solution974
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        // 统计前缀和出现的次数
        unordered_map<int, int> cnt;
        cnt[0] = 1;

        int sum = 0;
        int ret = 0;
        for (auto num: nums)
        {
            // 指定区间的前缀和
            sum += num;
            // 取余运算修正
            int rest = (sum % k + k) % k;
            // 如果当前rest存在于哈希表，说明满足sum%k等于之前的余数beforeSum % k
            if (cnt.find(rest) != cnt.end())
            {
                ret += cnt[rest];
            }

            cnt[rest]++;
        }

        return ret;
    }
};

// 力扣525.连续数组
class Solution525
{
public:
    int findMaxLength(vector<int> &nums)
    {
        unordered_map<int, int> cnt;
        cnt[0] = -1;

        // 将数组所有的0置为-1
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                nums[i] = -1;
            }
        }

        // 在数组中找前缀和为sum的最长子数组
        int sum = 0;
        int ret = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            // 求前缀和
            sum += nums[i];

            // 哈希表中存储的是前缀和，当遇到了前缀和为sum时就更新当前长度
            if (cnt.find(sum) != cnt.end())
            {
                ret = max(ret, i - cnt[sum]);
            }
            else
            {
                cnt[sum] = i;
            }
        }

        return ret;
    }
};

// 力扣1314.矩阵区域和
/*
 * 本题的关键就是理解题意以及对边界的处理，剩余的就是二维前缀和的基本构建和使用
 */
class Solution1314
{
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>> &mat, int k)
    {
        int m = mat.size();
        int n = mat[0].size();
        // 构建前缀和数组
        vector<vector<int>> sum(m + 1, vector<int>(n + 1));

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + mat[i - 1][j - 1];
            }
        }

        // 使用前缀和数组
        int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
        vector<vector<int>> ans(m, vector<int>(n));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                x1 = max(0, i - k) + 1;
                y1 = max(0, j - k) + 1;
                x2 = min(m - 1, i + k) + 1;
                y2 = min(n - 1, j + k) + 1;

                // 求和
                ans[i][j] = sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
            }
        }

        return ans;
    }
};
