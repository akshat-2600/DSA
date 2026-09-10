/*
    Company Tags    :   
    Leetcode Link   :   https://leetcode.com/problems/binary-tree-pruning/description/

*/


/******************************************************** C++ ********************************************************/


// Approach : Brute force visiting every node twice
// T.C      : O(N^2)
// S.C      : O(N) (recursion call stack)

class Solution {
public:
    bool isOnePresent(TreeNode* node) {
        if (node == NULL) {
            return false;
        }

        if (node->val == 1) {
            return true;
        }

        return isOnePresent(node->left) || isOnePresent(node->right);
    }

    TreeNode* pruneTree(TreeNode* root) {
        if (root == NULL) {
            return NULL;
        }

        if (!isOnePresent(root->left)) {
            root->left = NULL;
        }

        if (!isOnePresent(root->right)) {
            root->right = NULL;
        }

        pruneTree(root->left);
        pruneTree(root->right);

        if (root->left == NULL && root->right == NULL && root->val == 0) {
            return NULL;
        }
        return root;
    }
};

// Approach : DFS
// T.C      : O(N)
// S.C      : O(N) (recursion call stack)

class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if (root == NULL) {
            return NULL;
        }

        root->left  = pruneTree(root->left);
        root->right = pruneTree(root->right);

        if (root->left == NULL && root->right == NULL && root->val == 0) {
            return NULL;
        }
        return root;
    }
};


/******************************************************** JAVA ********************************************************/


// Approach : Brute force visiting every node twice
// T.C      : O(N^2)
// S.C      : O(N) (recursion call stack)


class Solution {
    boolean isOnePresent(TreeNode node) {
        if (node == null) {
            return false;
        }

        if (node.val == 1) {
            return true;
        }

        return isOnePresent(node.left) || isOnePresent(node.right);
    }

    public TreeNode pruneTree(TreeNode root) {
        if (root == null) {
            return null;
        }
        
        if (!isOnePresent(root.left)) {
            root.left = null;
        }

        if (!isOnePresent(root.right)) {
            root.right = null;
        }

        pruneTree(root.left);
        pruneTree(root.right);

        if (root.left == null && root.right == null && root.val == 0) {
            return null;
        }
        return root;
    }
}

// Approach : DFS
// T.C      : O(N)
// S.C      : O(N) (recursion call stack)

class Solution {
    public TreeNode pruneTree(TreeNode root) {
        if (root == null) {
            return null;
        }

        root.left  = pruneTree(root.left);
        root.right = pruneTree(root.right);

        if (root.left == null && root.right == null && root.val == 0) {
            return null;
        }

        return root;
    }
}