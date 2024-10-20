#include <iostream>
#include <vector>

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
    bool rotateSame(TreeNode* left, TreeNode* right) {
        if(!left && !right) return true;
        if(!left && right) return false;
        if(left && !right) return false;
        if(left && right && left->val != right->val) return false;
        bool outsideSame = rotateSame(left->left, right->right);
        bool insideSame = rotateSame(left->right, right->left);
        return outsideSame && insideSame;
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return rotateSame(root->left, root->right);
    }
};