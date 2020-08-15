//迭代法实现二叉树各序遍历
//用栈模拟递归
 /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
//前序遍历 
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode *> call;
        if(!root){
            return ans;
        }
        call.push(root);
        while(!call.empty()){
            TreeNode * tmp=call.top();
            call.pop();
            if(tmp!=NULL){
                if(tmp->right){
                    call.push(tmp->right);
                }
                if(tmp->left){
                    call.push(tmp->left);
                }
                call.push(tmp);
//                用来区分递归过程还是遍历 
                call.push(NULL);
            }
            else{
                ans.push_back(call.top()->val);
                call.pop();
            }
        }
        return ans;
    }
};

//后序遍历----------------只需要调换入栈顺序 
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode *> call;
        if(!root){
            return ans;
        }
        call.push(root);
        while(!call.empty()){
            TreeNode * tmp=call.top();
            call.pop();
            if(tmp){
                call.push(tmp);
                call.push(NULL);
                if(tmp->right){
                    call.push(tmp->right);
                }
                if(tmp->left){
                    call.push(tmp->left);
                }
            }
            else{
                ans.push_back(call.top()->val);
                call.pop();
            }
        }
        return ans;
    }
}; 
