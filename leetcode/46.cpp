#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> res;
        vector<int> path;
        vector<bool> HasEnd(nums.size(), false);
        man(nums, res, path, HasEnd);
        return res;
    }
    void man(vector<int> &nums, vector<vector<int>> &res, vector<int> &path, vector<bool> HasEnd)
    {
        int n = nums.size();
        int n2 = path.size();
        if (n2 == n)
        {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < n; i++)
        {
            if (!HasEnd[i])
            {
                HasEnd[i] = true;
                path.push_back(nums[i]);
                man(nums, res, path, HasEnd);
                HasEnd[i] = false;
            }
        }
        path.pop_back();
    }
};