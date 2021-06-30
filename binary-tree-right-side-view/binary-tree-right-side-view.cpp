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
 
struct TreeNode{
    int val;
    TreeNode* left, right;
    TreeNode(): val(0), left(NULL), right(NULL){};
    TreeNode(int x) : val(x), left(NULL), right(NULL){};
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right){};
};
*/
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> ans;
        if(root==NULL)
            return ans;
        q.push(root);
        while(!q.empty())
        {
            int q_size=q.size();
            for(int i=0;i<q_size;i++)
            {
                TreeNode* cur=q.front();
                q.pop();
                if(i==q_size-1){
                   // cout<<cur->val;
                    ans.emplace_back(cur->val);
                }
                if(cur->left)
                    q.push(cur->left);
                if(cur->right)
                    q.push(cur->right);
            }
        }
        return ans;
    }
};