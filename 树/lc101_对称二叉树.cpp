//对称二叉树

//层序遍历+队列写法
 
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
    bool test(vector<TreeNode *> & num){
        int size=num.size();
        for(int i=0;i<size/2;i++){
            //比较值之前一定先判断指针是否为空
            if(!num[i]&&!num[size-1-i]){
                continue;
            }
            if(!num[i]||!num[size-1-i]){
                return false;
            }
            if(num[i]->val != num[size-1-i]->val){
                return false;
            }
        }
        return true;
    }
    
    bool isSymmetric(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<TreeNode *> num;
            for(int i=0;i<size;i++){
                TreeNode * tmp= q.front();
                q.pop();               
                if(tmp->left){
                    q.push(tmp->left);
                    num.push_back(tmp->left);
                }
                else{
                    num.push_back(NULL);
                }                 
                if(tmp->right){
                    q.push(tmp->right);
                    num.push_back(tmp->right);
                }
                else{
                    num.push_back(NULL);
                }                   
            }
            if(!test(num)){
                return false;
            }
        }
        return true;
    }
};

//递归写法
class Solution {
public:
    bool mirror(TreeNode * p,TreeNode * q){
        if(p==NULL&&q==NULL){
            return true;
        }
        if(p==NULL||q==NULL){
            return false;
        }
        return ((p->val==q->val)&&mirror(p->left,q->right)&&mirror(p->right,q->left));
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        return mirror(root->left,root->right);
    }
}; 
