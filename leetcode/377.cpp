#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        long dp[target + 1];
        memset(dp, 0, sizeof(dp));
        sort(nums.begin(),nums.end());
        dp[0]=1;
        int j=0;
        for (int i = 1; i <= target; ++i) {
        for (int j = 0; j < nums.size(); ++j) {
            if (i >= nums[j]) {
                dp[i] += dp[i - nums[j]];
            } else {
                break; 
            }
        }
        }
        return dp[target];
    }
};