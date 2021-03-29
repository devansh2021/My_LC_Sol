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
class Solution
{
  bool preorderTraverse(TreeNode *root, vector<int> &v, int &i, vector<int> &ans)
  {
    if (root == nullptr)
      return true;
    if (root->val != v[i++])
      return false;
    auto l = root->left;
    auto r = root->right;
    if (l)
    {
      if (l->val != v[i])
      {
        swap(l, r);
        ans.emplace_back(root->val);
      }
    }
    return preorderTraverse(l, v, i, ans) && preorderTraverse(r, v, i, ans);
  }

public:
  vector<int> flipMatchVoyage(TreeNode *root, vector<int> &voyage)
  {
    vector<int> ans;
    int i = 0;
    return preorderTraverse(root, voyage, i, ans) ? ans : vector<int>() = {-1};
  }
};