/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    vector<int> ans;
    void preorderHelper(Node* root)
    {
        if(root==NULL)
            return ;
        ans.emplace_back(root->val);
        for(auto child:root->children)
            preorderHelper(child);
        return;
    }
public:
    vector<int> preorder(Node* root) {
        preorderHelper(root);
        return ans;
    }
};