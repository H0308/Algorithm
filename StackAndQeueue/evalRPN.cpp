//
// Created by 18483 on 2024/12/6.
//
#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <functional>

using namespace std;

// ����150.�沨�����ʽ��ֵ
class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> nums;
        // map�������ӳ��
        map<string, function<int(int, int)>> op = {
                    {
                        "+", [](int num1, int num2)
                        {
                            return num1 + num2;
                        }
                    },
                    {
                        "-", [](int num1, int num2)
                        {
                            return num1 - num2;
                        }
                    },
                    {
                        "*", [](int num1, int num2)
                        {
                            return num1 * num2;
                        }
                    },
                    {
                        "/", [](int num1, int num2)
                        {
                            return num1 / num2;
                        }
                    }
                };
        for (const auto& ch: tokens)
        {
            // ��������ջ
            if (ch != "+" && ch != "-" && ch != "*" && ch != "/")
                nums.push(stoi(ch));
            else
            {
                // ȡ���ڶ���������
                int num2 = nums.top();
                nums.pop();
                // ȡ����һ��������
                int num1 = nums.top();
                nums.pop();
                int ret = op[ch](num1, num2);
                nums.push(ret);
            }
        }

        return nums.top();
    }
};
