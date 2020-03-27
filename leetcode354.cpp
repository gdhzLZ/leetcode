class Solution {
public:
    static bool comp(vector<int> a,vector<int> b){
        if(a[0] != b[0])
            return a[0] < b[0];
        else return a[1] > b[1];
    }
   
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if(envelopes.size() == 0) return 0;
        sort(envelopes.begin(),envelopes.end(),comp);
        vector<int> d(envelopes.size()+1,0);
        int len = 1;
        d[1] = envelopes[0][1];
        for(int i = 1 ; i < envelopes.size() ; i++){
            int target = envelopes[i][1];
            if(target > d[len]){
                d[++len] = target;
            }
            else{
                int left = 1,right = len;
                while(left<right){
                    int mid = (left+right)/2;
                    if(d[mid] < target)left = mid+1;
                    else right = mid;
                }
                d[left] = target;
            }
        }
        return len;
    }
};