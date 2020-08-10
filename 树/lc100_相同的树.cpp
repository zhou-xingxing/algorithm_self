//相同的树

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
    bool dfs(TreeNode * p,TreeNode * q){
        if(!p && !q){
            return true;
        }
        if(!p || !q){
            return false;
        }
        //访问指针之前一定先检查是否为空
       return (p->val==q->val)&&dfs(p->left,q->left)&&dfs(p->right,q->right);   
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
       return dfs(p,q);      
    }
};
