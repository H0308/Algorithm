//
// Created by 18483 on 2024/10/30.
//
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// ������KamaCoder58.����ͣ������ⷨ
int main58_1()
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

// ������KamaCoder58.����ͣ�ǰ׺�ͽⷨ����д��1
int main58_2()
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

// ������KamaCoder58.����ͣ�ǰ׺�ͽⷨ����д��2
int main58_3()
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


// ������KamaCoder44.�����̹�������
int main44()
{
    int n = 0, m = 0;
    while (cin >> n >> m)
    {
        vector<vector<int>> arr(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> arr[i][j];
            }
        }

        int minNum = INT_MAX;
        // ͳ���ܺ�
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                sum += arr[i][j];
            }
        }

        // ���򻮷�
        // ע�Ᵽ֤������һ����һ������
        for (int i = 0; i < n - 1; i++)
        {
            int sumA = 0;
            // ��A��������
            for (int x = 0; x <= i; x++)
            {
                for (int y = 0; y < m; y++)
                {
                    sumA += arr[x][y];
                }
            }

            int sumB = sum - sumA;
            minNum = min(minNum, abs(sumA - sumB));
        }

        // ���򻮷�
        for (int j = 0; j < m - 1; j++)
        {
            int sumA = 0;
            // ��A��������
            for (int x = 0; x < n; x++)
            {
                for (int y = 0; y <= j; y++)
                {
                    sumA += arr[x][y];
                }
            }

            int sumB = sum - sumA;
            minNum = min(minNum, abs(sumA - sumB));
        }

        cout << minNum << endl;
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
        vector<vector<long long>> arr(n + 1);
        for (auto &v: arr)
        {
            v.resize(m + 1);
        }
        // ������
        vector<vector<long long>> sum(n + 1);
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

// ����724.Ѱ������������±�
// �ⷨ1��ֱ��ʹ��ǰ׺������
/*
 * ������Ҫ���õ�ǰ׺�����飬���ǰ׺������󣬱���ǰ׺�����飬
 * ����ҵ�һ���±�i������sum[i-1] == sum[n] - sum[i]���򷵻�i-1�����򷵻�-1
 * ע�⣬ǰ׺�͵���ЧԪ���±��Ǵ�1��ʼ�ģ����Է��ص��±���Ҫ��1
 */
class Solution724_1
{
public:
    int pivotIndex(vector<int> &nums)
    {
        vector<int> sum(nums.size() + 1);
        // ���ǰ׺������
        for (int i = 1; i <= nums.size(); i++)
        {
            sum[i] = nums[i - 1] + sum[i - 1];
        }

        // ʹ��ǰ׺������
        int index = 0;
        int back = sum[sum.size() - 1];
        for (int i = 1; i < sum.size(); i++)
        {
            if (back - sum[i] == sum[i - 1])
            {
                index = i;
                break;
            }
        }

        return index - 1 == nums.size() ? -1 : index - 1;
    }
};

// �ⷨ2��ǰ׺���������׺������
/*
 * ʹ����������ֱ𹹽�ǰ׺�����׺�ͣ���Ϊ��Ҫ�ҵ������±��ֵ���жϹ������ǲ�������
 * ���Կ��Կ��Ǽ���ǰ׺��ʱֻ����[0, i - 1]�����ֵ��Ϊ���γɴ�λ���ұ�֤������Խ������
 * ��Ҫ����ǰ׺�������һ��Ԫ��Ϊ0
 * ��ǰ׺������һ������׺������Ҳ����Ҫ���ǵ�i��λ�õ�ֵ�����Ǻ�׺���Ǵ��Ҳ��������м���
 * ����ֻ��Ҫ��������[i + 1, n - 1]�е�Ԫ��֮�ͼ��ɣ�
 * ��׺�����������һ��Ԫ�ؾʹ����Ҳ�����[i + 1, n - 1]����Ԫ�صĺ�
 * ע�⣬�����ǰ׺������ͺ�׺��������ԭ�������nums.size�ĳ���
 * �ó����ƹ�ʽ��
 * ǰ׺��prefix[i] = prefix[i - 1] + nums[i - 1]������i��1��ʼ��prefix[0] = 0
 * ��׺��suffix[i] = suffix[i + 1] + nums[i + 1]������i��nums.size() - 1��ʼ��suffix[nums.size() - 1] = 0
 */
