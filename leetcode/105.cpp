#include <iostream>
#include <vector>
#include <unordered_map>
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
    // 主函数：通过先序和中序遍历构建二叉树
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // 构建值到索引的映射，以便快速查找中序遍历中的根节点位置
        unordered_map<int, int> inorderIndexMap;
        for (int i = 0; i < inorder.size(); i++) {
            inorderIndexMap[inorder[i]] = i;
        }
        // 调用辅助函数，开始递归构建二叉树
        return buildTreeHelper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inorderIndexMap);
    }

private:
    // 辅助函数：递归构建二叉树
    TreeNode* buildTreeHelper(vector<int>& preorder, int preStart, int preEnd,
                              vector<int>& inorder, int inStart, int inEnd,
                              unordered_map<int, int>& inorderIndexMap) {
        // 递归结束条件：如果子序列为空，返回空指针
        if (preStart > preEnd || inStart > inEnd) {
            return nullptr;
        }

        // 先序遍历的第一个元素是当前子树的根节点
        int rootVal = preorder[preStart];
        TreeNode* root = new TreeNode(rootVal);

        // 在中序遍历中找到根节点的位置
        int rootIndex = inorderIndexMap[rootVal];
        // 计算左子树的大小
        int leftTreeSize = rootIndex - inStart;

        // 递归构建左子树
        root->left = buildTreeHelper(preorder, preStart + 1, preStart + leftTreeSize,
                                     inorder, inStart, rootIndex - 1, inorderIndexMap);
        // 递归构建右子树
        root->right = buildTreeHelper(preorder, preStart + leftTreeSize + 1, preEnd,
                                      inorder, rootIndex + 1, inEnd, inorderIndexMap);

        return root;
    }
};