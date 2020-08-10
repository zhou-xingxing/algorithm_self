//����һ����������һ��Ŀ��ͣ��ҵ����дӸ��ڵ㵽Ҷ�ӽڵ�·���ܺ͵��ڸ���Ŀ��͵�·����
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
        //�Ƚ����׺��Ե��ǣ��ҵ���ȷ��֮��ҲҪ�ǵû��ݣ���Ϊ��Ҫ��ȫ���� 
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
