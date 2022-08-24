#include<bits/stdc++.h>
/************************************************************
// width of a binary tree
    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
int heightModified(TreeNode<int> *root, int &maxi){
    if (root == NULL){
        return 0;
    }
    int lh = heightModified(root->left, maxi);
    int rh = heightModified(root->right, maxi);
    maxi = max(maxi, lh + rh);
    
    return max(lh , rh) + 1;
}

int diameterOfBinaryTree(TreeNode<int> *root)
{
    int maxi = 0;
	heightModified(root, maxi);
    return maxi;
}
