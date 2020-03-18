class Solution {
public:
    static bool compare(vector<int> a,vector<int> b){
        return a[1] < b[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),compare);
        int ans = 0;
        if(points.size() == 0) return 0;
        vector last = points[0];
        for(int i = 1 ; i < points.size() ; i++){
            if(points[i][0] <= last[1]) {
                ans++;
            }
            else last = points[i];
        }
        return points.size()-ans;
    }
};