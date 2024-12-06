//
// Created by 18483 on 2024/12/6.
//
#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <functional>

using namespace std;

// 力扣150.逆波兰表达式求值
class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> nums;
        // map处理计算映射
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
            // 操作数进栈
            if (ch != "+" && ch != "-" && ch != "*" && ch != "/")
                nums.push(stoi(ch));
            else
            {
                // 取出第二个操作数
                int num2 = nums.top();
                nums.pop();
                // 取出第一个操作数
                int num1 = nums.top();
                nums.pop();
                int ret = op[ch](num1, num2);
                nums.push(ret);
            }
        }

        return nums.top();
    }
};
