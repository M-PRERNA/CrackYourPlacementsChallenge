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
    int maxpath(TreeNode* root, int &maxSum){
        if (root == NULL) return 0;
        
        int ls = max(0, maxpath(root->left, maxSum));        
        int rs = max(0, maxpath(root->right, maxSum));
        
        maxSum = max (maxSum, root->val + ls + rs);
        
        return root->val + max(ls, rs);
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        
        maxpath(root, maxSum);
        
        return maxSum;
    }
};
