//
// Created by 18483 on 2024/10/30.
//
#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
using namespace std;

// 力扣1576.替换所有的问号
// 写法1
class Solution1576_1
{
public:
    string modifyString(string s)
    {
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '?')
            {
                for (char j = 'a'; j <= 'z'; j++)
                {
                    if (i - 1 >= 0 && i + 1 < s.size() && j != s[i - 1] && j != s[i + 1])
                    {
                        if (s[i + 1] == '?')
                        {
                            s[i] = j++;
                            break;
                        }
                        else
                        {
                            s[i] = j;
                            break;
                        }
                    }
                    else if (i - 1 < 0 && i + 1 < s.size())
                    {
                        if (j != s[i + 1])
                        {
                            s[i] = j;
                            break;
                        }
                    }
                    else if (i - 1 >= 0 && i + 1 >= s.size())
                    {
                        if (j != s[i - 1])
                        {
                            s[i] = j;
                            break;
                        }
                    }
                    else if (i - 1 < 0 && i + 1 >= s.size())
                    {
                        s[i] = j;
                        break;
                    }
                }
            }
        }

        return s;
    }
};

// 写法2
class Solution1576_2
{
public:
    string modifyString(string s)
    {
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '?')
            {
                for (char j = 'a'; j <= 'z'; j++)
                {
                    if ((i - 1 < 0 || j != s[i - 1]) && (i + 1 >= s.size() || j != s[i + 1]))
                    {
                        s[i] = j;
                        break;
                    }
                }
            }
        }

        return s;
    }
};


// 力扣495.提莫攻击
// 写法1
class Solution495_1
{
public:
    int findPoisonedDuration(vector<int> &timeSeries, int duration)
    {
        int time = 0;
        for (int i = 0; i < timeSeries.size(); i++)
        {
            if (i + 1 < timeSeries.size() && timeSeries[i + 1] - timeSeries[i] >= duration)
            {
                time += duration;
            }
            else if (i + 1 < timeSeries.size() && timeSeries[i + 1] - timeSeries[i] < duration)
            {
                time += timeSeries[i + 1] - timeSeries[i];
            }
        }

        // 最后一次攻击会持续到结尾
        time += duration;

        return time;
    }
};

// 写法2
class Solution495_2
{
public:
    int findPoisonedDuration(vector<int> &timeSeries, int duration)
    {
        int time = 0;
        for (int i = 1; i < timeSeries.size(); i++)
        {
            if (timeSeries[i] - timeSeries[i - 1] >= duration)
            {
                // 第一种情况
                time += duration;
            }
            else
            {
                time += timeSeries[i] - timeSeries[i - 1];
            }
        }

        // 最后一种情况
        time += duration;

        return time;
    }
};

// 力扣6.Z字形变换
// 暴力模拟
class Solution6_1
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
        {
            return s;
        }
        // 获取字符串的长度
        int sz = s.size();
        // 获取周期
        int cycle = ceil((float) sz / (2 * numRows - 2)) * (numRows - 1);
        // 构建二维矩阵
        vector<vector<char>> matrix(numRows, vector<char>(cycle));

        int i = 0;
        int j = 0;
        int k = 0;
        // 填充二维矩阵
        while (k < sz)
        {
            // 填充竖向列
            while (i < numRows)
            {
                if (k >= sz)
                    break;
                matrix[i][j] = s[k++];
                i++;
            }

            i -= 2;
            // 填充斜向上
            while (i > 0)
            {
                if (k >= sz)
                    break;
                j++;
                matrix[i][j] = s[k++];
                i--;
            }

            j++;
        }

        // 遍历二维矩阵
        string ret;
        for (auto &v: matrix)
        {
            for (auto &ch: v)
            {
                if (ch == '\0')
                    continue;
                ret += ch;
            }
        }

        return ret;
    }
};

// 找规律
class Solution6_2
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
        {
            return s;
        }

        // 获取字符串长度
        int sz = s.size();
        // 获取公差
        int d = 2 * numRows - 2;

        string ret;
        // 处理第一行
        for (int i = 0; i < sz; i += d)
        {
            ret += s[i];
        }

        // 处理中间行
        for (int k = 1; k < numRows - 1; k++)
        {
            for (int x = k, y = d - k; x < sz || y < sz; x += d, y += d)
            {
                if (x < sz)
                {
                    ret += s[x];
                }
                if (y < sz)
                {
                    ret += s[y];
                }
            }
        }

        // 处理最后一行
        for (int i = numRows - 1; i < sz; i += d)
        {
            ret += s[i];
        }

        return ret;
    }
};

