/*
    Company Tags    :   
    LeetCode Link   :   https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/description/

*/


/******************************************************** C++ ********************************************************/

// T.C   : O(n)
// S.C   : O(n)

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if (root == nullptr) {
            return 1;
        }

        queue<TreeNode*> q;
        q.push(root);
        int level = 1;
        int maxSum = INT_MIN;
        int ans = level;

        while (!q.empty()) {
            int n = q.size();

            int sum = 0;
            while (n--) {
                auto node = q.front();
                q.pop();

                sum += node->val;
                if (node->left != nullptr) {
                    q.push(node->left);
                }

                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
            if (maxSum < sum) {
                maxSum = sum;
                ans = level;
            }
            level++;
        }
        return ans;
    }
};

