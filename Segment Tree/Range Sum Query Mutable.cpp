/*
    Company Tags                :  
    Leetcode Link               :  https://leetcode.com/problems/range-sum-query-mutable/



/**************************************************************** C++ ****************************************************************/

//Approach-1 (Brute Force : TLE)
//T.C : Constructor: O(n), where n is length of nums array
//      Update : O(1), sumRange: O(n)
//S.C : O(n)

class NumArray {
public:
    vector<int> num;
    int n;

    NumArray(vector<int>& nums) {
        num = nums;
        n = nums.size();
    }
    
    void update(int index, int val) {
        num[index] = val;
    }
    
    int sumRange(int left, int right) {
        int sum = 0;
        for (int i=left; i <= right; i++) {
            sum += num[i];
        }
        return sum;
    }
};

// Approach-2 (Prefix sum array)
//T.C : Constructor: O(n), where n is length of nums array
//      Update : O(n), sumRange: O(1)
//S.C : O(n)

class NumArray {
public:
    vector<int> nums;
    vector<int> prefix;

    NumArray(vector<int>& arr) {
        nums = arr;
        int n = arr.size();

        prefix.resize(n);

        if (n == 0) return;
        prefix[0] = arr[0];

        for (int i=1; i < n; i++) {
            prefix[i] = prefix[i-1] + arr[i];
        }
    }
    
    void update(int index, int val) {
        int diff = val - nums[index];
        nums[index] = val;

        for (int i=index; i < prefix.size(); i++) {
            prefix[i] += diff;
        }
    }
    
    int sumRange(int left, int right) {
        if (left == 0) {
            return prefix[right];
        }

        return prefix[right] - prefix[left-1];
    }
};


//Approach-3 (Segment Tree)
//T.C : Constructor: O(n), where n is length of nums array
//      Update, sumRange: O(logN)
//S.C : O(n)

class NumArray {
public:
    int n;
    vector<int> segmentTree;

    void buildSegmentTree(int i, int l, int r, vector<int>& nums) {
        if (l == r) {
            segmentTree[i] = nums[l];
            return;
        }

        int mid = l + (r - l) / 2;
        buildSegmentTree(2*i+1, l, mid, nums);
        buildSegmentTree(2*i+2, mid+1, r, nums);

        segmentTree[i] = segmentTree[2*i+1] + segmentTree[2*i+2];
    }

    void updateSegmentTree(int idx, int val, int i, int l, int r) {
        if (l == r) {
            segmentTree[i] = val;
            return;
        }
        
        int mid = l + (r - l) / 2;
        if (idx <= mid) {
            updateSegmentTree(idx, val, 2*i+1, l, mid);
        } else {
            updateSegmentTree(idx, val, 2*i+2, mid+1, r);
        }

        segmentTree[i] = segmentTree[2*i+1] + segmentTree[2*i+2];
    }

    int querySegmentTree(int start, int end, int i, int l, int r) {
        if (l > end || r < start) {
            return 0;
        }

        if (l >= start && r <= end) {
            return segmentTree[i];
        }

        int mid = l + (r - l) / 2;

        return querySegmentTree(start, end, 2*i+1, l, mid) + querySegmentTree(start, end, 2*i+2, mid+1, r);
    }

    NumArray(vector<int>& nums) {
        n = nums.size();
        segmentTree.resize(4*n);
        buildSegmentTree(0, 0, n-1, nums);
    }
    
    void update(int index, int val) {
        updateSegmentTree(index, val, 0, 0, n-1);
    }
    
    int sumRange(int left, int right) {
        return querySegmentTree(left, right, 0, 0, n-1);
    }
};


/*********************************************************** JAVA **************************************************/

//Approach-1 (Brute Force : TLE)
//T.C : Constructor: O(n), where n is length of nums array
//      Update : O(1), sumRange: O(n)
//S.C : O(n)

class NumArray {

    private int[] nums;
    private int n;

    public NumArray(int[] nums) {
        this.nums = nums;
        n = nums.length;
    }
    
    public void update(int index, int val) {
        nums[index] = val;
    }
    
    public int sumRange(int left, int right) {
        int sum = 0;
        for (int i = left; i <= right; i++) {
            sum += nums[i];
        }

        return sum;
    }
}


// Approach-2 (Prefix sum array)
//T.C : Constructor: O(n), where n is length of nums array
//      Update : O(n), sumRange: O(1)
//S.C : O(n)

class NumArray {
    
    private int[] nums;
    private int[] prefix;

    public NumArray(int[] nums) {
        int n = nums.length;

        this.nums = new int[n];
        this.prefix = new int[n];

        for (int i=0; i < n; i++) {
            this.nums[i] = nums[i];
        }

        if (n == 0) return;

        prefix[0] = nums[0];

        for (int i=1; i < n; i++) {
            prefix[i] = prefix[i-1] + nums[i];
        }
        
    }
    
    public void update(int index, int val) {
        int diff = val - nums[index];
        nums[index] = val;

        for (int i=index; i < prefix.length; i++) {
            prefix[i] += diff;
        }
    }
    
    public int sumRange(int left, int right) {
        if (left == 0) {
            return prefix[right];
        }

        return prefix[right] - prefix[left-1];
    }
}


//Approach-3 (Segment Tree)
//T.C : Constructor: O(n), where n is length of nums array
//      Update, sumRange: O(logN)
//S.C : O(n)

class NumArray {

    private int n;
    private int[] segmentTree;

    private void buildSegmentTree(int i, int l, int r, int[] nums) {
        if (l == r) {
            segmentTree[i] = nums[l];
            return;
        }

        int mid = l + (r - l) / 2;
        buildSegmentTree(2*i+1, l, mid, nums);
        buildSegmentTree(2*i+2, mid+1, r, nums);

        segmentTree[i] = segmentTree[2*i+1] + segmentTree[2*i+2];
    }

    private void updateSegmentTree(int idx, int val, int i, int l, int r) {
        if (l == r) {
            segmentTree[i] = val;
            return;
        }

        int mid = l + (r - l) / 2;
        if (idx <= mid) {
            updateSegmentTree(idx, val, 2*i+1, l, mid);
        } else {
            updateSegmentTree(idx, val, 2*i+2, mid+1, r);
        }
        segmentTree[i] = segmentTree[2*i+1] + segmentTree[2*i+2];
    }

    private int querySegmentTree(int start, int end, int i, int l, int r) {
        if (l > end || r < start) {
            return 0;
        }

        if (l >= start && r <= end) {
            return segmentTree[i];
        }

        int mid = l + (r - l) / 2;

        return querySegmentTree(start, end, 2*i+1, l, mid) +
               querySegmentTree(start, end, 2*i+2, mid+1, r);
    }

    public NumArray(int[] nums) {
        n = nums.length;

        segmentTree = new int[4*n];
        buildSegmentTree(0, 0, n-1, nums);
    }
    
    public void update(int index, int val) {
        updateSegmentTree(index, val, 0, 0, n-1);
    }
    
    public int sumRange(int left, int right) {
        return querySegmentTree(left, right, 0, 0, n-1);
    }
}

