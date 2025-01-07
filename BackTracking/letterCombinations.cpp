//
// Created by 18483 on 2025/1/7.
//
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// 力扣17.电话号码的字母组合
// 基本思路：建立数字和字符串映射，第一层for循环枚举最开始的数字数组，第二层循环枚举其中的字符
// 因为一个组合中的每个字符来自不同的按键，所以递归时需要更改数字数组，但是对于映射的字符数组来说，每一次更新i，其都是从0下标开始向后枚举，所以此处是固定的操作
class Solution17_1
{
public:
    vector<string> ret;
    string path;

    void backtracking(string &digits, int startOfDigits, unordered_map<char, string> &dc)
    {
        if (path.size() == digits.size())
        {
            ret.push_back(path);
            return;
        }

        for (int i = startOfDigits; i < digits.size(); i++)
        {
            for (int j = 0; j < dc[digits[i]].size(); j++)
            {
                path += dc[digits[i]][j];
                backtracking(digits, i + 1, dc);
                path.pop_back();
            }
        }
    }

    vector<string> letterCombinations(string digits)
    {
        if (!digits.size())
            return ret;
        // 建立数字和字母映射
        unordered_map<char, string> dc;
        dc.insert({'2', "abc"});
        dc.insert({'3', "def"});
        dc.insert({'4', "ghi"});
        dc.insert({'5', "jkl"});
        dc.insert({'6', "mno"});
        dc.insert({'7', "pqrs"});
        dc.insert({'8', "tuv"});
        dc.insert({'9', "wxyz"});

        backtracking(digits, 0, dc);

        return ret;
    }
};

// 写法优化
// 基本思路还是与上面的解法一致，但是对于写法可以进行简化
// 首先是映射，使用数组代替原来的哈希表，影响不大
// 在上面的代码中，函数通过for循环和变量startOfDigits判断当前在digits数组的哪一个位置
// 但是实际上这一步可以交给递归来做，即每一次递归时通过更新下标，即可获取到新的数字对应的字符串数组，从而可以少写一个循环并且少用一个变量
// 接着是循环中的优化：因为递归前需要更新path，可以考虑不改变当前的path，而是将path+新的字符构成一个新的临时对象传递给参数
// 此时就可以做到自动回溯而不是手动回溯
class Solution17_2
{
public:
    vector<string> ret;
    // 数组映射
    const string dc[10] = {
                "", // 0
                "", // 1
                "abc", // 2
                "def", // 3
                "ghi", // 4
                "jkl", // 5
                "mno", // 6
                "pqrs", // 7
                "tuv", // 8
                "wxyz", // 9
            };

    void backtracking(const string &digits, int index, string path)
    {
        if (index == digits.size())
        {
            ret.push_back(path);
            return;
        }

        // 获取对应的字符串
        int digit = digits[index] - '0';
        string letter = dc[digit];

        for (int i = 0; i < letter.size(); i++)
            backtracking(digits, index + 1, path + letter[i]);
    }

    vector<string> letterCombinations(string digits)
    {
        if (!digits.size())
            return ret;

        string path;
        backtracking(digits, 0, path);

        return ret;
    }
};
