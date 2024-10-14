#include <iostream>
#include <vector>

using namespace std;

// 二叉树节点的定义
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 解决方案类
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBSTHelper(nums, 0, nums.size() - 1);
    }

private:
    TreeNode* sortedArrayToBSTHelper(const vector<int>& nums, int left, int right) {
        if (left > right) {
            return nullptr;
        }

        // 选择中间元素作为根节点
        int mid = left + (right - left) / 2;
        TreeNode* node = new TreeNode(nums[mid]);

        // 递归构建左子树和右子树
        node->left = sortedArrayToBSTHelper(nums, left, mid - 1);
        node->right = sortedArrayToBSTHelper(nums, mid + 1, right);

        return node;
    }
};