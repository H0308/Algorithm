//
// Created by 18483 on 2025/1/10.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ����131.�ָ���Ĵ�
/*
 * ����Ļ���˼·���Ǹ��ݷָ�λ���и��ַ���������и���ַ����ǻ��Ĵ��ͼ��뵽�������
 * �ѵ����������и��ַ�������Ȼ���и��ַ���������Ҫ�ҵ��и����ʼλ�ú���ֹλ��
 *
 * �и�Ļ���˼·�ǣ�������ݵ�ǰ��ʼλ���Լ���ֹλ���и��ȡ�������ַ����ǻ��Ĵ��Ͳ��뵽�������������ʼλ�ã����������ֹλ��
 * ������ʼλ�ÿ���ʹ����������е�start�����棬��ʾ��һ�α����Ŀ�ʼ����ֹλ�þ��ǵ�ǰ�������±�i
 * ע�⣬�ж�һ���Ӵ����ǻ��Ĵ���Ҫ���Ϸ��أ�����Ҫ�����жϺ����ַ����ɵ��Ӵ��Ƿ���Թ��ɻ��Ĵ�
 *
 * ��Ҫע�⣬���ⲻ�Ƽ�ʹ��ƴ�ӵķ�ʽ����Ϊƴ�ӵķ�ʽ����Ҫ��֤����ַ����е��ַ���ԭ�ַ�������������
 * ����ƴ�ӵķ�ʽ��Ҫ�Եڶ����ж�һ���Ӵ��Ƿ��ǻ��Ĵ���׼������������һ�ε������ַ�
 */
class Solution131
{
public:
    vector<vector<string>> ret;
    vector<string> temp;
    // �ж��Ƿ��ǻ��Ĵ�
    bool isPalindrome(const string& s)
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