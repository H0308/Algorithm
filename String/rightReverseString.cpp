//
// Created by 18483 on 2024/11/19.
//

// 卡码网KamaCoder.右旋字符串
// 整体反转+局部反转
#include <iostream>
using namespace std;

void reverseString(string& s, int start, int end)
{
    while(start < end)
    {
        swap(s[start++], s[end--]);
    }
}

int main()
{
    int k;
    string s;
    cin >> k >> s;

    // 1. 进行整体反转
    reverseString(s, 0, s.size() - 1);

    // 2. 翻转前k个
    reverseString(s, 0, k - 1);

    // 3. 翻转后n - k个
    reverseString(s, k, s.size() - 1);

    cout << s << endl;

    return 0;
}