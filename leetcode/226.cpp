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
    TreeNode* invertTree(TreeNode* root) {
        if(!root)return nullptr;
        TreeNode *n=new TreeNode(root->val);
        dfsInvertTree(root,n);
        return n;
    }
private:
    void dfsInvertTree(TreeNode* root,TreeNode *&n){
        if(!root)return;
         if(root->left!= nullptr){
             n->right=new TreeNode(root->left->val);
         }
         if(root->right!= nullptr){
             n->left=new TreeNode(root->right->val);
         }
        dfsInvertTree(root->left,n->right);
        dfsInvertTree(root->right,n->left);
    }
};