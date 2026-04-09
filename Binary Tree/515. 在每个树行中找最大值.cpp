/*
给定一棵二叉树的根节点 root ，请找出该二叉树中每一层的最大值。

 

示例1：



输入: root = [1,3,2,5,3,null,9]
输出: [1,3,9]
示例2：

输入: root = [1,2,3]
输出: [1,3]
 

提示：

二叉树的节点个数的范围是 [0,104]
-231 <= Node.val <= 231 - 1
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        queue<TreeNode*> que;
        if(root) que.push(root);
        while(!que.empty()) {
            int size = que.size();
            int maxNum = INT_MIN;
            for(int i = 0; i < size; i++) {
                TreeNode *node = que.front();
                que.pop();
                maxNum = max(maxNum, node->val);
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
            result.push_back(maxNum);
        }
        return result;
    }
};
