class Solution {
public:
    static bool comp(const vector<int> &a,const vector<int> &b){
        if(a[1] != b[1])
            return a[1] < b[1];
        else return a[0] > b[0];
    }
    int intersectionSizeTwo(vector<vector<int>>& intervals) {

        sort(intervals.begin(),intervals.end(),comp);
        int ans = 0;
        vector<int> visited(intervals.size(),2);
        for(int i = 0 ; i < intervals.size() ; i++){
            if(visited[i] <= 0) 
                continue;
            int a1,a2;
            ans += visited[i];
            if(visited[i] == 2){
                a1 = intervals[i][1];
                a2 = a1-1;
            }
            else{
                a1 = intervals[i][1];
                a2 = -100;
            }

            for(int j = i ; j < intervals.size() ; j++){
                if(a1<=intervals[j][1] && a1 >= intervals[j][0])
                    visited[j]--;
                if(a2<=intervals[j][1] && a2 >= intervals[j][0])
                    visited[j]--;
            }
        }
        return ans;
    }
}; 