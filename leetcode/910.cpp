#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution
{
public:
    int smallestRangeII(vector<int> &nums, int k)
    {
        int n = nums.size();
        int minv = *min_element(nums.begin(), nums.end()) - k;
        int maxv = *max_element(nums.begin(), nums.end()) + k;
        for (int i : nums)
        {
            minv = max(minv, min(i - k, minv + 2 * k));
            maxv = min(maxv, max(i + k, maxv - 2 * k));
        }
        return maxv - minv;
    }
};