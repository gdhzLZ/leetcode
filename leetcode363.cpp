
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int ans = INT_MIN;
        for(int left = 0 ; left < matrix[0].size() ; left++){
            vector<int> dp(matrix.size(),0);
            for(int right = left; right < matrix[0].size() ; right++){
                for(int row = 0 ; row < matrix.size() ;row++)
                    dp[row]+=matrix[row][right];
                set<int> SUM;
                SUM.insert(0);//如果不通过减别的矩阵，直接从第0行当当前位置的和<=k,
                //插入0就可以解决
                int sum = 0;
                for(int row = 0 ; row < matrix.size() ; row++){
                    sum+=dp[row];
                    set<int>::iterator it = SUM.lower_bound(sum-k);
                    if(it != SUM.end())
                        ans = max(ans,sum-*it);
                    SUM.insert(sum);
                }

            }
        }
        return ans;
    }
};