class Solution724_2
{
public:
    int pivotIndex(vector<int> &nums)
    {
        vector<int> prefix(nums.size());
        vector<int> suffix(nums.size());

        // ����ǰ׺��
        // ��Ϊֻ��Ҫ����[0, i - 1]�����е�ֵ�����Ե�iλ��ֵ���Բ��ÿ���
        // ��ǰ����£�ǰ׺�������һ��Ԫ��Ϊ0
        // ��Ϊ��i=0ʱ������Ϊ[0, -1]����һ�������ڵ�����
        for (int i = 1; i < nums.size(); i++)
            prefix[i] = nums[i - 1] + prefix[i - 1];
        // ������׺��
        // ��Ϊֻ��Ҫ����[i + 1, size - 1]�����е�ֵ�����Ե�iλ��ֵ���Բ��ÿ���
        // Ϊ���γɴ�λ����Ҫ��suffix[size-1]��Ϊ0
        for (int i = nums.size() - 2; i >= 0; i--)
            suffix[i] = nums[i + 1] + suffix[i + 1];

        // ʹ��ǰ׺�����׺��
        for (int i = 0; i < nums.size(); i++)
        {
            if (suffix[i] == prefix[i])
            {
                return i;
            }
        }

        return -1;
    }
};

// ����238.��������������ĳ˻�
/*
 * ����������˼·����һ����ʹ���������飬�ֱ��ʾǰ׺���ͺ�׺��
 */
class Solution238
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        // ������
        vector<int> ret;

        // ǰ׺������
        vector<int> prefix(nums.size(), 1);
        // ��׺������
        vector<int> suffix(nums.size(), 1);

        // ����ǰ׺������
        for (int i = 1; i < nums.size(); i++)
            prefix[i] = prefix[i - 1] * nums[i - 1];

        // ������׺������
        for (int i = nums.size() - 2; i >= 0; i--)
            suffix[i] = suffix[i + 1] * nums[i + 1];

        for (int i = 0; i < nums.size(); i++)
            ret.push_back(prefix[i] * suffix[i]);

        return ret;
    }
};

// ����560.��Ϊk��������
// ���󣺻�������
/*
 * �����һ��Ӧ��ʹ�û�����������������Ǳ��������е�Ԫ���漰��������
 * �����ڱ��������в����㵥���ԣ��Ӷ��������©��������Բ�����ʹ�û��������㷨���
 */
class Solution560_false
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int sum = 0;
        int count = 0;
        for (int left = 0, right = 0; right < nums.size(); right++)
        {
            // ������
            sum += nums[right];

            // ���´���
            while (sum >= k && left <= right)
            {
                if (sum == k)
                {
                    count++;
                }
                sum -= nums[left++];
            }
        }

        return count;
    }
};

// ǰ׺��+��ϣ��
/*
 * ����Ҫ�ҵ���Ϊk�������飬��򵥵ķ������Ǳ���ö�٣�������ʱ�临�ӶȽϸߣ�
 * ��ʱ��ν��ǰ׺�ͽ�����ǽ���ؼ���
 * ����ʹ��һ��˼·���ҵ���i��β�ĺ�Ϊk��������
 * Ϊʲôʹ������˼·����i��β���Ա�֤��ǰ׺��������i-1λ��һ����ǰ������Ԫ��֮��
 * ����ĿҪ���Ϊk�������飬��ʱ��ֻ��Ҫ��[0, i-1]�������ҵ���Ϊk��������
 * ���￼���Һ�Ϊ��ǰλ�õ�ǰ׺��sum��ȥk���ó�һ���µ����䣬
 * �������ĳ��־ʹ���һ����[0, i-1]�ڴ���һ����Ϊk��������
 * ֮������Ҫ����������Ϊֱ�Ӳ����뱩��ö��˼·һ�£�����Ч�ʵ�����û�����õ�ǰ׺�͵�����
 * ��Σ�Ϊ�˽�һ����֤���ӶȲ����˻�������ö�ٵĳ̶ȣ����Խ�����ϣ��ṹͳ�Ƶ�ǰ�����г���sum-k�Ĵ���
 * ��������ʹ����˶��ٸ���Ϊk�������飬�����ϣ�����Ѿ�����sum-k����˵��֮ǰ�Ѿ����ֹ�һ�������飬����͸��´�������
 * δ�����
 * 1. Ϊʲô��[0, i-1]����
 * 2. Ϊʲô��Ҫ��sum-k����ֱ����k
 * 3. ΪʲôҪʹ�ù�ϣ��ͳ�ƴ���
 */
