//��֤����������������ֻ�Ƚϸ��ڵ���ӽڵ�Ĺ�ϵ 
class Solution {
public:
    bool valid(TreeNode * root,long long lower,long long upper){
        if(!root){
            return true;
        }
        if(root->val<=lower || root->val>=upper){
            return false;
        }
        else{
            return valid(root->left,lower,root->val)&&valid(root->right,root->val,upper);
        }    
    }

    bool isValidBST(TreeNode* root) {
        
        return valid(root,LONG_MIN,LONG_MAX);
    }
};
