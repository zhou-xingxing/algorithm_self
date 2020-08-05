//打印二叉树所有路径 

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<string> ss;
    string tmp="";
    void dfs(TreeNode * root){
        string tmp2;
        // 方便回溯
        tmp2=tmp;
        if(!root){
            return ;
        }
        if(!root->left && !root->right){
            tmp+=to_string(root->val);
            ss.push_back(tmp);
            tmp=tmp2; //回溯
            return;
        } 
        tmp+=(to_string(root->val)+"->");
        dfs(root->left);
        dfs(root->right);
        tmp=tmp2;  //回溯 
    }  
    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root);
        return ss;
    }
};
