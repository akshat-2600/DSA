/*
    Company Tags       :   
    GeeksForGeeks Link :   https://www.geeksforgeeks.org/problems/possible-pairs1550/1

*/


/******************************************************** C++ ********************************************************/

// T.C : O(prod * log(min(a,b)))
// S.C : O(1)

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
  
    int pairCount(int x, int y) {
        if (y % x != 0) { // lcm must be a multiple of gcd
            return 0;
        }
            
        int count = 0;
        int prod = x * y;
        
        for (int i = 1; i <= y; i++) {
            int a = i;
            
            if (prod % a != 0) continue;
            
            int b = (x * y)/a;
            
            if (gcd(a, b) != x) {
                continue;
            }
            count++;
        }
        return count;
    }
};



// T.C : O(sqrt(x*y) * log(min(a, b)))
// S.C : O(1)

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
  
    int pairCount(int x, int y) {
        if (y % x != 0) { // lcm must be a multiple of gcd
            return 0;
        }
            
        int count = 0;
        int prod = x * y;
        
        for (int i = 1; i <= sqrt(prod); i++) {
            int a = i;
            
            if (prod % a != 0) continue;
            
            int b = prod/a;
            
            if (gcd(a, b) != x) {
                continue;
            }
            if (a == b) {
                count++;
            } else {
                count += 2;   
            }
        }
        return count;
    }
}

/******************************************************** JAVA ********************************************************/

//coming soon