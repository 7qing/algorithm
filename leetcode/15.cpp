#include "iostream"
#include <vector>
#include <cstring>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for (int first = 0; first < n; ++first) {
            
            if (first > 0 && nums[first] == nums[first - 1]) {
                continue;
            }
        
            int third = n - 1;
            int target = -nums[first];
         
            for (int second = first + 1; second < n; ++second) {
            
                if (second > first + 1 && nums[second] == nums[second - 1]) {
                    continue;
                }
            
                while (second < third && nums[second] + nums[third] > target) {
                    --third;
                }
               
                if (second == third) {
                    break;
                }
                if (nums[second] + nums[third] == target) {
                    ans.push_back({nums[first], nums[second], nums[third]});
                }
            }
        }
        return ans;
    }
};