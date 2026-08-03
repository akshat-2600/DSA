/*
    Company Tags                : 
    Leetcode Link               : https://leetcode.com/problems/binary-tree-inorder-traversal/description/
*/


/**************************************************************** C++ ****************************************************************/

//Approach : Recursion
//T.C : O(n)
//S.C : O(height of binary tree)


class Solution {
public:
    void solve(TreeNode* root, vector<int>& ans) {
        if (root == NULL) {
            return;
        }

        solve(root->left, ans);
        ans.push_back(root->val);
        solve(root->right, ans);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        solve(root, ans);
        return ans;
    }
};

/**************************************************************** JAVA ****************************************************************/

//Approach : Recursion
//T.C : O(n)
//S.C : O(height of binary tree)

class Solution {
    public void solve(TreeNode root, List<Integer> ans) {
        if (root == null) {
            return;
        }

        solve(root.left, ans);
        ans.add(root.val);
        solve(root.right, ans);
    }

    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> ans = new ArrayList<>();

        solve(root, ans);
        return ans;
    }
}