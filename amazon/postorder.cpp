/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/

void inorder(TreeNode *root, vector<int> &list){
    if(root == NULL){
        return;
    }
   
    
     inorder(root->left, list);
    inorder(root->right, list);
    list.push_back(root->data);
}

vector<int> getPostOrderTraversal(TreeNode *root)
{
   vector <int> list;
   inorder(root, list);
   return list;
}
