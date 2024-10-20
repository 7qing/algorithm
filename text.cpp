#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

int smallestRangeI(vector<int> nums, int k)
{
    int mi1 = INT_MAX;
    int mi2 = INT_MAX;
    int n = nums.size();
    for (int i; i < n; i++)
        mi1 = min(nums[i], mi1);
    for (int i; i < n; i++)
    {
        int x = min(nums[i], mi2);
        mi2 = x > mi1 ? x : mi2;
    }
    int res = mi2 - mi1 - 2 * k;
    return res > 0 ? res : 0;
}
int main()
{
    int a = smallestRangeI({0, 10}, 2);
    cout << a;
    return 0;
}