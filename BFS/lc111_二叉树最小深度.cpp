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
    queue<TreeNode *> q;
    
    int minDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int depth=1;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            TreeNode *tmp;
            for(int i=0;i<size;i++){            
                tmp=q.front();
                q.pop();
                if(tmp->left==NULL && tmp->right==NULL){
                    return depth;
                }
                if(tmp->left)
                    q.push(tmp->left);
                if(tmp->right)
                    q.push(tmp->right);
            }
            depth++;
        }
        return depth;
    }
};
