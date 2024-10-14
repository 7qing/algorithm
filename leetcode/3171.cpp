#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


class Solution
{
public:
    int minimumDifference(vector<int> &nums, int k)
    {
        // 初始化结果为一个非常大的数，用于存储最小差值
        int res = 1e9;
        // 左指针和当前按位或的累积结果初始化
        int l = 0, val = 0;

        // 遍历数组，r 作为右指针
        for (int r = 0; r < nums.size(); r++)
        {
            // 将右指针指向的元素加入当前按位或结果
            val |= nums[r];

            // 如果按位或结果大于 k，缩小左边界直到满足条件
            while (l <= r && val > k)
            {
                // 更新结果为当前按位或结果与 k 的差值
                res = min(res, val - k);

                // 从当前按位或结果中移除左端元素的影响
                // 使用异或操作，因为 val 是按位或运算所得
                val ^= nums[l];
                // 左指针右移，继续缩小区间
                l++;
            }

            // 当按位或结果满足条件时，检查是否更接近 k
            // 并更新最小差值
            if (l <= r)
            {
                res = min(res, k - val);
            }
        }

        // 返回与 k 的最小绝对差
        return res;
    }
};