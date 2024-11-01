//
// Created by 18483 on 2024/10/30.
//
#include <iostream>
#include <vector>
using namespace std;

// ������KamaCoder.����ͣ������ⷨ
int main1()
{
    // ���ͬ��
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // �������鳤��
    int len = 0;
    cin >> len;

    vector<int> arr(len);

    for (int i = 0; i < len; i++)
    {
        cin >> arr[i];
    }

    int a = 0, b = 0;
    int sum = 0;
    while (cin >> a >> b)
    {
        for (int i = a; i <= b; i++)
        {
            sum += arr[i];
        }
        cout << sum << endl;

        sum = 0;
    }

    return 0;
}

// ������KamaCoder.����ͣ�ǰ׺�ͽⷨ����д��1
int main2()
{
    // ���ͬ��
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // �������鳤��
    int len = 0;
    cin >> len;

    vector<int> arr(len);
    // ǰ׺������
    vector<int> prefixSum(len + 1, 0);

    for (int i = 0; i < len; i++)
    {
        cin >> arr[i];
        // ����ǰ׺�ͣ�ǰi��Ԫ�صĺ�
        prefixSum[i + 1] = prefixSum[i] + arr[i];
    }

    int a = 0, b = 0;
    while (cin >> a >> b)
    {
        // ��������
        cout << prefixSum[b + 1] - prefixSum[a] << endl;
    }

    return 0;
}

// ������KamaCoder.����ͣ�ǰ׺�ͽⷨ����д��2
int main3()
{
    // ���ͬ��
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // �������鳤��
    int len = 0;
    cin >> len;

    // Ԫ������
    vector<int> arr(len);
    // ǰ׺������
    vector<int> sum(len);

    int preSum = 0;
    for (int i = 0; i < len; i++)
    {
        cin >> arr[i];

        // ����ǰ׺��
        preSum += arr[i];
        sum[i] = preSum;
    }

    int a = 0, b = 0;
    while (cin >> a >> b)
    {
        // ���
        if (a == 0)
        {
            cout << sum[b] << endl;
        }
        else
        {
            cout << sum[b] - sum[a - 1] << endl;
        }
    }

    return 0;
}

// ţ����DP34.��ģ�桿ǰ׺��
int mainDP34()
{
    int n, q;
    while (cin >> n >> q)
    {
        // ע��ʹ��long long��ֹ���
        long long sumArr = 0;
        vector<long long> arr(n);
        vector<long long> sum(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            sumArr += arr[i];
            sum[i] = sumArr;
        }

        int l = 0, r = 0;
        for (int i = 0; i < q; i++)
        {
            cin >> l >> r;

            if (l - 1 == 0)
            {
                cout << sum[r - 1] << endl;
            }
            else
            {
                cout << sum[r - 1] - sum[l - 2] << endl;
            }
        }
    }
}

// ţ����DP35.��ģ�桿��άǰ׺��
int mainDP35()
{
    int n = 0, m = 0;
    int q = 0;
    while (cin >> n >> m >> q)
    {
        // ԭ����
        vector<vector<long long> > arr(n + 1);
        for (auto &v: arr)
        {
            v.resize(m + 1);
        }
        // ������
        vector<vector<long long> > sum(n + 1);
        for (auto &v: sum)
        {
            v.resize(m + 1);
        }

        // ��ȡ���鲢���ǰ׺��
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> arr[i][j];

                // ���ǰ׺������
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] + arr[i][j] - sum[i - 1][j - 1];
            }
        }

        int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
        // ʹ��ǰ׺������
        for (int i = 0; i < q; i++)
        {
            cin >> x1 >> y1 >> x2 >> y2;
            cout << sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1] << endl;
        }
    }
}
