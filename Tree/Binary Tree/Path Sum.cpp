/*
    Company Tags    :   
    Leetcode Link   :   https://leetcode.com/problems/path-sum/description/

*/


/******************************************************** C++ ********************************************************/

// T.C  : O(N)
// S.C  : O(N) (call stack)

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == NULL) {
            return false;
        }

        if (root->left == NULL && root->right == NULL) {
            return targetSum == root->val;
        }
        int newSum = targetSum - root->val;
        return hasPathSum(root->left, newSum) || hasPathSum(root->right, newSum);
    }
};



/******************************************************** JAVA ********************************************************/


// T.C  : O(N)
// S.C  : O(N) (call stack)

/**
 * Definition for a binary tree node.
 */
public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    
    TreeNode() {}
    
    TreeNode(int val) { 
        this.val = val; 
    }
    
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Solution {
    public boolean hasPathSum(TreeNode root, int targetSum) {
        // Base case: if the tree is empty
        if (root == null) {
            return false;
        }
        
        // Base case: if it's a leaf node, check if the remaining sum equals the node's value
        if (root.left == null && root.right == null) {
            return targetSum == root.val;
        }
        
        // Recursively check the left and right subtrees with the updated target sum
        int newSum = targetSum - root.val;
        return hasPathSum(root.left, newSum) || hasPathSum(root.right, newSum);
    }
}
