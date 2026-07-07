/*
    Company Tags                : AMAZON
    Leetcode Link               : https://www.geeksforgeeks.org/problems/sum-of-query-ii5310/1
*/


/**************************************************************** C++ ****************************************************************/

//T.C : O(q*log(n))
//S.C : O(4*n)

class Solution {
  public:
    // Function to build segment tree
    void buildSegmentTree(int i, int l, int r, vector<int>& segmentTree, int arr[]) {
        //Base case
        if (l == r) {
            segmentTree[i] = arr[l];
            return;
        }
        
        int mid = l + (r - l)/2;
        buildSegmentTree(2*i + 1, l, mid, segmentTree, arr);
        buildSegmentTree(2*i + 2, mid+1, r, segmentTree, arr);
        
        segmentTree[i] = segmentTree[2*i + 1] + segmentTree[2*i + 2];
    }
    
    int Query(int start, int end, int i, int l, int r, vector<int>& segmentTree) {
        // out of range
        if (l > end || r < start) {
            return 0;
        }
        
        if (l >= start && r <= end) {
            return segmentTree[i];
        }
        
        int mid = l + (r - l)/2;
        
        return Query(start, end, 2*i + 1, l, mid, segmentTree) +
               Query(start, end, 2*i + 2, mid+1, r, segmentTree);
        
    }
  
  
    vector<int> querySum(int n, int arr[], int q, int queries[]) {
        
        // Initializing segment tree
        vector<int> segmentTree(4*n);
        
        // Building segment tree
        buildSegmentTree(0, 0, n-1, segmentTree, arr);
        
        // Initializing result
        vector<int> result;
        
        for (int i=0; i < 2*q; i += 2) {
            int start = queries[i] - 1;
            int end   = queries[i+1] - 1;
            
            result.push_back(Query(start, end, 0, 0, n-1, segmentTree));
        }
        
        return result;
        
    }
};

/**************************************************************** JAVA ****************************************************************/

//T.C : O(q*log(n))
//S.C : O(4*n)

class Solution {
    
    void buildSegmentTree(int i, int l, int r, int[] segmentTree, int[] arr) {
        // Base case
        if (l == r) {
            segmentTree[i] = arr[l];
            return;
        }
        
        int mid = l + (r - l)/2;
        
        buildSegmentTree(2*i + 1, l, mid, segmentTree, arr);
        buildSegmentTree(2*i + 2, mid+1, r, segmentTree, arr);
        
        segmentTree[i] = segmentTree[2*i + 1] + segmentTree[2*i + 2];
    }
    
    
    int Query(int start, int end, int i, int l, int r, int[] segmentTree) {
        if (l > end || r < start) {
            return 0;
        }
        
        if (l >= start && r <= end) {
            return segmentTree[i];
        }
        
        int mid = l + (r - l)/2;
        
        return Query(start, end, 2*i + 1, l, mid, segmentTree) +
               Query(start, end, 2*i + 2, mid+1, r, segmentTree);
    }
    
    
    List<Integer> querySum(int n, int arr[], int q, int queries[]) {
        
        int[] segmentTree = new int[4 * n];
        
        buildSegmentTree(0, 0, n-1, segmentTree, arr);
        
        List<Integer> result = new ArrayList<Integer>();
        
        for (int i=0; i < 2*q; i += 2) {
            int start = queries[i] - 1;
            int end   = queries[i+1] - 1;
            
            result.add(Query(start, end, 0, 0, n-1, segmentTree));
        }
        
        return result;
        
    }
}