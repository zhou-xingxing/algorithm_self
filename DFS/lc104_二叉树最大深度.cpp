// 二叉树最大深度

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//递归解法 
class Solution {
public:
    int dfs(TreeNode *root){
        if(root==NULL){
            return 0;
        }
        int l=dfs(root->left);
        int r=dfs(root->right);
        return max(l,r)+1;
    }

    int maxDepth(TreeNode* root) {
       return dfs(root);
    }
}; 

//BFS解法 
class Solution {
public:
    queue<TreeNode *>q;
    int maxDepth(TreeNode* root) {
       int depth=0;
       if(root==NULL){
           return 0;
       }
       q.push(root);
       while(!q.empty()){
           int size=q.size();
           while(size){
               TreeNode * tmp=q.front();
               q.pop();
               if(tmp->left){
                   q.push(tmp->left);
               }
               if(tmp->right){
                   q.push(tmp->right);
               }
               size--;
           }
           depth++;
       }
       return depth;
    }
};
