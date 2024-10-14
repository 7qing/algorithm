
    #include <iostream>
#include <vector>
#include <queue>

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
class Solution {
public:
    void flatten(TreeNode* root) {
    // 如果根节点为空，则直接返回
    if (!root) return;

    // 当前遍历的节点，从根节点开始
    TreeNode* current = root;
    
    // 遍历每个节点
    while (current) {
        // 如果当前节点有左子树
        if (current->left) {
            // 寻找左子树的最右节点
            TreeNode* predecessor = current->left;
            while (predecessor->right) {
                predecessor = predecessor->right;
            }
            // 将当前节点的右子树链接到最右节点的右指针
            predecessor->right = current->right;
            // 将左子树替换成当前节点的右子树
            current->right = current->left;
            current->left = nullptr; // 清空左指针
        }
        // 移动到下一个节点
        current = current->right;
    }
}
};