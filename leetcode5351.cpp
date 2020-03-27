class Solution {
public:
    
    int MaxResult(vector<int> slices,int n){
        if(n == 1)
            return max(slices[0],slices[1]);
        vector<int> dp = slices;
        int ans = 0;
        for(int i = 1 ; i < n ; i++){
           vector<int>MaxPre(dp.size(),0);
           int Max = 0;
           for(int j = 2; j < MaxPre.size() ; j++){
               Max = max(dp[j-2],Max);
               MaxPre[j] = Max;
           }
           for(int j = 0 ; j < dp.size() ; j++){
               dp[j]=slices[j]+MaxPre[j];
               ans = max(ans,dp[j]);
           }
        }
        return ans;
    }
    int maxSizeSlices(vector<int>& slices) {
        if(slices.size() == 0) return 0;
        int n = slices.size()/3;
        int t = slices.back();
        slices.pop_back();
        int ans1 = MaxResult(slices,n);
        slices.push_back(t);
        slices.erase(slices.begin());
        int ans2 = MaxResult(slices,n);
        return max(ans1,ans2);
    }
};