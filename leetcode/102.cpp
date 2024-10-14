#include <iostream>
#include <vector>
#include <queue>

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret; // 用于存储结果的二维向量
        if(root == nullptr)
            return ret; // 如果根节点为空，直接返回空结果

        queue<TreeNode*> st; // 队列用于存储当前层的节点
        st.push(root); // 将根节点加入队列

        while(!st.empty()) { // 当队列不为空时，继续循环
            int n = st.size(); // 当前层的节点数
            vector<int> tmp; // 存储当前层的节点值

            while(n--) { // 遍历当前层的所有节点
                TreeNode* temp = st.front(); // 获取当前层的一个节点
                st.pop(); // 将其从队列中移除
                tmp.push_back(temp->val); // 将节点值加入当前层结果

                if(temp->left) // 如果左子节点存在，将其加入队列
                    st.push(temp->left);
                if(temp->right) // 如果右子节点存在，将其加入队列
                    st.push(temp->right);
            }
            ret.push_back(tmp); // 将当前层的结果加入最终结果
        } 
        return ret; // 返回最终结果
    }

};