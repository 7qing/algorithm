#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        queue<int> q;
        int n = nums.size();
        if (n == 1)
            return 0;
        q.push(nums[0]);
        q.push(nums[1]);
        for (int i = 0; i < n; i++)
        {
            if (nums[i] < q.front())
            {
                int n = q.front();
            }
        }
    }
};