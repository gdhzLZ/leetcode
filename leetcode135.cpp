class Solution {
public:
    int candy(vector<int>& ratings) {
        int sum = 0;
        int pos = 0;
        int lastMin = -1;
        for(int i = 0 ; i < ratings.size() -1;i++){
            if(ratings[i] <= ratings[i+1]){
                int n = i-pos+1;
                sum += (n+1)*n/2;
                if(pos > 0 && ratings[pos-1] < ratings[pos] && lastMin >= n){
                    sum+=lastMin-n+1;
                }
                if(n > 1||pos == 0) lastMin = 1;
                else if(n==1){
                    if(ratings[pos] <= ratings[pos-1]) lastMin = 1;
                    else lastMin = lastMin +1;
                }
                pos = i+1;
            }
        }
        int n = ratings.size()-pos;
        sum+=(n+1)*n/2;
        if(pos > 0 && ratings[pos-1] < ratings[pos] && lastMin >= n){
            sum+=lastMin-n+1;
        }
        return sum;
    }
};