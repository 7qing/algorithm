#include "iostream"
#include <vector>
#include <cstring>
#include <unordered_map>
using namespace std;

class Solution {
public:
   
    
    
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int, int> numIndex; 

        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            
            if (numIndex.find(complement) != numIndex.end()) {
                result.push_back(numIndex[complement]); 
                result.push_back(i); 
                break;
            }

            numIndex[nums[i]] = i;
        }

        return result;
    }
};