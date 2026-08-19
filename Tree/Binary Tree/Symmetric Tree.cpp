/*
    Company Tags        : 
    Leetcode Link       :  https://leetcode.com/problems/symmetric-tree/
*/


/********************************************************************* C++ ****************************************************************/

// Approach : Recursion
// T.C      : O(N) * O(N)
// S.C      : O(1)


class Solution {
public:
    bool isMirror(TreeNode* left, TreeNode* right) {
        if (!left && !right) {
            return true;
        }
        if (!left || !right) {
            return false;
        }
        if (left->val != right->val) {
            return false;
        }
        return isMirror(left->left, right->right) && isMirror(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {
        return isMirror(root->left, root->right);
    }
};



/********************************************************************* JAVA ****************************************************************/

// Approach : Recursion
// T.C      : O(N) * O(N)
// S.C      : O(1)

class Solution {
public:
    bool isMirror(TreeNode* left, TreeNode* right) {
        if (!left && !right) {
            return true;
        }
        if (!left || !right) {
            return false;
        }
        if (left->val != right->val) {
            return false;
        }
        return isMirror(left->left, right->right) && isMirror(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {
        return isMirror(root->left, root->right);
    }
};