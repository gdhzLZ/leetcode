class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = 1, n = (int)nums.size();
        if (n == 0) return 0;
        vector<int> d(n + 1, 0);
        d[len] = nums[0];
        for (int i = 1; i < n; ++i) {
            if (nums[i] > d[len]) d[++len] = nums[i];
            else{
                int l = 1, r = len;
                while (l < r) {
                    int mid = (l + r) /2;
                    if (d[mid] < nums[i]) {
                        l = mid + 1;
                    }
                    else r = mid ;
                }
                d[l] = nums[i];
            }
        }
        return len;
    }
};