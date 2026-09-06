/*  
    Company Tags  : Accolite, Amazon, American Express, Expedia, MakeMyTrip, Microsoft, Payu, Snapdeal, Times Internet, Twitter
    Link to Qn    : https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
*/


/****************************************************** C++ ***************************************************/

//Approach - DFS and find p and q
//T.C : O(n)
//S.C : O(n) (recursion call stack)


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) {
            return NULL;
        }
        
        if (root == p || root == q) {
            return root;
        }

        TreeNode* leftNode  = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightNode = lowestCommonAncestor(root->right, p, q);

        if (leftNode != NULL && rightNode != NULL) {
            return root;
        } 

        if (leftNode != NULL) {
            return leftNode;
        }
        return rightNode;
    }
};


/****************************************************** JAVA ***************************************************/


class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if (root == null) {
            return null;
        } 

        if (root == p || root == q) {
            return root;
        }

        TreeNode leftNode  = lowestCommonAncestor(root.left, p, q);
        TreeNode rightNode = lowestCommonAncestor(root.right, p, q);

        if (leftNode != null && rightNode != null) {
            return root;
        }

        if (leftNode != null) {
            return leftNode;
        }

        return rightNode;
    }
}