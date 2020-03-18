class Solution {
public:
    static bool compare(vector<int> a,vector<int> b){
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),compare);
        for(int i = 0 ;  i < intervals.size() ; i++)
            cout << intervals[i][0] << " " << intervals[i][1] << endl;
        int ans = 0;
        if(intervals.size() == 0) return 0;
        vector last = intervals[0];
        for(int i = 1 ; i < intervals.size() ; i++){
            if(intervals[i][0] < last[1]) {
                ans++;
            }
            else last = intervals[i];
        }
        return ans;
    }
};