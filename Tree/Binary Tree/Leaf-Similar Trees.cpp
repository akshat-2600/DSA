/*
    Company Tags    :   
    LeetCode Link   :   https://leetcode.com/problems/leaf-similar-trees/

*/


/******************************************************** C++ ********************************************************/

// T.C   : O(V + E)
// S.C   : O(V + E)

class Solution {
public:
    void dfs(TreeNode* root, vector<int>& ans) {
        if (root == nullptr) {
            return;
        }

        if (root->left == nullptr && root->right == nullptr) {
            ans.push_back(root->val);
        }

        dfs(root->left, ans);
        dfs(root->right, ans);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> ans1, ans2;

        dfs(root1, ans1);
        dfs(root2, ans2);

        for (int val : ans1) {
            cout << val << " ";
        }
        cout << endl;

        for (int val : ans2) {
            cout << val << " ";
        }
        cout << endl;

        return ans1 == ans2;
    }
};