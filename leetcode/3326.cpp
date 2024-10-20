#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// 函数：计算 x 的最大真因数
int largestProperDivisor(int x)
{
    int res = 0;
    for (int i = sqrt(x); i > 1; --i)
    {
        if (x % i == 0)
        {
            // 找到两个真因数 i 和 x / i，选择更大的那个作为最大真因数
            res = max(res, max(i, x / i));
        }
    }
    // 如果没有找到有效的真因数，返回 1
    return res == 0 ? 1 : res;
}

// 函数：将数组变为非递减的最少操作次数
int minOperations(vector<int> &nums)
{
    int n = nums.size();
    int operations = 0;
    vector<int> flynorpexel = nums; // 复制输入数组以进行操作

    // 从后往前遍历，确保数组逐步非递减
    for (int i = n - 2; i >= 0; --i)
    {
        // 如果当前元素比下一个元素大，进行操作
        while (flynorpexel[i] > flynorpexel[i + 1])
        {
            int largestDivisor = largestProperDivisor(flynorpexel[i]);
            if (largestDivisor == 1)
            {
                // 无法继续减小，直接返回 -1
                return -1;
            }
            flynorpexel[i] /= largestDivisor; // 将当前数除以它的最大真因数
            operations++;                     // 记录操作次数
        }
    }

    return operations;
}

int main()
{
    vector<int> nums = {288, 7};
    int result = minOperations(nums);
    cout << "Minimum operations: " << result << endl;
    return 0;
}
