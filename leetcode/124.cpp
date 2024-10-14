
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 二叉树节点的定义
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
     int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;  // 记录全局的最大路径和
        findMax(root, maxSum);
        return maxSum;
    }
    
    // 这个函数返回的是从某个节点向下延伸的最大路径和（只能向下走）
    int findMax(TreeNode* node, int& maxSum) {
        if (node == nullptr) {
            return 0;  // 空节点的路径和为 0
        }
        
        // 递归计算左右子树的最大路径和，只有当路径和大于 0 时才考虑该路径
        int leftMax = max(0, findMax(node->left, maxSum));
        int rightMax = max(0, findMax(node->right, maxSum));
        
        // 计算经过当前节点的路径和（包括左右子树的最大路径）
        int currentPathSum = node->val + leftMax + rightMax;
        
        // 更新全局最大路径和
        maxSum = max(maxSum, currentPathSum);
        
        // 返回从当前节点向下延伸的最大路径和（只能选择左或右子树的一条路径）
        return node->val + max(leftMax, rightMax);
    }
};