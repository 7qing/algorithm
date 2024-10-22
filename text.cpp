#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

double findMaxAverage(vector<int> nums, int k)
{
    int res;
    int val = 0;
    int n = nums.size();
    int left = 0;
    int right = 0;
    for (; right < k; right++)
        val += nums[right];
    res = val;
    for (; right < n; right++)
    {
        val = val + nums[right] - nums[left++];
        res = max(val, res);
    }
    return ((double)(res)) / ((double)k);
}
int main()
{
    double a = findMaxAverage({1, 12, -5, -6, 50, 3}, 4);
    cout << a;
    return 0;
}