//
// Created by 18483 on 2025/1/10.
//
#include <iostream>
#include <string>
#include <vector>
#include <functional>

using namespace std;

// ����131.�ָ���Ĵ�
/*
 * ���ڷָ����⣬����Ҫ˼��Ϊʲô������ֱ���õ��������
 * �ָ�ı���ʵ���Ͼ���ȡ�����еĽ�������жϣ���ʱ�ͻ��漰��ÿһ���ַ�����������һ���Ӵ�����㣬���ʹ��ѭ�������ҵ�һ��������Ҫ����Ӵ�ʱ
 * ����Ҫ������λع鵽��һ����㣬�������ĸ��ӳ̶Ⱦͻ�ܸߣ����Զ��ڷָ�����Ҳ��Ҫ����ʹ�û��ݽ��
 *
 * ������������ηָ��������ķ���������֪���ָ�ı��ʣ����ø����ʿ��Կ���˼·���̶�һ�������յ㣬�ж��м�����ַ����Ƿ��ǻ��Ĵ�����
 * ��Ϊÿһ�ηָ��Ҫ���Ǵ��ʼ���ַ���ʼ�����Էָ�������ǵ�һ���ַ�����������ȷ���յ㼴��
 */
class Solution131_1
{
public:
    vector<vector<string>> ret;
    vector<string> temp;
    // �ж��Ƿ��ǻ��Ĵ�
    bool isPalindrome(const string &s)
    {
        for (int left = 0, right = s.size() - 1; left <= right;)
        {
            while (left <= s.size() - 1 && !isalnum(s[left]))
                left++;
            while (right >= 0 && !isalnum(s[right]))
                right--;

            if (left <= s.size() - 1 && right >= 0 && tolower(s[left]) != tolower(s[right]))
            {
                return false;
            }
            else
            {
                left++;
                right--;
            }
        }

        return true;
    }

    void backtracking(const string &s, int start)
    {
        if (start == s.size())
        {
            ret.push_back(temp);
            return;
        }

        for (int i = start; i < s.size(); i++)
        {
            string path = s.substr(start, i - start + 1);
            if (isPalindrome(path))
                temp.push_back(path);
            else
                continue;
            backtracking(s, i + 1);
            temp.pop_back();
        }
    }

    vector<vector<string>> partition(string s)
    {
        backtracking(s, 0);

        return ret;
    }
};

class Solution131_2
{
public:
    vector<vector<string>> ret;
    vector<string> path;

    vector<vector<string>> partition(string s)
    {
        function<bool(const string &)> isPalindrome =
                [&](const string &s) -> bool
        {
            for (int left = 0, right = s.size() - 1; left <= right;)
            {
                while (left <= s.size() - 1 && !isalnum(s[left]))
                    left++;
                while (right >= 0 && !isalnum(s[right]))
                    right--;

                if (left <= s.size() - 1 && right >= 0 &&
                    tolower(s[left]) != tolower(s[right]))
                {
                    return false;
                }
                else
                {
                    left++;
                    right--;
                }
            }

            return true;
        };
        function<void(const string &, int)> backtracking =
                [&](const string &s, int start) -> void
        {
            if (start == s.size())
            {
                ret.push_back(path);
                return;
            }

            for (int i = start; i < s.size(); i++)
            {
                string str = s.substr(start, i - start + 1);
                if (isPalindrome(str))
                    path.push_back(str);
                else
                    continue;

                backtracking(s, i + 1);
                path.pop_back();
            }
        };

        backtracking(s, 0);

        return ret;
    }
};
