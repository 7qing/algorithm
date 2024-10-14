#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> res;
        vector<int> path;
        res.push_back(path); // 空集
        backtrack(nums, res, path, 0);
        return res;
        }

    void backtrack(vector<int> &nums, vector<vector<int>> &res, vector<int> &path, int start)
    {
        for (int i = start; i < nums.size(); i++)
        {
            // 做选择
            path.push_back(nums[i]);
            res.push_back(path);               // 每次选择都记录一个新子集
            backtrack(nums, res, path, i + 1); // 递归生成后续子集
            path.pop_back();                   // 撤销选择（回溯）
        }
    }
};