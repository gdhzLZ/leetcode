class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        if(A.size() == 0)
            return 0;
        for(int i = 0 ; i < A.size() ; i++){
            if(A[i][0] == 1){
                for(int j = 0 ; j < A[0].size() ; j++){
                    if(A[i][j] == 0)
                        A[i][j] = 1;
                    else A[i][j] = 0;
                }
            }

        }
        int ans = 0;
        for(int i = 0 ; i < A[0].size() ; i++){
            int num = 0;
            for(int j = 0 ; j < A.size() ; j++){
                if(A[j][i] == 1)
                    num++;
            }
            int temp = A.size()-num;
            ans+=max(temp,num)*pow(2,A[0].size()-1-i);
        }
        return ans;
        
    }
};