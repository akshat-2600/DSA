/*
    Company Tags           : MICROSOFT 
    GFG Link               : https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1
*/


/************************************************************ C++ ************************************************************/

// T.C : O(n log(n) + n)
// T.C : O(1)

class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        
        // Profit per weight jitna zyada hain vo better hain
        
        vector<pair<int, int>> vec(n);
        
        for (int i = 0; i < n; i++) {
            vec[i] = {val[i], wt[i]};
        }
        
        auto lambda = [](pair<int, int> p1, pair<int, int> p2) {
            return (1.0 * p1.first/p1.second) > (1.0 * p2.first/p2.second);
        };
        
        sort(vec.begin(), vec.end(), lambda); // O(nlogn)
        
        double result = 0.0 ;
        
        for (int i = 0; i < n; i++) {
            if (vec[i].second <= capacity) {
                result += vec[i].first; // profit
                capacity -= vec[i].second; // weight
                
            } else {
                result += (1.0 * vec[i].first/vec[i].second) * capacity;
                break;
            }
        }
        return result;
        
    }
};



/************************************************************ Java ************************************************************/

// T.C : O(n log(n) + n)
// T.C : O(1)

class Solution {
    
    class Item {
        
        int val;
        int wt;
        
        Item(int val, int wt) {
            this.val = val;
            this.wt  = wt;
        }
    }
    
    
    public double fractionalKnapsack(int[] val, int[] wt, int capacity) {
        
        int n = val.length;
        Item[] items = new Item[n];
        
        // Fill the items array
        for (int i = 0; i < n; i++) {
            items[i] = new Item(val[i], wt[i]);
        }
        
        // Sort
        Arrays.sort(items, new Comparator<Item>() {
            @Override
            public int compare(Item i1, Item i2) {
                double r1 = (double) i1.val / i1.wt;
                double r2 = (double) i2.val / i2.wt;
                
                if (r1 < r2) return 1;
                if (r1 > r2) return -1;
                return 0;
            }
        });
        
        double result = 0.0;
        
        // Calculate maximum total profit
        for (int i = 0; i < n; i++) {
            if (items[i].wt <= capacity) {
                result += items[i].val;
                capacity -= items[i].wt;
            } else {
                result += ((double) items[i].val / items[i].wt) * capacity;
                break;
            }
        }
        return result;
    }
}