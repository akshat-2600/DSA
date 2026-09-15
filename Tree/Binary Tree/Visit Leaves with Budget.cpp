/*  
    Company Tags       : ORACLE
    GeeksForGeeks Link : https://www.geeksforgeeks.org/problems/leaf-under-budget/1
*/

/********************************************* C++ ****************************************/

//Approach-1 : Using DFS
//T.C : O(n * log(n))
//S.C : O(n) 

class Solution {
  public:
    void getLeafCost(Node* node, int level, vector<int>& costs) {
        if (node == nullptr) {
            return;
        }
        
        if (node->left == nullptr && node->right == nullptr) {
            costs.push_back(level);
            return;
        }
        
        getLeafCost(node->left, level+1, costs);
        getLeafCost(node->right, level+1, costs);
    }
  
    int getCount(Node *root, int k) {
        if (root == nullptr) {
            return 0;
        }
        
        vector<int> costs;
        // Start DFS from the root at level 1
        getLeafCost(root, 1, costs);
        
        sort(costs.begin(), costs.end());
        
        int count = 0;
        for (int cost : costs) {
            if (k < cost) {
                break;
            }
            k -= cost;
            count++;
        }
        return count;
    }
};

//Approach-2 : Using BFS
//T.C : O(n * log(n))
//S.C : O(n)

class Solution {
  public:
    int getCount(Node *root, int k) {
        if (root == NULL) {
            return 0;
        }
        
        queue<pair<Node*, int>> q;
        vector<int> costs;
        
        q.push({root, 1});
        
        while (!q.empty()) {
            auto [node, level] = q.front();
            q.pop();
            
            if (node->left == nullptr && node->right == nullptr) {
                costs.push_back(level);
                continue;
            }
            
            if (node->left) {
                q.push({node->left, level+1});
            }
            if (node->right) {
                q.push({node->right, level+1});
            }
        }
        sort(costs.begin(), costs.end());
        
        int count = 0;
        
        for (int cost : costs) {
            if (k < cost) {
                break;
            }
            k -= cost;
            count++;
        }
        return count;
    }
};


