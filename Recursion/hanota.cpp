//
// Created by 18483 on 2025/1/2.
//
#include <iostream>
#include <vector>

using namespace std;

// ����������08.06.��ŵ������
// �����ⷨ
class Solution0806_1
{
public:
    void _hanota(vector<int> &A, vector<int> &B, vector<int> &C, int num)
    {
        if (num == 1)
        {
            C.push_back(A.back());
            // ע�ⵯ�����һ��Ԫ��
            A.pop_back();
            return;
        }

        _hanota(A, C, B, num - 1);
        C.push_back(A.back());
        // ע�ⵯ�����һ��Ԫ��
        A.pop_back();
        _hanota(B, A, C, num - 1);
    }

    void hanota(vector<int> &A, vector<int> &B, vector<int> &C)
    {
        _hanota(A, B, C, A.size());
    }
};

// ����Ͷ��ȡ��
class Solution0806_2
{
public:
    void hanota(vector<int> &A, vector<int> &B, vector<int> &C)
    {
        C = A;
    }
};
