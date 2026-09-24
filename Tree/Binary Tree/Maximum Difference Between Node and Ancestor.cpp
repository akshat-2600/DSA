/*
    Company Tags    :   GOOGLE, MICROSOFT, META
    LeetCode Link   :   https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/description/

*/


/******************************************************** C++ ********************************************************/

// T.C   : O((V + E)^2)
// S.C   : O((V + E)^2)


class Solution {
public:
    int maxDiff = -1;

    void findMaxDiffUtil(TreeNode* root, TreeNode* child) {
        if (child == NULL) {
            return;
        }

        maxDiff = max(maxDiff, abs(root->val - child->val));
        findMaxDiffUtil(root, child->left);
        findMaxDiffUtil(root, child->right);
    }

    int maxAncestorDiff(TreeNode* root) {
        if (root == NULL) {
            return -1;
        }

        findMaxDiffUtil(root, root->left);
        findMaxDiffUtil(root, root->right);

        maxAncestorDiff(root->left);
        maxAncestorDiff(root->right);

        return maxDiff;
    }
};

// T.C   : O(V + E)
// S.C   : O(V + E)


class Solution {
public:
    int findMaxDiff(TreeNode* root, int maxVal, int minVal) {
        if (root == nullptr) {
            return abs(maxVal - minVal);
        }

        maxVal = max(maxVal, root->val);
        minVal = min(minVal, root->val);

        int leftMaxDiff  = findMaxDiff(root->left, maxVal, minVal);
        int rightMaxDiff = findMaxDiff(root->right, maxVal, minVal);

        return max(leftMaxDiff, rightMaxDiff);
    }

    int maxAncestorDiff(TreeNode* root) {
        return findMaxDiff(root, root->val, root->val);
    }
};