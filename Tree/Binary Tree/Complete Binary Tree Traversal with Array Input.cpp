/*
    Company Tags         :   
    GeeksForGeeks Link   :  https://www.geeksforgeeks.org/problems/print-binary-tree-levels-in-sorted-order3241/1
*/

/**************************************************************** C++ ****************************************************************/

// Approach : Two Pointers 
// T.C      : O(N * log(N))
// S.C      : O(N)

class Solution {
  public:
    vector<vector<int>> levelSort(vector<int>& arr) {
        
        vector<vector<int>> res;
        
        int n = arr.size();
        
        int i = 0;
        int j = 0;
        int level = 0;
        
        while (i < arr.size()) {
            vector<int> temp;
            while (i <= j && i < arr.size()) {
                temp.push_back(arr[i]);
                i++;
            }
            sort(temp.begin(), temp.end());
            res.push_back(temp);
            level++;
            j = j + pow(2, level);
        }
        
        return res;
    }
};



/**************************************************************** JAVA ****************************************************************/

// Approach : Two Pointers 
// T.C      : O(N * log(N))
// S.C      : O(N)

class Solution {
    public ArrayList<ArrayList<Integer>> levelSort(int[] arr) {
        
        ArrayList<ArrayList<Integer>> res = new ArrayList<ArrayList<Integer>>();
        
        int n = arr.length;
        int i = 0;
        int j = 0;
        int level = 0;
        
        while (i < n) {
            ArrayList<Integer> temp = new ArrayList<>();
            
            // Gather elements belonging to the current level
            while (i <= j && i < n) {
                temp.add(arr[i]);
                i++;
            }
            
            // Sprt the current level
            Collections.sort(temp);
            res.add(temp);
            
            // Update the end index for the next level
            level++;
            j = j + (int) Math.pow(2, level);
        }
        
        return res;
        
    }
}

