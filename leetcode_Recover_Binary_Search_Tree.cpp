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
    void recoverTree(TreeNode* root) {
        vector<TreeNode* > address;
        vector<int> value;
        inorder(root,address,value);
        std::sort(value.begin(),value.end());
        for(int i=0;i<value.size();++i){
            address[i]->val = value[i];
        }
        return ;
    }
    void inorder(TreeNode* root,vector<TreeNode* >& address,vector<int>& value){
        if(root->left==nullptr && root->right==nullptr){
            address.push_back(root);
            value.push_back(root->val);
            return;
            }
        if(root->left){
            inorder(root->left,address,value);
        }
        address.push_back(root);
        value.push_back(root->val);
        if(root->right){
            inorder(root->right,address,value);
        }
    }
    
};
