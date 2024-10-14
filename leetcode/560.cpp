#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int subarraySum(vector<int> &nums, int k)
{
    int res = 0;
    int sum = 0;                            // 当前前缀和
    unordered_map<int, int> prefixSumCount; // 存储前缀和出现的次数
    prefixSumCount[0] = 1;                  // 初始条件：前缀和为 0 时，出现 1 次

    for (int num : nums)
    {
        sum += num; // 计算当前前缀和

        // 如果当前前缀和 - k 已经存在于哈希表中，说明存在一个子数组的和为 k
        if (prefixSumCount.find(sum - k) != prefixSumCount.end())
        {
            res += prefixSumCount[sum - k]; // 增加符合条件的子数组个数
        }

        // 将当前前缀和加入哈希表，记录它出现的次数
        prefixSumCount[sum]++;
    }

    return res;
}