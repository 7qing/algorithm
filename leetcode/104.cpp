#include <iostream>
#include <vector>
#include <functional>

using namespace std;

/**
 * Definition for a binary tree node. */
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
    int maxDepth(TreeNode* root) {
    // int max = 0;

    // std::function<void(TreeNode*, int)> zhongxu = [&](TreeNode* node, int ans) {
    //     if (node == nullptr)
    //         return;
    //     if (ans == max) {
    //         max++;
    //     }
    //     ans++;
    //     zhongxu(node->left, ans);
    //     zhongxu(node->right, ans);
    // };

    // zhongxu(root, 0);
    // return max;
    if (root == NULL)
        return 0;
        
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;

}
private:
    
};