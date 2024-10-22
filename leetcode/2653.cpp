#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
using namespace std;

class Solution
{
public:
    vector<int> getSubarrayBeauty(vector<int> &nums, int k, int x)
    {
        int n = nums.size();
        vector<int> res(n - k + 1, 0);
        int count = 0;
        multiset<int> set;
        int left = 0;
        for (int i = 0; i < k; i++)
            if (nums[i] < 0)
            {
                count++;
                set.insert(nums[i]);
            }
        if (count >= x)
        {
            auto it = set.begin();
            advance(it, x - 1);
            res[0] = *it;
        }
        for (int i = k; i < n; i++)
        {
            if (nums[left] < 0)
            {
                set.erase(nums[left]);
                count--;
            }
            left++;
            if (nums[i] < 0)
            {
                set.insert(nums[i]);
                count++;
            }
            if (count >= x)
            {
                auto it = set.begin();
                advance(it, x - 1);
                res[left] = *it;
            }
        }
        return res;
    }
};