/*
给你一棵二叉树的根节点 root ，返回其节点值的 后序遍历 。

 

示例 1：

输入：root = [1,null,2,3]

输出：[3,2,1]

解释：



示例 2：

输入：root = [1,2,3,4,5,null,8,null,null,6,7,9]

输出：[4,6,7,5,2,9,8,3,1]

解释：



示例 3：

输入：root = []

输出：[]

示例 4：

输入：root = [1]

输出：[1]

 

提示：

树中节点的数目在范围 [0, 100] 内
-100 <= Node.val <= 100
*/

// 1、递归
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
    void traversal(TreeNode *cur, vector<int> &result)
    {
        if(cur == nullptr) return;

        traversal(cur->left, result);
        traversal(cur->right, result);
        result.push_back(cur->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        traversal(root, result);
        return result;
    }
};

// 2、迭代
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        if(!root) return result;
        st.push(root);
        while(!st.empty()) {
            TreeNode *node = st.top();
            result.push_back(node->val);
            st.pop();
            if(node->left) st.push(node->left);
            if(node->right) st.push(node->right);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
