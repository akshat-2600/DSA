/*
    Company Tags       :   GOOGLE
    LeetCode Link      :   https://leetcode.com/problems/minimum-absolute-difference-in-bst/
                           https://leetcode.com/problems/minimum-distance-between-bst-nodes/
    GeeksForGeeks Link :   https://www.geeksforgeeks.org/problems/minimum-absolute-difference-in-bst-1665139652/1
*/


/******************************************************** C++ ********************************************************/

// Approach : Inorder + Array storage and calculating adjacent differnce from i = 1
// T.C      : O(n)
// S.C      : O(n)



class Solution {
public:
    void inorder(TreeNode* root, vector<int>& ans) {
        if (root == NULL) {
            return;
        }
        
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }

    int getMinimumDifference(TreeNode* root) {
        vector<int> ans;
        
        inorder(root, ans);
        
        int minDiff = INT_MAX;
        for (int i = 1; i < ans.size(); i++) {
            minDiff = min(minDiff, abs(ans[i-1] - ans[i]));
        }
        
        return minDiff == INT_MAX ? -1 : minDiff;
    }
};


// Approach : Inorder + Array storage and calculating adjacent differnce from i = 1
// T.C      : O(n)
// S.C      : O(n)


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
    int minDiff = INT_MAX;

    void inorder(TreeNode* root, TreeNode*& prev) {
        if (root == NULL) {
            return;
        }
        
        inorder(root->left, prev);
        if (prev != NULL) {
            minDiff = min(minDiff, abs(root->val - prev->val));
        }
        prev = root;
        inorder(root->right, prev);
    }

    int getMinimumDifference(TreeNode* root) {
        TreeNode* prev = NULL;
        inorder(root, prev);
        
        return minDiff;
    }
};