/*
    Company Tags    :   
    LeetCode Link   :   https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

*/


/******************************************************** C++ ********************************************************/

// Approach : Using Hash map to store parent of each node and then applying BFS
// T.C : O(2*N)
// S.C : O(2*N)

class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parent;
    
    void addParent(TreeNode* root) {
        if (!root) {
            return;
        }

        if (root->left) {
            parent[root->left] = root;
        }
        addParent(root->left);

        if (root->right) {
            parent[root->right] = root;
        }
        addParent(root->right);
    }

    void collectKDistanceNodes(TreeNode* target, int k, vector<int>& result) {
        queue<TreeNode*> q;
        unordered_set<int> visited;

        q.push(target);
        visited.insert(target->val);
        
        while (!q.empty()) {
            int n = q.size();

            if (k == 0) {
                break;
            }

            while (n--) {
                TreeNode* curr = q.front();
                q.pop();

                if (curr->left && visited.find(curr->left->val) == visited.end()) {
                    q.push(curr->left);
                    visited.insert(curr->left->val);
                }

                if (curr->right && visited.find(curr->right->val) == visited.end()) {
                    q.push(curr->right);
                    visited.insert(curr->right->val);
                }

                if (parent.find(curr) != parent.end() && visited.find(parent[curr]->val) == visited.end()) {
                    q.push(parent[curr]);
                    visited.insert(parent[curr]->val);
                }
            }
            k--;
        }

        while (!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();
            result.push_back(temp->val);
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        vector<int> result;

        addParent(root);

        collectKDistanceNodes(target, k, result);

        return result;
    }
};