#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maxNumOfMarkedIndices(vector<int> &nums)
    {
        int ans = 0;
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int left = 0;
        int right = n / 2;
        int m = n / 2;

        // 尝试配对
        while (left < m && right < n)
        {
            if (nums[right] >= 2 * nums[left])
            {
                ans += 2;
                left++;
                right++;
            }
            else
                right++;
        }

        return ans;
    }
};