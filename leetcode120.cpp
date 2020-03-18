class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> now(triangle.size()+2,0x3f3f3f3f);
        if(triangle.size() == 0) return 0;
        now[1] = triangle[0][0];
        for(int i = 1 ; i < triangle.size() ; i++){
            for(int j = i+1 ; j >= 1 ; j--){
                now[j] = min(now[j],now[j-1])+triangle[i][j-1];
            }
        }
        int minn = now[0];
        for(int i =1 ; i <= triangle.size() ;i++)
            minn = min(minn,now[i]);
        return minn;
    }
};