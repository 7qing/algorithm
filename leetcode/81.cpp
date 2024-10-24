#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool search(vector<int> &nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        // 如果找到了目标值，直接返回 true
        if (nums[mid] == target)
        {
            return true;
        }

        // 处理可能存在的重复元素
        if (nums[left] == nums[mid] && nums[right] == nums[mid])
        {
            left++;
            right--;
        }
        // 如果左半部分是有序的
        else if (nums[left] <= nums[mid])
        {
            // 判断目标值是否在左半部分
            if (nums[left] <= target && target < nums[mid])
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        // 如果右半部分是有序的
        else
        {
            // 判断目标值是否在右半部分
            if (nums[mid] < target && target <= nums[right])
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
    }

    return false; // 如果没找到，返回 false
}