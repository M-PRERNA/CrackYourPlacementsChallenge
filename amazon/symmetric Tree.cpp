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
    bool symmetricCheck(TreeNode* leftTree, TreeNode* rightTree){
        if (leftTree == NULL || rightTree == NULL) return leftTree == rightTree;
        
        if(leftTree->val != rightTree->val) return false;
        
        return symmetricCheck(leftTree->left, rightTree->right) 
               &&
               symmetricCheck(leftTree->right, rightTree->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        
        return root==NULL || symmetricCheck(root->left, root->right);
        
    }
};
