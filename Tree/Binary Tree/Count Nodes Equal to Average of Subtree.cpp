/*
    Company Tags    :   
    Leetcode Link   :   https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/description/

*/


/******************************************************** C++ ********************************************************/

// Approach-1 : preOrder and for every node calculating sum and count of nodes separately
// T.C        : O(n^2)
// S.C        : O(N)  (call stack)  


class Solution {
public:
    int ans = 0;

    int total(TreeNode* node) {
        if (node == NULL) {
            return 0;
        }

        return node->val + total(node->left) + total(node->right);
    }

    int countNodes(TreeNode* node) {
        if (node == NULL) {
            return 0;
        }

        return 1 + countNodes(node->left) + countNodes(node->right);
    }

    void preOrder(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        
        int sum   = total(root);
        int count = countNodes(root);

        int avg = sum / count;
        if (avg == root->val) {
            ans++;
        }
        preOrder(root->left);
        preOrder(root->right);
    }

    int averageOfSubtree(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        preOrder(root);
        return ans;
    }
};


// Approach-2 : preOrder and for every node calculating sum and count of nodes together
// T.C        : O(n^2)
// S.C        : O(N)  (call stack) 

class Solution {
public:
    int ans = 0;

    int total(TreeNode* node, int &count) {
        if (node == NULL) {
            return 0;
        }
        count++;
        return node->val + total(node->left, count) + total(node->right, count);
    }

    void preOrder(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        
        int count = 0;
        int sum   = total(root, count);

        int avg = sum / count;
        if (avg == root->val) {
            ans++;
        }
        preOrder(root->left);
        preOrder(root->right);
    }

    int averageOfSubtree(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        preOrder(root);
        return ans;
    }
};

// Approach-3 : Optimized Post Order
// T.C        : O(n)
// S.C        : O(N)  (call stack)  

class Solution {
public:
    int ans = 0;

    pair<int, int> solve(TreeNode* root) {  // {sum, count}
        if (root == nullptr) {
            return {0, 0};
        }

        auto p1 = solve(root->left);
        auto p2 = solve(root->right);

        int totalSum = p1.first + p2.first + root->val;
        int count    = p1.second + p2.second + 1;

        int avg      = totalSum / count;
        if (avg == root->val) {
            ans++;
        }
        return {totalSum, count};
    }

    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return ans;
    }
};

/******************************************************** JAVA ********************************************************/


// Approach-1 : preOrder and for every node calculating sum and count of nodes separately
// T.C        : O(n^2)
// S.C        : O(N)  (call stack)


class Solution {
    int ans = 0;

    int total(TreeNode node) {
        if (node == null) {
            return 0;
        }

        return node.val + total(node.left) + total(node.right);
    }

    int countNodes(TreeNode node) {
        if (node == null) {
            return 0;
        }

        return 1 + countNodes(node.left) + countNodes(node.right);
    }

    void preOrder(TreeNode root) {
        if (root == null) {
            return;
        }

        int sum   = total(root);
        int count = countNodes(root);

        int avg = sum / count;
        if (avg == root.val ) {
            ans++;
        }
        preOrder(root.left);
        preOrder(root.right);
    }

    public int averageOfSubtree(TreeNode root) {
        if (root == null) {
            return 0;
        }
        
        preOrder(root);
        return ans;
    }
}


// Approach-2 : preOrder and for every node calculating sum and count of nodes together
// T.C        : O(n^2)
// S.C        : O(N)  (call stack) 


class Solution {
    int ans = 0;

    int total(TreeNode node, int[] count) {
        if (node == null) {
            return 0;
        }
        count[0]++;
        return node.val + total(node.left, count) + total(node.right, count);
    }

    void preOrder(TreeNode root) {
        if (root == null) {
            return;
        }

        int[] count = new int[]{0};
        int sum   = total(root, count);

        int avg = sum / count[0];
        if (avg == root.val ) {
            ans++;
        }
        preOrder(root.left);
        preOrder(root.right);
    }

    public int averageOfSubtree(TreeNode root) {
        if (root == null) {
            return 0;
        }
        
        preOrder(root);
        return ans;
    }
}

// Approach-3 : Optimized Post Order
// T.C        : O(n)
// S.C        : O(N)  (call stack) 


class Solution {
    int ans = 0;

    public int[] solve(TreeNode root) {
        if (root == null) {
            return new int[]{0, 0};
        }

        int[] p1 = solve(root.left);
        int[] p2 = solve(root.right);

        int totalSum   = p1[0] + p2[0] + root.val;
        int count      = p1[1] + p2[1] + 1;

        int avg   = totalSum / count;
        if (avg == root.val) {
            ans++;
        }
        return new int[]{totalSum, count};
    }

    public int averageOfSubtree(TreeNode root) {
        
        solve(root);
        return ans;
    }
}