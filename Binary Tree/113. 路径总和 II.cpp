/*
给你二叉树的根节点 root 和一个整数目标和 targetSum ，找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径。

叶子节点 是指没有子节点的节点。

 

示例 1：


输入：root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
输出：[[5,4,11,2],[5,8,4,5]]
示例 2：


输入：root = [1,2,3], targetSum = 5
输出：[]
示例 3：

输入：root = [1,2], targetSum = 0
输出：[]
 

提示：

树中节点总数在范围 [0, 5000] 内
-1000 <= Node.val <= 1000
-1000 <= targetSum <= 1000
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
private:
    vector<vector<int>> result;
    unordered_map<TreeNode*, TreeNode*> parent;
public:
    vector<int> getPath(TreeNode* node) {
        vector<int> temp;
        while(node) {
            temp.push_back(node->val);
            node = parent[node];
        }
        reverse(temp.begin(), temp.end());
        return temp;
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        queue<TreeNode*> que;
        queue<int> que_val;
        if(!root) return result;
        que.push(root);
        que_val.push(root->val);
        while(!que.empty() && !que_val.empty()) {
            TreeNode *node = que.front();
            int temp = que_val.front();
            que.pop();
            que_val.pop();
            if(node->left == nullptr && node->right == nullptr) {
                if(temp == targetSum) {
                    result.push_back(getPath(node));
                }
            }
            if(node->left) {
                parent[node->left] = node;
                que.push(node->left);
                que_val.push(node->left->val + temp);
            }
            if(node->right) {
                parent[node->right] = node;
                que.push(node->right);
                que_val.push(node->right->val + temp);
            }
        }
        return result;
    }
};
