/*
    Company Tags                : 
    Leetcode Link               : https://www.geeksforgeeks.org/problems/range-minimum-query/1
*/


/**************************************************************** C++ ****************************************************************/

//T.C : O(q*log(n))
//S.C : O(4*n)

/* The functions which
builds the segment tree */

void buildSegmentTree(int i, int l, int r, int segmentTree[], int arr[]) {
    
    // Base case
    if (l == r) {
        segmentTree[i] = arr[l];
        return;
    }
    
    int mid = l + (r - l)/2;
    buildSegmentTree(2*i + 1, l, mid, segmentTree, arr);
    buildSegmentTree(2*i + 2, mid+1, r, segmentTree, arr);
    
    segmentTree[i] = min(segmentTree[2*i + 1],segmentTree[2*i + 2]);
}

int query(int start, int end, int i, int l, int r, int segmentTree[]) {
    if (l > end || r < start) {
        return INT_MAX;
    } 
    
    if (l >= start && r <= end) {
        return segmentTree[i];
    }
    
    int mid = l + (r - l)/2;
    
    return min(query(start, end, 2*i + 1, l, mid, segmentTree), 
               query(start, end, 2*i + 2, mid+1, r, segmentTree));
}

int *constructST(int arr[], int n) {
    
    int *segmentTree = new int[4 * n];
    buildSegmentTree(0, 0, n-1, segmentTree, arr);
    
    return segmentTree;
    
}

/* The functions returns the
 min element in the range
 from a and b */
int RMQ(int st[], int n, int a, int b) {
    
    return query(a, b, 0, 0, n-1, st);
    
}

/**************************************************************** JAVA ****************************************************************/

//T.C : O(q*log(n))
//S.C : O(4*n)

/* The functions which
builds the segment tree */
class GfG {
    static int st[];
    
    public static void buildSegmentTree(int i, int l, int r, int arr[]) {
        if (l == r) {
            st[i] = arr[l];
            return;
        }
        
        int mid = l + (r - l)/2;
        
        buildSegmentTree(2*i + 1, l, mid, arr);
        buildSegmentTree(2*i + 2, mid+1, r, arr);
        
        st[i] = Math.min(st[2*i + 1], st[2*i + 2]);
    }
    
    public static int query(int start, int end, int i, int l, int r) {
        if (l > end || r < start) {
            return Integer.MAX_VALUE;
        }
        
        if (l >= start && r <= end) {
            return st[i];
        }
        
        int mid = l + (r - l) / 2;
        
        return Math.min(query(start, end, 2*i + 1, l, mid),
                        query(start, end, 2*i + 2, mid+1, r));
    }

    public static int[] constructST(int arr[], int n) {
        int height = (int)Math.ceil(Math.log(n) / Math.log(2));
        int size   = 2 * (int) Math.pow(2, height) - 1;
        st = new int[size];
        
        buildSegmentTree(0, 0, n-1, arr);
        
        return st;
    }

    /* The functions returns the
      min element in the range
      from l and r */
    public static int RMQ(int st[], int n, int l, int r) {
        
        return query(l, r, 0, 0, n-1);
    }
}