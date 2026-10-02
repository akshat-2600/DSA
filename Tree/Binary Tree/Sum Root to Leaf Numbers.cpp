/*
    Company Tags    :   
    LeetCode Link   :   https://leetcode.com/problems/sum-root-to-leaf-numbers/

*/    

/******************************************************** C++ ********************************************************/

// Approach : Preorder
// T.C      : O(n)
// S.C      : O(H = N)


class Solution {
public:
    int sum;

    void solve(TreeNode* root, int num) {
        if (root->left == NULL && root->right == NULL) {
            num = num*10 + root->val;
            sum += num;
            return;
        }

        num = num*10 + root->val;
        if (root->left != nullptr) {
            solve(root->left, num);   
        }

        if (root->right != nullptr) {
            solve(root->right, num);
        }
    }

    int sumNumbers(TreeNode* root) {
        if (root == nullptr) return 0;

        sum = 0;
        solve(root, 0);
        return sum;    
    }
};