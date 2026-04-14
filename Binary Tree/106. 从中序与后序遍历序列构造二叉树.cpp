/*
给定两个整数数组 inorder 和 postorder ，其中 inorder 是二叉树的中序遍历， postorder 是同一棵树的后序遍历，请你构造并返回这颗 二叉树 。

 

示例 1:


输入：inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
输出：[3,9,20,null,null,15,7]
示例 2:

输入：inorder = [-1], postorder = [-1]
输出：[-1]
 

提示:

1 <= inorder.length <= 3000
postorder.length == inorder.length
-3000 <= inorder[i], postorder[i] <= 3000
inorder 和 postorder 都由 不同 的值组成
postorder 中每一个值都在 inorder 中
inorder 保证是树的中序遍历
postorder 保证是树的后序遍历
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
    TreeNode* Traversal(vector<int>& inorder, int il, int ir, vector<int>& postorder, int pl, int pr) {
        if(pl == pr) return nullptr;
        int rootval = postorder[pr - 1];
        TreeNode *root = new TreeNode(rootval);
        
        // 切割点
        int delimiterIndex;
        for(delimiterIndex = il; delimiterIndex < ir; delimiterIndex++) {
            if(inorder[delimiterIndex] == rootval) break;
        }

        // 切割中序数组
        int lil = il;
        int lir = delimiterIndex;
        int ril = lir + 1;
        int rir = ir;

        // 切割后序数组
        int lpl = pl;
        int lpr = pl + delimiterIndex - il;
        int rpl = lpr;
        int rpr = pr - 1;

        root->left = Traversal(inorder, lil, lir, postorder, lpl, lpr);
        root->right = Traversal(inorder, ril, rir, postorder, rpl, rpr);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() == 0 || postorder.size() == 0) {
            return nullptr;
        }
        return Traversal(inorder, 0, inorder.size(), postorder, 0, postorder.size());
    }
};