class Solution560
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        // ͳ�Ƹ���
        unordered_map<int, int> cnt;
        // ������������Ԫ�غ�Ϊk����Ҳ������һ��
        cnt[0] = 1;

        int sum = 0;
        int ret = 0;
        for (auto num: nums)
        {
            // ��ǰ׺��
            sum += num;
            // �жϵ�ǰǰ׺���Ƿ����sum - k
            // �������sum-k����ǰ������һ������һ����Ϊk��������
            if (cnt.find(sum - k) != cnt.end())
            {
                ret += cnt[sum - k];
            }
            // ��¼��ǰǰ׺�ͳ��ֵĴ���
            cnt[sum]++;
        }

        return ret;
    }
};

// ����974.�Ϳɱ�K������������
/*
 * �������ͬ�ඨ����Խ���Ŀת��Ϊ��ǰ׺����������tempSum%k==sum%k�������飬ע��ȡ�����������
 * ʣ��˼·���������һ��
 */
class Solution974
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        // ͳ��ǰ׺�ͳ��ֵĴ���
        unordered_map<int, int> cnt;
        cnt[0] = 1;

        int sum = 0;
        int ret = 0;
        for (auto num: nums)
        {
            // ָ�������ǰ׺��
            sum += num;
            // ȡ����������
            int rest = (sum % k + k) % k;
            // �����ǰrest�����ڹ�ϣ��˵������sum%k����֮ǰ������beforeSum % k
            if (cnt.find(rest) != cnt.end())
            {
                ret += cnt[rest];
            }

            cnt[rest]++;
        }

        return ret;
    }
};

// ����525.��������
class Solution525
{
public:
    int findMaxLength(vector<int> &nums)
    {
        unordered_map<int, int> cnt;
        cnt[0] = -1;

        // ���������е�0��Ϊ-1
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                nums[i] = -1;
            }
        }

        // ����������ǰ׺��Ϊsum���������
        int sum = 0;
        int ret = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            // ��ǰ׺��
            sum += nums[i];

            // ��ϣ���д洢����ǰ׺�ͣ���������ǰ׺��Ϊsumʱ�͸��µ�ǰ����
            if (cnt.find(sum) != cnt.end())
            {
                ret = max(ret, i - cnt[sum]);
            }
            else
            {
                cnt[sum] = i;
            }
        }

        return ret;
    }
};

// ����1314.���������
/*
 * ����Ĺؼ�������������Լ��Ա߽�Ĵ���ʣ��ľ��Ƕ�άǰ׺�͵Ļ���������ʹ��
 */
class Solution1314
{
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>> &mat, int k)
    {
        int m = mat.size();
        int n = mat[0].size();
        // ����ǰ׺������
        vector<vector<int>> sum(m + 1, vector<int>(n + 1));

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + mat[i - 1][j - 1];
            }
        }

        // ʹ��ǰ׺������
        int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
        vector<vector<int>> ans(m, vector<int>(n));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                x1 = max(0, i - k) + 1;
                y1 = max(0, j - k) + 1;
                x2 = min(m - 1, i + k) + 1;
                y2 = min(n - 1, j + k) + 1;

                // ���
                ans[i][j] = sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
            }
        }

        return ans;
    }
};
