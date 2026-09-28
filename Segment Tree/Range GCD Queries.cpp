/*
    Company Tags        :     
    GeekForGeeks Link   :   https://www.geeksforgeeks.org/problems/range-gcd-queries3654/1

*/


/******************************************************** C++ ********************************************************/

// Time Complexity : O((n + q) * log(n) * log(min(A)))
/**
 * A = max value in arr
 * Segment Tree Construction : O(n * log(min(A)))
 * Processing Queries        : O(q * log(n) * log(min(A)))
 */

 // Space Complexity : O(n + q)
 /**
  * Segment Tree    : O(n)
  * Recursion Stack : O(log(n))
  * Result Array    : O(q)
  */

class Solution {
  public:
    int gcd(int a, int b) {
        while (b != 0) {
            int c = a % b;
            a = b;
            b = c;
        }
        return a;
    }
    
    void buildSegmentTree(int i, int l, int r, vector<int>& segmentTree, vector<int> &arr) {
        
        if (l == r) {
            segmentTree[i] = arr[l];
            return;
        }
        
        int mid = l + (r - l) / 2;
        buildSegmentTree(2*i+1, l, mid, segmentTree, arr);
        buildSegmentTree(2*i+2, mid+1, r, segmentTree, arr);
        
        segmentTree[i] = gcd(segmentTree[2*i + 1], segmentTree[2*i + 2]);
    }
    
    int Query(int start, int end, int i, int l, int r, vector<int>& segmentTree) {
        // out of range
        if (r < start || l > end) {
            return 0;
        }
        
        if (l >= start && r <= end) {
            return segmentTree[i];
        }
        
        int mid = l + (r - l) / 2;
        
        int leftQuery  = Query(start, end, 2*i+1, l, mid, segmentTree);
        int rightQuery = Query(start, end, 2*i+2, mid+1, r, segmentTree);
        
        return gcd(leftQuery, rightQuery);
    }
    
    void Update(int idx, int value, int i, int l, int r, vector<int>& segmentTree) {
        if (l == r) {
            segmentTree[i] = value;
            return;
        }
        
        int mid = l + (r - l) / 2;
        
        if (idx <= mid) {
            Update(idx, value, 2*i+1, l, mid, segmentTree);
        } else {
            Update(idx, value, 2*i+2, mid+1, r, segmentTree);
        }
        
        segmentTree[i] = gcd(segmentTree[2*i+1], segmentTree[2*i+2]);
    }
  
    vector<int> processQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        
        if (n == 0) return {};
        
        vector<int> segmentTree(4*n, 0);
        
        buildSegmentTree(0, 0, n-1, segmentTree, arr);
        
        vector<int> result;
        
        for (const auto& q : queries) {
            int type  = q[0];
            int left  = q[1];  // index
            int right = q[2];  // value
            
            if (type == 0) {
                int output = Query(left, right, 0, 0, n-1, segmentTree);
                result.push_back(output);
            } else {
                int idx   = left;
                int value = right;
                arr[idx] = value;
                Update(idx, value, 0, 0, n-1, segmentTree);
            }
        }
        return result;
    }
};