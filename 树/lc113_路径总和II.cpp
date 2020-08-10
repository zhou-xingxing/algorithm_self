//给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。
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
    vector<vector<int>> ans;
    vector<int> tmp;
    int tmpsum=0;
    void dfs(TreeNode * root,int sum){
        if(root==NULL){
            return;
        }
        tmpsum+=root->val;
        tmp.push_back(root->val);
        //比较容易忽略的是，找到正确答案之后也要记得回溯，因为是要找全部答案 
        if(tmpsum==sum && !root->left && !root->right){
            ans.push_back(tmp);
        }
        else{
            dfs(root->left,sum);
            dfs(root->right,sum);
        }
        tmpsum-=root->val;
        tmp.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
         dfs(root,sum);
         return ans;
    }
};
