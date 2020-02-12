class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 0) return false;
        long long m = n;
        long long temp = (m & -m);
        if(temp == n) return true;
        else return false;
    }
};