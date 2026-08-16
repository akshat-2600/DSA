/*
    Company Tags    :   
    LeetCode Link   :   https://leetcode.com/problems/maximum-depth-of-binary-tree/
*/


/**************************************************************** C++ ****************************************************************/

// T.C      : O(n)
// S.C      : O(1)


class Solution {
public:
    int solve(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int left = 1 + solve(root->left);
        int right = 1 + solve(root->right);
        return max(left, right);
    }

    int maxDepth(TreeNode* root) {
        return solve(root);
    }
};

/**************************************************************** JAVA ****************************************************************/


// T.C      : O(n)
// S.C      : O(1)


class Solution {
    int solve(TreeNode root) {
        if (root == null) return 0;

        int left = 1 + solve(root.left);
        int right = 1 + solve(root.right);

        return Math.max(left, right);
    }

    public int maxDepth(TreeNode root) {
        return solve(root);
    }
}