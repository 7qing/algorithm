#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        // 确保 nums1 是较短的数组，以减少二分查找的复杂性
        if (nums1.size() > nums2.size())
        {
            return findMedianSortedArrays(nums2, nums1);
        }

        int n1 = nums1.size();
        int n2 = nums2.size();

        // 进行二分查找，设定 nums1 的搜索范围
        int low = 0, high = n1;

        while (low <= high)
        {
            // 在 nums1 中找到切割位置 cut1
            int cut1 = low + (high - low) / 2;

            // 计算 nums2 中对应的切割位置 cut2
            int cut2 = (n1 + n2 + 1) / 2 - cut1;

            // 获取切割后 nums1 左侧最大值 (考虑边界)
            int left1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];

            // 获取切割后 nums2 左侧最大值 (考虑边界)
            int left2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];

            // 获取切割后 nums1 右侧最小值 (考虑边界)
            int right1 = (cut1 == n1) ? INT_MAX : nums1[cut1];

            // 获取切割后 nums2 右侧最小值 (考虑边界)
            int right2 = (cut2 == n2) ? INT_MAX : nums2[cut2];

            // 检查切割是否符合条件：左侧部分的最大值小于等于右侧部分的最小值
            if (left1 <= right2 && left2 <= right1)
            {
                // 如果总元素个数为奇数，中位数是左半部分的最大值
                if ((n1 + n2) % 2 == 1)
                {
                    return max(left1, left2);
                }
                else
                {
                    // 如果总元素个数为偶数，中位数是左半部分最大值和右半部分最小值的平均值
                    return (max(left1, left2) + min(right1, right2)) / 2.0;
                }
            }
            // 如果左侧的最大值不符合条件，调整搜索范围
            else if (left1 > right2)
            {
                // 左侧的最大值太大，减少 cut1 以缩小范围
                high = cut1 - 1;
            }
            else
            {
                // 左侧的最大值太小，增加 cut1 以扩大范围
                low = cut1 + 1;
            }
        }

        // 逻辑上不会到达这里，但函数需要有返回值
        return -1.0;
    }
};
