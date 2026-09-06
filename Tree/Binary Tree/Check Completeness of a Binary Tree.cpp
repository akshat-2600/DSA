/*
    Company Tags                 : Amazon, Meta
    Leetcode Link                : https://leetcode.com/problems/check-completeness-of-a-binary-tree/
*/


/****************************************************** C++ ***************************************************/

// Approach : BFS
// T.C      : O(n)
// S.C      : O(n)


class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool past = false; // have i seen null node in the past ? 

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node == NULL) {
                past = true;
            } else {
                if (past == true) {
                    return false;
                }
                q.push(node->left);
                q.push(node->right);
            }
        }
        return true;
    }
};

// Approach : DFS
// T.C      : O(n)
// S.C      : O(n) (call stack recursion)


class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    bool dfs(TreeNode* root, int idx, int totalNodes) {
        if (root == NULL) {
            return true;
        }

        if (idx > totalNodes) {
            return false;
        }

        return dfs(root->left, 2*idx, totalNodes) && dfs(root->right, 2*idx + 1, totalNodes);
    }

    bool isCompleteTree(TreeNode* root) {
        int totalNodes = countNodes(root);

        int idx = 1;

        return dfs(root, idx, totalNodes);
    }
};


/****************************************************** JAVA ***************************************************/

// Approach : BFS
// T.C      : O(n)
// S.C      : O(n)


class Solution {
    public boolean isCompleteTree(TreeNode root) {
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);
        boolean past = false; // have i seen null node in the past ?

        while (!q.isEmpty()) {
            TreeNode node = q.poll();

            if (node == null){
                past = true;
            } else {
                if (past == true) {
                    return false;
                } else {
                    q.offer(node.left);
                    q.offer(node.right);
                }
            }
        }
        return true;
    }
}


// Approach : DFS
// T.C      : O(n)
// S.C      : O(n) (call stack recursion)


class Solution {
    public int countNodes(TreeNode root) {
        if (root == null) {
            return 0;
        }

        return 1 + countNodes(root.left) + countNodes(root.right);
    }

    public boolean dfs(TreeNode root, int idx, int totalNodes) {
        if (root == null) {
            return true;
        }

        if (idx > totalNodes) {
            return false;
        }

        return dfs(root.left, 2*idx, totalNodes) && dfs(root.right, 2*idx+1, totalNodes);
    }

    public boolean isCompleteTree(TreeNode root) {
        int totalNodes = countNodes(root);

        int idx = 1;

        return dfs(root, idx, totalNodes);
    }
}