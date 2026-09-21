/*
    Company Tags         :
    GeeksForGeeks Link   : https://leetcode.com/problems/reverse-degree-of-a-string/
*/

/************************************************************** C++ **************************************************************/

// Approach : BFS + sorting each level
// T.C      : O((V+E)*log(V+E))
// S.C      : O(V+E)

class Solution {
  public:
    bool areAnagrams(Node* root1, Node* root2) {
        
        if (root1 == nullptr || root2 == nullptr) {
            return root1 == root2;
        }
        
        queue<Node*> q1;
        queue<Node*> q2;
        
        q1.push(root1);
        q2.push(root2);
        
        while (!q1.empty() && !q2.empty()) {
            int n1 = q1.size();
            int n2 = q2.size();
            
            if (n1 != n2) {
                return false;
            }
            
            vector<int> level1;
            vector<int> level2;
            
            for (int i = 0; i < n1; i++) {
                Node* node1 = q1.front();
                Node* node2 = q2.front();
                q1.pop();
                q2.pop();
                
                level1.push_back(node1->data);
                level2.push_back(node2->data);
                
                if (node1->left != nullptr) {
                    q1.push(node1->left);
                }
                
                if (node1->right != nullptr) {
                    q1.push(node1->right);
                }
                
                if (node2->left != nullptr) {
                    q2.push(node2->left);
                }
                
                if (node2->right != nullptr) {
                    q2.push(node2->right);
                }
            }
            sort(level1.begin(), level1.end());
            sort(level2.begin(), level2.end());
            
            if (level1 != level2) {
                return false;
            }
        }
        return q1.empty() && q2.empty();
    }
};


// Approach : BFS + frequency map
// T.C      : O(V+E)
// S.C      : O(V+E)

class Solution {
  public:
    bool areAnagrams(Node* root1, Node* root2) {
        
        if (root1 == nullptr || root2 == nullptr) {
            return root1 == root2;
        }
        
        queue<Node*> q1;
        queue<Node*> q2;
        
        q1.push(root1);
        q2.push(root2);
        
        while (!q1.empty() && !q2.empty()) {
            int n1 = q1.size();
            int n2 = q2.size();
            
            if (n1 != n2) {
                return false;
            }
            
            unordered_map<int, int> freq;
            
            for (int i = 0; i < n1; i++) {
                Node* node1 = q1.front();
                Node* node2 = q2.front();
                q1.pop();
                q2.pop();
                
                // Increase frequency for values from the first tree
                // and decrease it for values from the second tree.
                freq[node1->data]++;
                freq[node2->data]--;
                
                if (node1->left != nullptr) {
                    q1.push(node1->left);
                }
                
                if (node1->right != nullptr) {
                    q1.push(node1->right);
                }
                
                if (node2->left != nullptr) {
                    q2.push(node2->left);
                }
                
                if (node2->right != nullptr) {
                    q2.push(node2->right);
                }
            }
            
            for (const auto &entry : freq) {
                if (entry.second != 0) {
                    return false;
                }
            }
        }
        return q1.empty() && q2.empty();
    }
};
