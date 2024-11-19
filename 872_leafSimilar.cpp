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
vector<int> leaf1;
vector<int> leaf2;
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        dfs(root1, leaf1);
        dfs(root2, leaf2);
        return leaf1 == leaf2;
    }

    void dfs(TreeNode* root, vector<int>& result){
        if(root == NULL){
            return;
        }
        if(root->left == NULL && root->right == NULL){
            result.push_back(root->val);
        }
        dfs(root->left, result);
        dfs(root->right, result);
    }
};