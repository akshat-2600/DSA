/*
    Company Tags             :  Morgan Stanley , Microsoft , Adobe
    GeekForGeeks Link        :  https://www.geeksforgeeks.org/problems/preorder-traversal-and-bst4006/1



/**************************************************************** C++ ****************************************************************/

// T.C : O(N)
// S.C : O(N)

class Solution {
public:
    bool canRepresentBST(vector<int> &arr) {
        stack<int> st;
        int lowerBound = INT_MIN;

        for (int x : arr) {

            // Invalid if current value violates BST property
            if (x < lowerBound)
                return false;

            // Move up to find the correct parent
            while (!st.empty() && x > st.top()) {
                lowerBound = st.top();
                st.pop();
            }

            st.push(x);
        }

        return true;
    }
};


/**************************************************************** JAVA ****************************************************************/

// T.C : O(N)
// S.C : O(N)

class Solution {
    public boolean canRepresentBST(List<Integer> arr) {
     
        Stack<Integer> st = new Stack<>();
        int lowerBound = Integer.MIN_VALUE;
        
        for (int x: arr) {
            
            if (x < lowerBound) {
                return false;
            }
            
            while (!st.isEmpty() && x > st.peek()) {
                lowerBound = st.peek();
                st.pop();
            }
            st.push(x);
        }
        return true;
    }
}
