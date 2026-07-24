/*
    Company Tags                :  
    GeeksForGeeks Link          :  https://www.geeksforgeeks.org/problems/longest-consecutive-sequence-in-binary-tree/1



/**************************************************************** C++ ****************************************************************/


// Approach 1 : Using DFS try to start from every node and calculating length
// T.C      : O(n^2)
// S.C      : O(1)

class Solution {
  public:
  
    int ans = 0;
  
    int solve(Node* root) {
        if (root == NULL) {
            return 0;
        }
        
        int left = 0;
        int right = 0;
        
        if (root->left != NULL && root->left->data == root->data + 1) {
            left = 1 + solve(root->left);
        }
        
        if (root->right != NULL && root->right->data == root->data + 1) {
            right = 1 + solve(root->right);
        } 
        
        if (left == 0 && right == 0) {
            return 1;
        }
        
        return max(left, right);
    }
  
  
    void dfs(Node* root) {
        if (root == NULL) {
            return;
        }
        
        ans = max(ans, solve(root));
        
        dfs(root->left);
        dfs(root->right);
    }
  
    int longestConsecutive(Node* root) {
        ans = 0;
        dfs(root);
        
        return (ans == 1) ? -1 : ans;
    }
};

// Approach 2 : Traverse the tree once while carrying the previous value and current consecutive length
// T.C      : O(n)
// S.C      : O(1)


class Solution {
  public:
    int ans = 0;
    
    void dfs(Node* root, int prev, int len) {
        if (root == NULL) {
            return;
        }
        
        if (root->data == prev + 1) {
            len++;
        } else {
            len = 1;
        }
        
        ans = max(ans, len);
        
        dfs(root->left, root->data, len);
        dfs(root->right, root->data, len);
    }
  
    int longestConsecutive(Node* root) {
        
        if (root == NULL) {
            return -1;
        }
        
        dfs(root, root->data-1, 0);
        
        return ans == 1 ? -1 : ans;
        
    }
};

/**************************************************************** JAVA ****************************************************************/

// Approach 1 : Using DFS try to start from every node and calculating length
// T.C      : O(n^2)
// S.C      : O(1)


class Solution {
        
    int ans;
    
    int solve(Node root) {
        
        if (root == null) {
            return 0;
        }
        
        int left = 0;
        int right = 0;
        
        if (root.left != null && root.left.data == root.data + 1) {
            left = 1 + solve(root.left);
        }
        
        if (root.right != null && root.right.data == root.data + 1) {
            right = 1 + solve(root.right);
        }
        
        if (left == 0 && right == 0) {
            return 1;
        }
        
        return Math.max(left, right);
    }
    
    void dfs(Node root) {
        if (root == null) {
            return;
        }
        
        ans = Math.max(ans, solve(root));
        
        dfs(root.left);
        dfs(root.right);
    }
    
    public int longestConsecutive(Node root) {
        ans = 0;
        
        dfs(root);
        
        return ans == 1 ? -1 : ans;
    }
}

// Approach 2 : Traverse the tree once while carrying the previous value and current consecutive length
// T.C      : O(n)
// S.C      : O(1)


class Solution {
    
    int ans = 0;
    
    void dfs(Node root, int prev, int len) {
        if (root == null) {
            return;
        }
        
        if (root.data == prev + 1)  {
            len++;
        } else {
            len = 1;
        }
        
        ans = Math.max(ans, len);
        
        dfs(root.left, root.data, len);
        dfs(root.right, root.data, len);
    }
    
    public int longestConsecutive(Node root) {
        
        if (root == null) {
            return -1;
        }
        
        dfs(root, root.data - 1, 0);
        
        return ans == 1 ? -1 : ans;
        
        
    }
}