// 力扣59.螺旋矩阵 II
class Solution59
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        // 处理结果
        vector<vector<int>> ret(n);
        for (auto &v: ret)
            v.resize(n);
        int count = 1;
        int left = 0, top = 0;
        int right = n - 1, bottom = n - 1;
        while (left <= right && top <= bottom)
        {
            for (int i = left; i <= right; i++)
                ret[top][i] = count++;
            top++;
            for (int i = top; i <= bottom; i++)
                ret[i][right] = count++;
            right--;
            for (int i = right; i >= left; i--)
                ret[bottom][i] = count++;
            bottom--;
            for (int i = bottom; i >= top; i--)
                ret[i][left] = count++;
            left++;
        }

        return ret;
    }
};

// 力扣54.螺旋矩阵
class Solution54
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        // 处理结果
        vector<int> ret;
        // 获取行和列
        int m = matrix.size();
        int n = matrix[0].size();
        // 定义上下左右边
        int left = 0;
        int right = n - 1;
        int top = 0;
        int bottom = m - 1;

        while (top <= bottom && left <= right)
        {
            // 处理第一行
            for (int i = left; i <= right; i++)
            {
                ret.push_back(matrix[left][i]);
            }
            // 第一行处理完毕
            top++;

            // 处理第一列
            for (int i = top; i <= bottom; i++)
            {
                ret.push_back(matrix[i][right]);
            }
            // 第一列处理完毕
            right--;

            // 处理第二行
            // 需要判断是否还有第二行
            if (top <= bottom)
            {
                for (int i = right; i >= left; i--)
                {
                    ret.push_back(matrix[bottom][i]);
                }
                // 第二行处理完毕
                bottom--;
            }

            // 处理第二列
            // 需要判断是否还有第二列
            if (left <= right)
            {
                for (int i = bottom; i >= top; i--)
                {
                    ret.push_back(matrix[i][left]);
                }
                left++;
            }
        }

        return ret;
    }
};


// 力扣38.外观数列
// 递归版本
class Solution38_1
{
public:
    string countAndSay(int n)
    {
        if (n == 1)
        {
            return "1";
        }

        string ret = countAndSay(n - 1);
        string temp;
        temp.clear();
        for (int left = 0, right = 0; right < ret.size(); left = right)
        {
            while (ret[left] == ret[right])
            {
                right++;
            }

            temp += to_string(right - left) + ret[left];
        }

        ret = temp;

        return ret;
    }
};

// 迭代版本
class Solution38_2
{
public:
    string countAndSay(int n)
    {
        string ret = "1";
        for (int i = 1; i < n; i++)
        {
            string temp;
            // 统计个数
            for (int left = 0, right = 0; right < ret.size(); left = right)
            {
                // 持续寻找相同的字符
                while (right < ret.size() && ret[left] == ret[right])
                {
                    right++;
                }

                // 更新字符串
                temp += to_string(right - left) + ret[left];
            }
            ret = temp;
        }
        return ret;
    }
};

// 力扣1419.数青蛙
class Solution
{
public:
    int minNumberOfFrogs(string croakOfFrogs)
    {
        string s = "croak";
        int sz = s.size();
        // 创建哈希表用于字符个数的映射
        vector<int> hash(sz);

        // 创建哈希表用于下标映射
        unordered_map<char, int> index;
        for (int i = 0; i < s.size(); i++)
        {
            index[s[i]] = i;
        }

        // 遍历所给字符串
        for (auto ch : croakOfFrogs)
        {
            if (ch == 'c')
            {
                // 判断k字符个数是否为0
                if (hash[index[ch] + sz - 1])
                {
                    hash[index[ch] + sz - 1]--;
                }
                hash[index[ch]]++;
            }
            else
            {
                // 其他四个字符
                if (hash[index[ch] - 1] == 0)
                    return -1;
                hash[index[ch] - 1]--;
                hash[index[ch]]++;
            }
        }

        // 结束后判断是否存在除k以外的字符的个数非0
        for (int i = 0; i < hash.size() - 1; i++)
            if (hash[i] != 0)
                return -1;

        return hash[index['k']];
    }
};
