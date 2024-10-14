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
    int diameterOfBinaryTree(TreeNode* root) {
        int len=0;
        dep(root,len);
        return len;
    }

    int dep(TreeNode* root, int &len) {
        if(!root)  return 0;
        int hl;
        int hr;
        if(!root->left && !root->right)
        {
            hl=0;
            hr=0;
        }
        else if(!root->left)
        {
            hl=0;
            hr=dep(root->right,len)+1;
        }
        else if(!root->right)
        {
            hr=0;
            hl=dep(root->left,len)+1;
        }
        else{
            hl=dep(root->left,len)+1;
            hr=dep(root->right,len)+1;
        }
        len=max(len,hl+hr);
        return max(hl,hr);
    }
    
};