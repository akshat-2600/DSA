/** 
    Company Tags        : Accolite, Amazon, Flipkart, Knowlarity, MakeMyTrip, Ola Cabs, Open Solutions, OYO ROoms, Paytm, Qualcomm, Samsung,
                          Snapdeal, Twitter
    Leetcode Qn Link    : https://leetcode.com/problems/binary-tree-right-side-view/
*/


// Approach : DFS
// T.C      : O(n)
// S.C      : O(1)

class Solution {
public:
    void preOrder(TreeNode* root, int level, vector<int>& result) {
        if (root == NULL) {
            return;
        }

        if (result.size() < level) {
            result.push_back(root->val);
        }

        preOrder(root->right, level+1, result);
        preOrder(root->left, level+1, result);
    }

    vector<int> rightSideView(TreeNode* root) {
        if (root == NULL) {
            return {};
        }

        vector<int> result;
        preOrder(root, 1, result);

        return result;
    }
};

// Approach  : Level Order Traversal
// T.C       : O(n)
// S.C       : O(1)

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (root == NULL) {
            return {};
        }

        queue<TreeNode*> q;
        vector<int> result;

        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            TreeNode* node = NULL;

            while (n--) {
                node = q.front();
                q.pop();

                if (node->left != NULL) {
                    q.push(node->left);
                } 
                if (node->right != NULL) {
                    q.push(node->right);
                }
            }
            result.push_back(node->val);
        }
        return result;
    }
};



// ======================================================= JAVA ===================================================

// Approach  : Level Order Traversal
// T.C       : O(n)
// S.C       : O(1)

class Solution {
    public List<Integer> rightSideView(TreeNode root) {
        if (root == null) {
            return new ArrayList<>();
        }

        List<Integer> result = new ArrayList<>();
        Queue<TreeNode> q = new LinkedList<>();

        q.offer(root);
        while (!q.isEmpty()) {
            int n = q.size();
            TreeNode node = null;

            while (n != 0) {
                node = q.poll();

                if (node.left != null) {
                    q.offer(node.left);
                }

                if (node.right != null) {
                    q.offer(node.right);
                }
                n--;
            }
            result.add(node.val);
        }
        return result;
    }
}

// Approach : DFS
// T.C      : O(n)
// S.C      : O(1)

class Solution {
    public void preOrder(TreeNode root, int level, List<Integer> result) {
        if (root == null) {
            return;
        }

        if (result.size() < level) {
            result.add(root.val);
        }

        preOrder(root.right, level+1, result);
        preOrder(root.left, level+1, result);
    }

    public List<Integer> rightSideView(TreeNode root) {
        if (root == null) {
            return new ArrayList<>();
        }

        List<Integer> result = new ArrayList<>();

        preOrder(root, 1, result);

        return result;
    }
}