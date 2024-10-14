#include <iostream>
#include <vector>
using namespace std;
bool canPartition(vector<int> &nums)
{
    int sum = 0;
    for (int num : nums)
    {
        sum += num;
    }

    // 如果总和为奇数，无法平分
    if (sum % 2 != 0)
    {
        return false;
    }

    int target = sum / 2;
    vector<bool> dp(target + 1, false);
    dp[0] = true; // 和为0的子集是肯定可以实现的（不选择任何元素）

    // 遍历每个数
    for (int num : nums)
    {
        // 从后向前更新dp数组，防止重复使用同一个元素
        for (int j = target; j >= num; --j)
        {
            dp[j] = dp[j] || dp[j - num];
        }
    }

    return dp[target];
}