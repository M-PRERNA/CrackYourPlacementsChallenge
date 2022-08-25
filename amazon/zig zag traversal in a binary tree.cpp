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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
//         a result vector storing the list of each levels
        vector<vector<int>> result;
        if (root == NULL) return result; //empty result 
        
        queue <TreeNode*> NodesQueue;
        NodesQueue.push(root);
        
//         creating a variable to decid ethe direction of insertion in result queue
        bool leftToright = true;
        
        while (!NodesQueue.empty()){
            int size = NodesQueue.size();
            vector<int> row(size);
            
            for(int i = 0; i<size; i++){
                TreeNode* node = NodesQueue.front();
                NodesQueue.pop();
                
                int index = leftToright ? i : size - 1 -i;
//                 decide whetehr to insert from the front or from the back
                row[index] = node->val;
                if(node->left){
                    NodesQueue.push(node->left);
                }
                if(node->right){
                    NodesQueue.push(node->right);
                }
                
            }
            
//             now one row has been inserted so reverse the order for spiral insertion
            leftToright = !leftToright;
            result.push_back(row);
        }
        return result;
    }
};
