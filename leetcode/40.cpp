#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<vector<int>> res;
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        __combinationSum2(candidates, target, res, path, 0, 0);
        return res;
    }

    void __combinationSum2(vector<int> &candidates, int target, vector<vector<int>> &res, vector<int> &path, int cur, int start)
    {
        if (cur == target)
        {
            res.push_back(path);
        }
        else if (cur > target)
            return;
        int n = candidates.size();
        for (int i = start; i < n; i++)
        {
            if (i > start && candidates[i] == candidates[i - 1])
                continue;
            path.push_back(candidates[i]);
            __combinationSum2(candidates, target, res, path, cur + candidates[i], i + 1);
            path.pop_back();
        }
    }
};