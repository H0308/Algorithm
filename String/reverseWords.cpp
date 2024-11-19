//
// Created by 18483 on 2024/11/19.
//
#include <iostream>
using namespace std;

// ����151. ��ת�ַ����еĵ���
// �ⷨ1��������ȡ��ԭ�ַ��������еĵ��ʲ���β�����һ���ո����ȥ������Ŀո�
class Solution151_1
{
public:
    string trim(string &s)
    {
        int index = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != ' ')
            {
                index = i;
                break;
            }
        }

        int length = 0;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] != ' ')
            {
                length = i;
                break;
            }
        }

        return s.substr(index, length - index + 1);
    }

    string trimInner(string &s)
    {
        string result;
        bool space = false;
        for (char c: s)
        {
            if (c != ' ')
            {
                result += c;
                space = false;
            }
            else if (!space)
            {
                result += c;
                space = true;
            }
        }
        return result;
    }

    string reverseWords(string s)
    {
        // ȥ��ǰ����β���ո�
        string copy = trim(s);

        string word;

        int wordStart = 0;

        for (int i = 0; i < copy.size(); i++)
        {
            if (i + 1 < copy.size() && copy[i] != ' ' && copy[i + 1] == ' ')
            {
                word.insert(0, copy.substr(wordStart, i - wordStart + 1) + ' ');
            }
            else if (i + 1 < copy.size() && copy[i] == ' ' && copy[i + 1] != ' ')
            {
                wordStart = i;
            }
        }

        word.insert(0,
                    copy.substr(wordStart, copy.size() - wordStart + 1) + ' ');

        string ret = trim(word);

        // ȥ���м�ո�
        ret = trimInner(ret);

        return ret;
    }
};

// �ⷨ2�����巴ת+���ʵ�����ת+�Ż��Ƴ��ո��߼�
class Solution151_2
{
public:
    // �Ƴ��ַ����еĿո�
    // �����Ƴ�Ԫ�ص�˼·
    void removeSpaces(string &s)
    {
        int fast = 0, slow = 0;
        while (fast < s.size())
        {
            if (s[fast] != ' ')
            {
                // �����ǿո�ʹ�����ɾ�����пո�
                if (slow != 0)
                    s[slow++] = ' '; // �ֶ����ƿո񣬸�����֮����ӿո�slow != 0˵�����ǵ�һ�����ʣ���Ҫ�ڵ���ǰ��ӿո�
                while (fast < s.size() && s[fast] != ' ')
                {
                    // ���ϸõ��ʣ������ո�˵�����ʽ�����
                    s[slow++] = s[fast++];
                }
            }

            fast++;
        }

        s.resize(slow);
    }

    // ��ת
    void reverseString(string &s, int start, int end)
    {
        while (start < end)
        {
            swap(s[start], s[end]);
            start++;
            end--;
        }
    }

    string reverseWords(string s)
    {
        // ȥ���ַ����ж���Ŀո�
        removeSpaces(s);
        // ���巴ת
        reverseString(s, 0, s.size() - 1);

        // �ٶԵ������ʽ��з�ת
        int start = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
            {
                reverseString(s, start, i - 1);
                start = i + 1;
            }
        }

        // ���תʣ��ĵ���
        reverseString(s, start, s.size() - 1);

        return s;
    }
};
