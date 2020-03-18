class Solution {
public:
    bool isPossible(vector<int>& nums) {
        map<int,int> count;
        map<int,int> End;
        for(int i = 0 ; i < nums.size() ; i++){
            if(count.find(nums[i]) == count.end())
                count[nums[i]] = 1;
            else count[nums[i]]++;
        }
        for(int i = 0 ; i < nums.size() ; i++){
            if(count[nums[i]] != 0){
                int t1 = nums[i]+1;
                int t2 = nums[i]+2;
                if(End.find(nums[i]-1) != End.end() && End[nums[i]-1] > 0){
                        End[nums[i]-1]--;
                        if(End.find(nums[i]) != End.end())
                            End[nums[i]]++;
                        else End[nums[i]] = 1;
                        count[nums[i]]--;
                    }
                
                else{
                    if(count.find(t1) != count.end() && count[t1] > 0 && count.find(t2)!=count.end() && count[t2] > 0){
                    count[t1]--;
                    count[t2]--;
                    count[nums[i]]--;
                    if(End.find(t2) != End.end())
                        End[t2]++;
                    else End[t2] = 1;
                    }
                    else {
                        cout << i << endl;
                        return false;
                    }
                }
            }
        }
        return true;
    }
};