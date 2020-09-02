//验证平衡二叉树 

class Solution {
public:
    bool balance=true;
    int depth(TreeNode* root){
        if(!root){
            return 0;
        }
        if(balance==false){
            return 0;
        }
        int left=depth(root->left);
        int right=depth(root->right);
        if(left-right>1 || right-left>1){
            balance=false;
        }
        return 1+max(left,right);
    }
    
    
    bool isBalanced(TreeNode* root) {
        depth(root);
        return balance;
    }
};
