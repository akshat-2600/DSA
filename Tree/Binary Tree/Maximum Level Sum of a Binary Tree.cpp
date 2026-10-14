/*
    Company Tags    :   
    LeetCode Link   :   https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/description/

*/


/******************************************************** C++ ********************************************************/


// Approach : BFS
// T.C      : O(n)
// S.C      : O(n)

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


// Approach : DFS
// T.C      : O(n)
// S.C      : O(n)

class Solution {
public:
    unordered_map<int, int> mp;  // level, sum

    void DFS(TreeNode* root, int level) {
        if (root == nullptr) {
            return;
        }

        if (root->left != nullptr) {
            DFS(root->left, level+1);
        }

        mp[level] += root->val;

        if (root->right != nullptr) {
            DFS(root->right, level+1);
        }
    }

    int maxLevelSum(TreeNode* root) {
        if (!root) return 1;

        DFS(root, 1);

        int maxWidth = INT_MIN;
        int level    = 1;

        for (auto [p, sum] : mp) {
            if (maxWidth < sum) {
                maxWidth = sum;
                level = p;
            }
        }
        return level;
    }
};