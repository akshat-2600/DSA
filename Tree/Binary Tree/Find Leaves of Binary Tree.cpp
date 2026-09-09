/*
    Company Tags    :   AMAZON , GOOGLE Onsite(2022)
    Leetcode Link   :   https://leetcode.com/problems/find-leaves-of-binary-tree/description/

*/


/******************************************************** C++ ********************************************************/

// Approach-1 : Uisng height of binary tree similar code and creating groups from bottom to to as all leaf nodes will have same group number
// T.C        : O(n * log10(n))
// S.C        : O(1)   

class Solution {
  public:
    map<int, vector<int>> mp;

    int collectNodeWithHeight(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int LH = collectNodeWithHeight(root->left);
        int RH = collectNodeWithHeight(root->right);
        int H  = 1 + max(LH, RH);

        return H;
    }

    vector<vector<int>> findLeaves(TreeNode* root) {
        mp.clear();
        collectNodeWithHeight(root);

        vector<vector<int>> result;
        
        map<int, vector<int>> ::iterator itr;
        for (itr = mp.begin(); itr != mp.end(); itr++) {
            result.push_back(itr.second);
        }

        return result;
    }

};



/******************************************************** JAVA ********************************************************/

//coming soon