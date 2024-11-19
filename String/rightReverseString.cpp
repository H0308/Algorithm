//
// Created by 18483 on 2024/11/19.
//

// ������KamaCoder.�����ַ���
// ���巴ת+�ֲ���ת
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

    // 1. �������巴ת
    reverseString(s, 0, s.size() - 1);

    // 2. ��תǰk��
    reverseString(s, 0, k - 1);

    // 3. ��ת��n - k��
    reverseString(s, k, s.size() - 1);

    cout << s << endl;

    return 0;
}