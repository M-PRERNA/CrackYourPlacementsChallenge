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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inmap;
        
        int ind = 0;
        for(auto it: inorder){
            inmap[it] = ind;
            ind+=1;
        }
        
        TreeNode* root = buildTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, inmap);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder,int ps, int pe, vector<int>& inorder, int is, int ie, unordered_map<int, int> &inmap){
        
        if(is>ie || ps>pe) return NULL;
        
        TreeNode* root = new TreeNode(preorder[ps]);
        
//        find the root in the inorder
        int iroot = inmap[root->val];
        int numsleft = iroot - is;
        
//         build the left subtree
        root->left = buildTree(preorder, ps+1, pe , inorder, is, iroot-1, inmap);
//         build the right subtree
        root->right = buildTree(preorder, ps+numsleft+1, pe , inorder, iroot+1, ie, inmap);
        return root;  
    }
    
};
