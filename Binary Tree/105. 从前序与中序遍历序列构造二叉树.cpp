/*
给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历， inorder 是同一棵树的中序遍历，请构造二叉树并返回其根节点。

 

示例 1:


输入: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
输出: [3,9,20,null,null,15,7]
示例 2:

输入: preorder = [-1], inorder = [-1]
输出: [-1]
 

提示:

1 <= preorder.length <= 3000
inorder.length == preorder.length
-3000 <= preorder[i], inorder[i] <= 3000
preorder 和 inorder 均 无重复 元素
inorder 均出现在 preorder
preorder 保证 为二叉树的前序遍历序列
inorder 保证 为二叉树的中序遍历序列
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
    TreeNode* Traversal(vector<int>& preorder, int pl, int pr, vector<int>& inorder, int il, int ir) {
        if(pl == pr) return nullptr;
        int rootval = preorder[pl];
        TreeNode *root = new TreeNode(rootval);

        // 切割点
        int delimiterIndex;
        for(delimiterIndex = il; delimiterIndex < ir; delimiterIndex++) {
            if(inorder[delimiterIndex] == rootval) break;
        }

        // 切割前序数组
        int lpl = pl + 1;
        int lpr = lpl + delimiterIndex - il;
        int rpl = lpr;
        int rpr = pr;

        // 切割中序数组
        int lil = il;
        int lir = delimiterIndex;
        int ril = lir + 1;
        int rir = ir;

        root->left = Traversal(preorder, lpl, lpr, inorder, lil, lir);
        root->right = Traversal(preorder, rpl, rpr, inorder, ril, rir);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0 || inorder.size() == 0) return nullptr;
        return Traversal(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
};
