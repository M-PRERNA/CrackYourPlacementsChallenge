class Solution {
    
private:
    int checkHeightLeft(TreeNode* node){
        if(!node) return 0;
        int height = 0;
        
        while(node != NULL){
            height++;
            node = node->left;
        }
        
        return height;
    }
    
    int checkHeightRight(TreeNode* node){
        if(!node) return 0;
        int height = 0;
        
        while(node != NULL){
            height++;
            node = node->right;
        }
        
        return height;
    }
    
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        
        int leftHeight = checkHeightLeft(root);
        int rightHeight = checkHeightRight(root);
        
        if(leftHeight == rightHeight) return (1<<leftHeight) - 1;
        
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
