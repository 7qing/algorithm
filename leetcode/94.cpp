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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        zhongxu(root,ans);
        return ans;
    }
private:
    void zhongxu(TreeNode* root,vector<int> &n1)
    {
        if(root==nullptr)
            return;
        zhongxu(root->left,n1);
        n1.push_back(root->val);
        zhongxu(root->right,n1);
    }
};