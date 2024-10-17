#include <iostream>
#include <vector>

// ����ҿ�ԭ��
// ����ָ��Ԫ�ص��±�
int BinarySearch(std::vector<int> &nums, int target)
{
    // ����ҿ�ԭ��[left, right]����������ֵ����vector����Ч
    int left = 0;
    int right = nums.size() - 1;

    // left <= right, ��Ϊ��left==rightʱ��nums[left] == nums[right]��Ч����ʱ�����һ���ж�
    while (left <= right)
    {
        // ������м�ֵ
        int mid = (left + right) / 2;
        // �ж��Ƿ�ȡ��ָ��ֵ
        if (nums[mid] == target) // ��ȡ�������
        {
            return mid; // ����ָ��ֵ�±�
        }
        else if (nums[mid] > target) // �м�ֵ�ϴ󡪡�targetһ�����м�ֵ���
        {
            // ����ҿ�ԭ�򣬴�ʱnums[mid]һ������target
            right = mid - 1;
        }
        else if (nums[mid] < target) // �м�ֵ��С����targetһ�����м�ֵ�ұ�
        {
            // ����ҿ�ԭ�򣬴�ʱnums[mid]һ������target
            left = mid + 1;
        }
    }

    // Լ��û�ҵ�����-1
    return -1;
}

int main()
{
    int target = 0;
    std::cin >> target;
    std::vector<int> v{2, 3, 34, 23, 90, 36, 22, 123, 45};
    int pos = BinarySearch(v, target);
    if (pos != -1)
        std::cout << "��ֵ������" << std::endl;
    else
        std::cout << "��ֵ����" << std::endl;

    return 0;
}
