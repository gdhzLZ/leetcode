class Solution {
public:
    bool isTouch(vector<int> row){
        for(int i = 0 ; i< row.size() ; i=i+2){
            if(row[i]%2==0 && row[i+1] != row[i]+1)
                return false;
            else if(row[i] % 2 != 0 && row[i+1]+1 != row[i])
                return false;
        }
        return true;
    }
    bool isTouch(int a1,int a2){
        if(a1 % 2 == 0 && a2 == a1+1)
            return true;
        else if(a2 % 2 == 0 && a1 == a2+1)
            return true;
        else return false;
    }
    int minSwapsCouples(vector<int>& row)  {
        int ans = 0;
        while(1){
            if(isTouch(row))
                break;
            for(int i = 0 ;  i < row.size() ; i=i+2){
                if(!isTouch(row[i],row[i+1])){
                    vector<int>::iterator it;
                    if(row[i]%2==0){
                        it = find(row.begin(),row.end(),row[i]+1);

                    }
                    else {
                        it = find(row.begin(),row.end(),row[i]-1);
                    }
                    int t =distance(row.begin(),it);
                    int temp = row[i+1];
                    row[i+1] = row[t];
                    row[t]= temp;
                    ans++;
                    break;
                    
                }
            }
        }
        return ans;
    }
};