/*
    Company Tags         :   
    GeeksForGeeks Link   :   https://www.geeksforgeeks.org/problems/construct-a-full-binary-tree--170648/1
*/

/**************************************************************** C++ ****************************************************************/

// Approach : Linear search
// O(n^2)
// O(n)  (recursion stack)


class Solution {
  public:
    Node* build(vector<int>& pre, vector<int>& preMirror, int& preIndex, int l, int h, int size) {
        
        if (preIndex >= size || l > h) {
            return nullptr;
        }
        
        Node* root = new Node(pre[preIndex]);
        preIndex++;
        
        // Leaf node
        if (l == h || preIndex >= size) {
            return root;
        }
        
        // Find next preorder element in mirror preorder
        int i;
        for (i = l; i <= h; i++) {
            if (pre[preIndex] == preMirror[i]) {
                break;
            }
        }
        
        if (i <= h) {
            root->left = build(pre, preMirror, preIndex, i, h, size);
            root->right = build(pre, preMirror, preIndex, l + 1, i - 1, size);
        }
        
        return root;
    }
  
    Node *constructBinaryTree(vector<int> &pre, vector<int> &preMirror) {
        
        int preIndex = 0;
        int n = pre.size();
        
        return build(pre, preMirror, preIndex, 0, n - 1, n);
    }
};


// Approach : HashMap
// T.C      : O(n)
// S.C      : O(n) 

class Solution {
  public:
    unordered_map<int, int> pos;
    
    Node* build(vector<int>& pre, vector<int>& preMirror, int& preIndex, int l, int h) {
        
        if (preIndex >= pre.size() || l > h) {
            return nullptr;
        }
        
        Node* root = new Node(pre[preIndex++]);
        
        if (l == h || preIndex >= pre.size()) {
            return root;
        }
        
        int idx = pos[pre[preIndex]];
        
        root->left = build(pre, preMirror, preIndex, idx, h);
        root->right = build(pre, preMirror, preIndex, l + 1, idx - 1);
        
        return root;
    }
  
    Node *constructBinaryTree(vector<int> &pre, vector<int> &preMirror) {
        
        int n = preMirror.size();
        
        for (int i = 0; i < n; i++) {
            pos[preMirror[i]] = i;
        }
        int preIndex = 0;
        
        return build(pre, preMirror, preIndex, 0, n - 1);
        
    }
};

/**************************************************************** JAVA ****************************************************************/

// Approach : Linear search
// T.C      : O(n^2)
// S.C      : O(n)  (recursion stack)

class Solution {
    
    int preIndex;
    
    private Node build(int[] pre, int[] preMirror, int l, int h) {
        
        if (preIndex >= pre.length || l > h) {
            return null;
        }
        
        Node root = new Node(pre[preIndex++]);
        
        // Leaf Node
        if (l == h || preIndex >= pre.length) {
            return root;
        }
        
        // Find the next preorder element in mirrro preorder
        int idx = -1;
        for (int i = l; i <= h; i++) {
            if (preMirror[i] == pre[preIndex]) {
                idx = i;
                break;
            }
        }
        
        if (idx != -1) {
            root.left = build(pre, preMirror, idx, h);
            root.right = build(pre, preMirror, l + 1, idx - 1);
        }
        
        return root;
    }
    
    public Node constructBinaryTree(int[] pre, int[] preMirror) {
        
        preIndex = 0;
        
        return build(pre, preMirror, 0, pre.length - 1);
    }
}


// Approach : HashMap
// T.C      : O(n)
// S.C      : O(n) 

class Solution {
    int preIndex = 0;
    HashMap<Integer, Integer> map = new HashMap<>();
    
    private Node build(int[] pre, int[] preMirror, int l, int h) {
        if (preIndex >= pre.length || l > h) {
            return null;
        }
        
        Node root = new Node(pre[preIndex++]);
        
        // Leaf node
        if (l == h || preIndex >= pre.length) {
            return root;
        }
        
        int idx = map.get(pre[preIndex]);
        
        root.left = build(pre, preMirror, idx, h);
        root.right = build(pre, preMirror, l + 1, idx - 1);
        
        return root;
    }
    
    public Node constructBinaryTree(int[] pre, int[] preMirror) {
        
        preIndex = 0;
        map.clear();
        
        for (int i = 0; i < preMirror.length; i++) {
            map.put(preMirror[i], i);
        }
        
        return build(pre, preMirror, 0, pre.length - 1);
    }
}