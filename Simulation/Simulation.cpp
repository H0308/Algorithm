//
// Created by 18483 on 2024/10/30.
//
#include <iostream>
#include <vector>
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
class Solution495
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

// 力扣6.Z字形变换
class Solution6
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
        {
            return s;
        }
        // 计算公差
        int d = 2 * numRows - 2;
        string ret;

        // 处理第一行
        for (int j = 0; j < s.size(); j += d)
        {
            ret.push_back(s[j]);
        }

        // 处理中间行
        for (int k = 1; k < numRows - 1; k++)
        {
            for (int i = k, j = d - k; i < s.size() || j < s.size(); i += d, j += d)
            {
                if (i < s.size())
                {
                    ret += s[i];
                }
                if (j < s.size())
                {
                    ret += s[j];
                }
            }
        }

        // 处理最后一行
        for (int j = numRows - 1; j < s.size(); j += d)
        {
            ret.push_back(s[j]);
        }

        return ret;
    }
};


// 力扣59.螺旋矩阵 II
// 写法1
class Solution59_1
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        // 控制横向坐标和纵向坐标
        int startx = 0, starty = 0;
        // 控制行和列
        int row = 0, col = 0;
        // 控制偏移量
        int offset = 1;
        // 控制填充数值
        int count = 1;
        // 结果矩阵
        vector<vector<int>> ret(n);
        for (size_t i = 0; i < n; i++)
        {
            ret[i].resize(n, 0);
        }

        // vector<vector<int>> ret(n, vector<int>(n, 0));

        // 控制轮转圈数
        int cycle = n / 2;
        while (cycle--)
        {
            // 左闭右开方式控制每条边
            // 处理横向第一条边
            for (col = starty; col < n - offset; col++)
            {
                // 填充数值
                ret[startx][col] = count++;
            }

            // 处理纵向第一条边
            for (row = startx; row < n - offset; row++)
            {
                // 填充数值
                ret[row][col] = count++;
            }

            // 处理横向第二条边
            for (; col > starty; col--)
            {
                // 填充数值
                ret[row][col] = count++;
            }

            // 处理纵向第二条边
            for (; row > startx; row--)
            {
                // 填充数值
                ret[row][col] = count++;
            }

            // 控制圈
            startx++;
            starty++;
            offset++;
        }

        // 如果n为奇数时填充中间的数值
        if (n % 2)
            ret[startx][starty] = count;

        return ret;
    }
};

// 写法2_1
class Solution59_2
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
class Solution38
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
        string t = "croak";
        int n = t.size();
        vector<int> hash(n); // ⽤数组来模拟哈希表
        unordered_map<char, int> index; //[x, x这个字符对应的下标]
        for (int i = 0; i < n; i++)
            index[t[i]] = i;
        for (auto ch: croakOfFrogs)
        {
            if (ch == 'c')
            {
                if (hash[n - 1] != 0)
                    hash[n - 1]--;
                hash[0]++;
            }
            else
            {
                int i = index[ch];
                if (hash[i - 1] == 0)
                    return -1;
                hash[i - 1]--;
                hash[i]++;
            }
        }
        for (int i = 0; i < n - 1; i++)
            if (hash[i] != 0)
                return -1;
        return hash[n - 1];
    }
};