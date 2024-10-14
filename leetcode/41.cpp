#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int firstMissingPositive(vector<int> &nums)
{
    int min1;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (nums[i] <= 0)
            nums[i] = n + 1;
    }
    for (int i = 0; i < n; i++)
    {
        if (nums[i] <= n)
            nums[nums[i] - 1] = -nums[nums[i] - 1];
    }
    for (int i = 0; i < n; i++)
    {
        if (nums[i] > 0)
            min1 = i + 1;
    }
    return min1;
}