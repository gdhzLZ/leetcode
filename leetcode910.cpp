class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
    	int len = A.size();
        sort(A.begin(),A.end());
        int ans = A[len-1] - A[0];
        for(int i=1;i<len;i++){
            int minv = min(A[0]+K,A[i]-K);
            int maxv = max(A[len-1]-K,A[i-1]+K);
            ans = min(ans,maxv - minv);
        }
        return ans;
    }
};

