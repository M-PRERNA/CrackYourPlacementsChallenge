#include<bits/stdc++.h>
/*************************************************************
    Following is the Binary Tree node structure
    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };
*************************************************************/
int isBalanced(BinaryTreeNode<int>* root){
    if(root == NULL){
        return 0;
    }
    int leftHeight = isBalanced(root->left);
    int rightHeight = isBalanced(root->right);
    
    if(leftHeight == -1 || rightHeight == -1) return -1;
    if(abs(leftHeight - rightHeight) > 1) return -1;
    
    return max(leftHeight, rightHeight) + 1;
}
bool isBalancedBT(BinaryTreeNode<int>* root) {
    // Write your code here.
    int val = isBalanced(root);
    if(val == -1) return false;
    return true;
}
