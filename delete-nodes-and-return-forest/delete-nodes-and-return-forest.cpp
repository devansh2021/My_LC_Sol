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
    TreeNode* helper(TreeNode* root, set<int> &s, vector<TreeNode*> &roots, bool isroot)
    {
        if(root==NULL)
            return NULL;
         bool deleted=(s.count(root->val)>0)?1:0;
        if(isroot&&!deleted){
            roots.push_back(root);
        }
        root->left=helper(root->left,s,  roots,deleted);
        root->right=helper(root->right, s, roots, deleted);
        return deleted?NULL:root;
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> roots;
        set<int> s(to_delete.begin(), to_delete.end());
        helper(root, s, roots, true);
        return roots;
    }
};