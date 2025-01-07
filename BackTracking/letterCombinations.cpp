//
// Created by 18483 on 2025/1/7.
//
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// ����17.�绰�������ĸ���
// ����˼·���������ֺ��ַ���ӳ�䣬��һ��forѭ��ö���ʼ���������飬�ڶ���ѭ��ö�����е��ַ�
// ��Ϊһ������е�ÿ���ַ����Բ�ͬ�İ��������Եݹ�ʱ��Ҫ�����������飬���Ƕ���ӳ����ַ�������˵��ÿһ�θ���i���䶼�Ǵ�0�±꿪ʼ���ö�٣����Դ˴��ǹ̶��Ĳ���
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
        // �������ֺ���ĸӳ��
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

// д���Ż�
// ����˼·����������Ľⷨһ�£����Ƕ���д�����Խ��м�
// ������ӳ�䣬ʹ���������ԭ���Ĺ�ϣ��Ӱ�첻��
// ������Ĵ����У�����ͨ��forѭ���ͱ���startOfDigits�жϵ�ǰ��digits�������һ��λ��
// ����ʵ������һ�����Խ����ݹ���������ÿһ�εݹ�ʱͨ�������±꣬���ɻ�ȡ���µ����ֶ�Ӧ���ַ������飬�Ӷ�������дһ��ѭ����������һ������
// ������ѭ���е��Ż�����Ϊ�ݹ�ǰ��Ҫ����path�����Կ��ǲ��ı䵱ǰ��path�����ǽ�path+�µ��ַ�����һ���µ���ʱ���󴫵ݸ�����
// ��ʱ�Ϳ��������Զ����ݶ������ֶ�����
class Solution17_2
{
public:
    vector<string> ret;
    // ����ӳ��
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

        // ��ȡ��Ӧ���ַ���
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
